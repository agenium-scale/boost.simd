//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ABS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ABS_HPP_INCLUDED

#include <boost/simd/math.hpp>
#include <boost/simd/options.hpp>
#include <boost/dispatch/meta/as_unsigned.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( abs_
                          , (typename T)
                          , bd::cpu_
                          , bd::scalar_<bd::arithmetic_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T a) const BOOST_NOEXCEPT
    {
      using utype = dispatch::as_unsigned_t<T>;

      utype mask = a >> (sizeof(T)*8 - 1);
      return (a + mask) ^ mask;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( abs_
                          , (typename T)
                          , bd::cpu_
                          , bd::scalar_<bd::single_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T a) const BOOST_NOEXCEPT
    {
      #ifdef BOOST_SIMD_HAS_FABSF
       return ::fabsf(a);
      #else
       return (a > 0) ? a : -a;
      #endif
    }
  };

  BOOST_DISPATCH_OVERLOAD ( abs_
                          , (typename T)
                          , bd::cpu_
                          , bd::scalar_<bd::double_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T a) const BOOST_NOEXCEPT
    {
      return ::fabs(a);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( abs_
                          , (typename T)
                          , bd::cpu_
                          , bd::scalar_<bd::unsigned_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T a) const BOOST_NOEXCEPT
    {
      return a;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( abs_
                          , (typename T)
                          , bd::cpu_
                          , bd::scalar_<bd::bool_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T a) const BOOST_NOEXCEPT
    {
      return a;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( abs_
                          , (typename T)
                          , bd::cpu_
                          , bd::scalar_<bd::unspecified_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(T const& a) const BOOST_NOEXCEPT
    {
      return abs(a);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( abs_
                          , (typename T)
                          , bd::cpu_
                          , bd::scalar_<bd::floating_<T>>
                          , boost::simd::std_tag
                          )
  {
    BOOST_FORCEINLINE T operator()(T a, std_tag const&) const BOOST_NOEXCEPT
    {
      return std::fabs(a);
    }
  };
} } }


#endif
