//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_DETAIL_SCALAR_EXPO_SCALE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_DETAIL_SCALAR_EXPO_SCALE_HPP_INCLUDED

#include <boost/simd/constant/maxexponent.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/shift_left.hpp>
#include <boost/simd/function/simd/toint.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    namespace bd =  boost::dispatch;
    namespace bs =  boost::simd;

    template < class A0 >
    inline A0 scale(A0 const & y, const A0& k)
    {
      using i_t = bd::as_integer_t<A0>;
      i_t ik =  toint(k);
      ik =  ik + Maxexponent<A0>();//+=  Maxexponent<A0>();
      ik = shift_left(ik, Nbmantissabits<A0>());
      return y*bitwise_cast<A0>(ik);;
    }
  }
} }
#endif
