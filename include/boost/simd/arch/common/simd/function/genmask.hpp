//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_GENMASK_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_GENMASK_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/meta/hierarchy/logical.hpp>
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/meta/as_arithmetic.hpp>
// if_else_zero is not stil correct
#include <boost/simd/function/simd/is_nez.hpp>
#include <boost/simd/function/simd/if_else_zero.hpp>
#include <boost/simd/function/simd/is_nez.hpp>
#include <boost/simd/function/simd/if_else.hpp>

#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  // -----------------------------------------------------------------------------------------------
  // genmask from logical
  BOOST_DISPATCH_OVERLOAD ( genmask_
                          , (typename A0, typename X)
                          , bs::simd_
                          , bs::pack_< bs::logical_<A0>, X >
                          )
  {
    using result_t = as_arithmetic_t<A0>;

    BOOST_FORCEINLINE result_t operator()( A0 const& a0 ) const BOOST_NOEXCEPT
    {
      // TODO: Handle non-logical mask values
      return bitwise_cast<result_t>(a0);
    }
  };

   BOOST_DISPATCH_OVERLOAD(genmask_
                          , (typename A0,typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>,X>
                          )

  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
    {
       return if_else(a0,  Allbits<A0>(), Zero<A0>());
    }
  };
} } }

#endif
