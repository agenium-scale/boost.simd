//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_COMBINE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_COMBINE_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( combine_, tag::simd_
                          , (A0)
                          , ((scalar_<unspecified_<A0>))
                            ((scalar_<unspecified_<A0>>))
                          )
  {
    BOOST_FORCEINLINE bs::pack<A0,2> operator()(A0 const& a0, A0 const& a1) const BOOST_NOEXCEPT
    {
      return {a0,a1};
    }
  };
} } }

#endif
