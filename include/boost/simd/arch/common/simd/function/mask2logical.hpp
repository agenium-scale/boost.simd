//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MASK2LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MASK2LOGICAL_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/sdk/as_logical.hpp>
#include <boost/simd/sdk/is_logical_mask.hpp>
#include <boost/simd/detail/assert_utils.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD(mask2logical_
                         , (typename A0,typename X)
                         , bd::cpu_
                         , bs::pack_<bd::arithmetic_<A0>,X>
                         )

  {
    using result =  bs::as_logical_t<A0> ;
    BOOST_FORCEINLINE result operator()( const A0& a0
//                                        , typename std::enable_if<
//                                             bs::is_logical_mask<typename result::type>
//                                          >*= 0
                                       ) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG(assert_is_mask(a0), "Argument to mask2logical is not a valid logical mask");
      return bitwise_cast<result>(a0);
    }
  };

} } }

#endif
