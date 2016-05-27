//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_LOG10_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_LOG10_HPP_INCLUDED

#include <boost/simd/arch/common/detail/scalar/logarithm.hpp>
#include <boost/simd/arch/common/detail/simd/logarithm.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/function/assert.hpp>
#include <boost/simd/function/is_not_nan.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/meta/is_not_scalar.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( log10_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      return detail::logarithm<A0,is_not_scalar_t<A0>>::log10(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( log10_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::arithmetic_<A0> >
                          , boost::simd::assert_tag
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 const & a0
                                    , assert_tag const& ) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG(bs::assert_all(is_positive(a0)&&is_not_nan(a0)),
                       "log10(x, assert_) cannot produce complex result.");
      return bs::log10(a0);
    }
  };
} } }


#endif
