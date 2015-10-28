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

//#include <boost/simd/pack.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
//   BOOST_DISPATCH_IMPLEMENT          ( combine_
//                                     , tag::cpu_
//                                     , (A0)
//                                     , ((scalar_<unspecified_<A0>))
//                                       ((scalar_<unspecified_<A0>>))
//                                     )
//   {
//     using result_t =   pack<A0, 2 >::type;

//     BOOST_FORCEINLINE result_t operator()(A0 const& a0, A0 const& a1) const BOOST_NOEXCEPT
//     {
//       result_t that;
//       that[0] = a0;
//       that[1] = a1;
//       return that;
//     }
} } }


#endif
