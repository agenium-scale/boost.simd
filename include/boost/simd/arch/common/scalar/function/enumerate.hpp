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
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ENUMERATE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ENUMERATE_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/constant/zero.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( enumerate_
                          , (typename T)
                          , bd::cpu_
                          , bd::target_< bd::scalar_< bd::unspecified_<T> > >
                          )
  {
    using result_t = typename T::type;
    result_t operator() (T const& ) const BOOST_NOEXCEPT
    {
      return Zero<result_t>();
    }
  };

  BOOST_DISPATCH_OVERLOAD ( enumerate_
                          , (typename A0, typename T)
                          , bd::cpu_
                          , bd::scalar_< bd::unspecified_<A0> >
                          , bd::target_< bd::scalar_< bd::unspecified_<T> > >
                          )
  {
    using result_t = typename T::type;
    result_t operator() ( A0 const& a0, T const& ) const BOOST_NOEXCEPT
    {
      return static_cast<result_t>(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( enumerate_
                          , (typename A0, typename A1,typename T)
                          , bd::cpu_
                          , bd::scalar_< bd::arithmetic_<A0> >
                          , bd::scalar_< bd::arithmetic_<A1> >
                          , bd::target_< bd::scalar_< bd::arithmetic_<T> > >
                          )
  {
    using result_t = typename T::type;
    result_t operator() ( A0 a0, A1 const&, T const& ) const BOOST_NOEXCEPT
    {
      return static_cast<result_t>(a0);
    }
  };
} } }


#endif
