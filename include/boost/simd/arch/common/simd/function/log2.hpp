//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOG2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOG2_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/arch/common/detail/simd/logarithm.hpp>
#include <boost/simd/function/ilog2.hpp>
#include <boost/simd/meta/is_not_scalar.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>


namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( log2_
                          , (typename A0,typename X)
                          , bs::simd_
                          , bs::pack_< bd::floating_<A0>, X>
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 const& a0) const BOOST_NOEXCEPT
    {
      return detail::logarithm<A0,is_not_scalar_t<A0>>::log2(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( log2_
                          , (typename A0,typename X)
                          , bs::simd_
                          , bs::pack_< bd::arithmetic_<A0>, X >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 const& a0) const BOOST_NOEXCEPT
    {
      return bs::ilog2(a0);
    }
  };

} } }


#endif
