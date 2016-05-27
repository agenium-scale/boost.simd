//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CORRECT_FMA_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CORRECT_FMA_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
//#include <boost/simd/sdk/meta/is_upgradable.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/group.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/function/simd/split.hpp>
#include <boost/simd/function/simd/two_add.hpp>
#include <boost/simd/function/simd/two_prod.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/detail/dispatch/meta/upgrade.hpp>
#include <tuple>

#ifndef BOOST_SIMD_DONT_CARE_FMA_OVERFLOW
#include <boost/simd/function/simd/exponent.hpp>
#include <boost/simd/function/simd/ldexp.hpp>
#include <boost/simd/function/simd/maxmag.hpp>
#include <boost/simd/function/simd/minmag.hpp>
#include <boost/simd/function/simd/shift_right.hpp>
#include <boost/simd/function/simd/unary_minus.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
  // TODO wait for split
//    BOOST_DISPATCH_OVERLOAD(correct_fma_
//                              , (typename A0, typename X)
//                              , bd::cpu_
//                              , bs::pack_<bd::single_<A0>, X>
//                              , bs::pack_<bd::single_<A0>, X>
//                              , bs::pack_<bd::single_<A0>, X>
//                              )
//    {
//       BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1, const A0& a2) const BOOST_NOEXCEPT
//       {
//         using ivtype = bd::upgrade_t<A0>;
//         ivtype a0l, a0h, a1l, a1h, a2l, a2h;
//         split(a0, a0l, a0h);
//         split(a1, a1l, a1h);
//         split(a2, a2l, a2h);
//         return group(a0l*a1l+a2l, a0h*a1h+a2h);
//       }
//    };

   BOOST_DISPATCH_OVERLOAD(correct_fma_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          , bs::pack_<bd::floating_<A0>, X>
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1, const A0& a2) const BOOST_NOEXCEPT
      {
        A0 p, rp, s, rs;
  #ifndef BOOST_SIMD_DONT_CARE_FMA_OVERFLOW
          using iA0 = bd::as_integer_t<A0>;
          A0 amax =  maxmag(a0, a1);
          A0 amin =  minmag(a0, a1);
          iA0 e0 = -shift_right(exponent(amax), 1);
          amax = ldexp(amax, e0);
          A0 a02 = ldexp(a2, e0);
          std::tie(p, rp) = two_prod(amax, amin);
          std::tie(s, rs) = two_add(p, a02);
          return ldexp(s+(rp+rs), -e0);
  #else
          std::tie(p, rp) = two_prod(a0, a1);
          std::tie(s, rs) = two_add(p, a2);
          return s+(rp+rs);
  #endif
      }
   };

   BOOST_DISPATCH_OVERLOAD(correct_fma_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::int_<A0>, X>
                          , bs::pack_<bd::int_<A0>, X>
                          , bs::pack_<bd::int_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1, const A0& a2) const BOOST_NOEXCEPT
      {
        // correct fma has to ensure "no intermediate overflow".
        // This is done in the case of signed integers by transtyping to unsigned type
        // to perform the computations in a guaranteed 2-complement environment
        // since signed integer oveflow in C++ produces "undefined results"
        using utype =  bd::as_integer_t<A0>;
        return bitwise_cast<A0>(correct_fma(bitwise_cast<utype>(a0), bitwise_cast<utype>(a1), bitwise_cast<utype>(a2)));
      }
   };

   BOOST_DISPATCH_OVERLOAD(correct_fma_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::uint_<A0>, X>
                          , bs::pack_<bd::uint_<A0>, X>
                          , bs::pack_<bd::uint_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const A0& a1, const A0& a2) const BOOST_NOEXCEPT
      {
        return a0*a1+a2;
      }
   };

} } }


#endif

