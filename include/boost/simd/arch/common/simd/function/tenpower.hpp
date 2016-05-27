//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TENPOWER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TENPOWER_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/ten.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/abs.hpp>
#include <boost/simd/function/simd/any.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_ltz.hpp>
#include <boost/simd/function/simd/is_odd.hpp>
#include <boost/simd/function/simd/multiplies.hpp>
#include <boost/simd/function/simd/rec.hpp>
#include <boost/simd/function/simd/shift_right.hpp>
#include <boost/simd/function/simd/sqr.hpp>
#include <boost/simd/detail/dispatch/meta/as_floating.hpp>
#include <boost/mpl/equal_to.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(tenpower_
                             , (typename A0, typename X)
                             , bd::cpu_
                             , bs::pack_<bd::int_<A0>, X>
                             )
   {
      using result = bd::as_floating_t<A0>;
      BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        result res = One<result>();
        result base = Ten<result>();
        A0 exp = bs::abs(a0);
        while(any(exp))
        {
          //       res *= if_else(is_odd(exp), base, One<result>()); TO DO
          res =  res * if_else(is_odd(exp), base, One<result>());
          //  exp >>= 1; TODO
          exp =  shift_right(exp, 1);
          base = sqr(base);
        }
        return if_else(is_ltz(a0), bs::rec(res), res);
      }
   };

   BOOST_DISPATCH_OVERLOAD(tenpower_
                             , (typename A0, typename X)
                             , bd::cpu_
                             , bs::pack_<bd::uint_<A0>, X>
                             )
   {
      using result = bd::as_floating_t<A0>;
      BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        result res = One<result>();
        result base = Ten<result>();
        A0 exp = a0;
        while(any(exp))
        {
          res = res*if_else(is_odd(exp), base, One<result>()); // TODO
//          res *= if_else(is_odd(exp), base, One<result>());
          //  exp >>= 1; TODO
          exp =  shift_right(exp, 1);
          base = sqr(base);
        }
        return res;
      }
   };

} } }


#endif

