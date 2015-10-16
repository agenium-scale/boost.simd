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
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IDIVFLOOR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IDIVFLOOR_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/function/ifloor.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/divfloor.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( idivfloor_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::arithmetic_<A0> >
                          , bd::generic_< bd::arithmetic_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0, A0 const& a1) const BOOST_NOEXCEPT
    {
      return divfloor(a0, a1);
    }
  };

#ifdef BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4723) // potential divide by 0
#endif

  BOOST_DISPATCH_OVERLOAD ( idivfloor_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE bd::as_integer_t<A0> operator() ( A0 const& a0, A0 const& a1) const BOOST_NOEXCEPT
    {
      return ifloor(a0/a1);
    }
  };

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif
} } }


#endif
