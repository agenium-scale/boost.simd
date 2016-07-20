//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LDEXP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LDEXP_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/config.hpp>
#include <boost/simd/constant/limitexponent.hpp>
#include <boost/simd/constant/maxexponent.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/is_equal.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/function/simd/rshl.hpp>
#include <boost/simd/function/simd/if_plus.hpp>
#include <boost/simd/function/simd/if_minus.hpp>
#include <boost/simd/function/simd/shift_left.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

#ifndef BOOST_SIMD_NO_DENORMALS
#include <boost/simd/constant/minexponent.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_less.hpp>
#include <boost/simd/function/simd/if_minus.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(ldexp_
                             , (typename A0, typename A1, typename X)
                             , bd::cpu_
                             , bs::pack_<bd::integer_<A1>, X>
                             , bs::pack_<bd::integer_<A0>, X>
                             )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const  A1&  a1) const BOOST_NOEXCEPT
      {
        return rshl(a0, a1);
      }
   };

   BOOST_DISPATCH_OVERLOAD(ldexp_
                             , (typename A0, typename A1, typename X, typename Y)
                             , bd::cpu_
                             , bs::pack_<bd::floating_<A0>, X>
                             , bs::pack_<bd::integer_<A1>, Y>
                             )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0, const  A1&  a1) const BOOST_NOEXCEPT
      {
        using iA0 = bd::as_integer_t<A0>;
        using sA0 = bd::scalar_of_t<A0>;
        iA0 e = a1;
        A0 f = One<A0>();
  #ifndef BOOST_SIMD_NO_DENORMALS
        auto denormal =  is_less(e, Minexponent<A0>());
        e = if_minus(denormal, e, Minexponent<A0>());
        f = if_else(denormal, Smallestposval<A0>(), One<A0>());
  #endif
        auto test = is_equal(e, Limitexponent<A0>());
        f = if_plus(test, f, One<A0>());
        e = if_minus(test, e, One<iA0>());
        e = e+Maxexponent<A0>();
        e = shift_left(e, Nbmantissabits<sA0>());
        return a0*bitwise_cast<A0>(e)*f;
      }
   };


} } }

#endif

