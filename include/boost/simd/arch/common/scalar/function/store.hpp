//==================================================================================================
/*!
  @file

  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_STORE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_STORE_HPP_INCLUDED

#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/dispatch/adapted/common/pointer.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  /// INTERNAL ONLY - Scalar store and store are equivalent
  BOOST_DISPATCH_OVERLOAD ( store_
                          , (typename A0, typename A1, typename A2)
                          , bd::cpu_
                          , bd::scalar_< bd::unspecified_<A0> >
                          , bd::pointer_<bd::scalar_<bd::unspecified_<A1>>,1u>
                          , bd::scalar_<bd::integer_<A2>>
                          )
  {
    BOOST_FORCEINLINE void operator() ( A0 const& a0, A1 a1,  A2 const & a2) const BOOST_NOEXCEPT
    {
      *(a1+a2) = a0;
    }
  };

  /// INTERNAL ONLY - Scalar store and store are equivalent
  BOOST_DISPATCH_OVERLOAD ( store_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::scalar_< bd::unspecified_<A0> >
                          , bd::pointer_<bd::scalar_<bd::unspecified_<A1>>,1u>
                          )
  {
    BOOST_FORCEINLINE void operator() ( A0 const& a0, A1 a1) const BOOST_NOEXCEPT
    {
      *a1 = a0;
    }
  };

  /// INTERNAL ONLY -  scalar masked store
  BOOST_DISPATCH_OVERLOAD ( store_
                          , (typename A0, typename A1, typename A2)
                          , bd::cpu_
                          , bd::scalar_< bd::unspecified_<A0> >
                          , bd::pointer_<bd::scalar_<bd::unspecified_<A1>>,1u>
                          , bd::scalar_ < bd::fundamental_<A2>>
                          )
  {
    BOOST_FORCEINLINE void operator() ( A0 const& a0, A1 a1, A2 const& a2) const BOOST_NOEXCEPT
    {
      if (a2) *a1 = a0;
    }
  };

  /// INTERNAL ONLY -  scalar masked store
  BOOST_DISPATCH_OVERLOAD ( store_
                          , (typename A0, typename A1, typename A2, typename A3)
                          , bd::cpu_
                          , bd::scalar_< bd::unspecified_<A0> >
                          , bd::pointer_<bd::scalar_<bd::unspecified_<A1>>,1u>
                          , bd::scalar_<bd::integer_<A2>>
                          , bd::scalar_ < bd::fundamental_<A3>>
                          )
  {
    BOOST_FORCEINLINE void operator() ( A0 const& a0, A1 a1, A2 const& a2, A3 const& a3) const BOOST_NOEXCEPT
    {
      if (a3) *(a1+a2) = a0;
    }
  };

} } }


#endif
