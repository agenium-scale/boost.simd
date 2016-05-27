//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_POSMAX_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_POSMAX_HPP_INCLUDED

#include <boost/simd/constant/zero.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( posmax_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_<bd::fundamental_<A0> >
                          )
  {
    BOOST_FORCEINLINE std::size_t operator() (A0 ) const BOOST_NOEXCEPT
    {
      return Zero<std::size_t>();
    }
  };
} } }


#endif
