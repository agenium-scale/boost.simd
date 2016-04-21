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
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/divides_s.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/hierarchy.hpp>
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
                          ,  bd::generic_<bd::fundamental_<T>>
                          ,  bd::generic_<bd::fundamental_<T>>
                          ,  bs::saturated_tag
                          )
  {
    BOOST_FORCEINLINE T operator()(const T& a, const T& b, const saturated_tag &) const BOOST_NOEXCEPT
    {
      return divides_s(a, b);
    }
  };
} } }

#endif
