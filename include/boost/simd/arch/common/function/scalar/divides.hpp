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
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_DIVIDES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_DIVIDES_HPP_INCLUDED

#include <boost/dispatch/hierarchy.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_DISPATCH_OVERLOAD ( divides_
                          , (typename T)
                          , boost::dispatch::cpu_
                          , boost::dispatch::scalar_<boost::dispatch::unspecified_<T>>
                          , boost::dispatch::scalar_<boost::dispatch::unspecified_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a, T const& b) const BOOST_NOEXCEPT
    {
      return a/b;
    }
  };
} } }

#endif
