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
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MAJORITY_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MAJORITY_HPP_INCLUDED

#include <boost/simd/logical.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
// TODO mix logical fundamental ?

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( majority_
                          , (typename A0, typename A1, typename A2)
                          , bd::cpu_
                          , bd::scalar_< bd::bool_<A0> >
                          , bd::scalar_< bd::bool_<A1> >
                          , bd::scalar_< bd::bool_<A2> >
                          )
  {
    BOOST_FORCEINLINE bool operator() ( A0 a0, A1 a1, A2 a2) const BOOST_NOEXCEPT
    {
      return ((a0&&a1)||(a1&&a2)||(a2&&a0));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( majority_
                          , (typename A0, typename A1, typename A2)
                          , bd::cpu_
                          , bd::scalar_< bd::fundamental_<A0> >
                          , bd::scalar_< bd::fundamental_<A1> >
                          , bd::scalar_< bd::fundamental_<A2> >
                          )
  {
    BOOST_FORCEINLINE logical<A0> operator() ( A0 a0, A1 a1, A2 a2) const BOOST_NOEXCEPT
    {
      return ((a0&&a1)||(a1&&a2)||(a2&&a0));
    }
  };
  BOOST_DISPATCH_OVERLOAD ( majority_
                          , (typename A0, typename A1, typename A2)
                          , bd::cpu_
                          , bd::scalar_< logical_<A0> >
                          , bd::scalar_< logical_<A1> >
                          , bd::scalar_< logical_<A2> >
                          )
  {
    BOOST_FORCEINLINE logical<A0> operator() ( A0 a0, A1 a1, A2 a2) const BOOST_NOEXCEPT
    {
      return ((a0.value()&&a1.value())||(a1.value()&&a2.value())||(a2.value()&&a0.value()));
    }
  };
} } }


#endif
