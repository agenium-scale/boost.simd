//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_DIVIDES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_DIVIDES_HPP_INCLUDED

#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/hierarchy.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( divides_
                          , (typename T)
                          , bd::cpu_
                          , boost::simd::fast_tag
                          , bd::generic_<bd::unspecified_<T>>
                          , bd::generic_<bd::unspecified_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(const fast_tag &, T const& a, T const& b
                                  ) const BOOST_NOEXCEPT
    {
      return divides(a, b);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( divides_
                          , (typename T)
                          , bd::cpu_
                          , boost::simd::fast_tag
                          , bd::generic_<bd::floating_<T>>
                          , bd::generic_<bd::floating_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(const fast_tag &, T const& a, T const& b
                                  ) const BOOST_NOEXCEPT
    {
      return a*fast_(rec)(b);
    }
  };
   BOOST_DISPATCH_OVERLOAD ( divides_
                          , (typename T)
                          ,  bd::cpu_
                          ,  bs::saturated_tag
                          ,  bd::generic_<bd::fundamental_<T>>
                          ,  bd::generic_<bd::fundamental_<T>>
                          )
  {
    BOOST_FORCEINLINE T operator()(const saturated_tag &, const T& a, const T& b) const BOOST_NOEXCEPT
    {
      return saturated_(divides)(a, b);
    }
  };
} } }

#endif
