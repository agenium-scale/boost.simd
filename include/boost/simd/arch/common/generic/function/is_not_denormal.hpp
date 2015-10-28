//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_IS_NOT_DENORMAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_IS_NOT_DENORMAL_HPP_INCLUDED

#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_not_less.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/logical.hpp>
//#include <boost/simd/constant/true.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
//TODO LOGICAL

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( is_not_denormal_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::arithmetic_<A0> >
                          )
  {
    BOOST_FORCEINLINE logical<A0> operator() (const A0& ) const BOOST_NOEXCEPT
    {
      return true; //True<result_type>();
    }
  };

  BOOST_DISPATCH_OVERLOAD ( is_not_denormal_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE logical<A0> operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      return logical_or(is_eqz(a0), is_not_less(simd::abs(a0), Smallestposval<A0>()));
    }
  };
} } }


#endif
