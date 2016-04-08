//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_LOAD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_LOAD_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/adapted/common/pointer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // load from a pointer of double
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Pointer)
                          , bs::avx_
                          , bd::pointer_<bd::scalar_<bd::double_<Pointer>>,1u>
                          , bd::target_<bs::pack_<bd::double_<Target>,bs::avx_>>
                          )
  {
    using target = typename Target::type;

    BOOST_FORCEINLINE target operator()(Pointer p, Target const&) const
    {
      return _mm256_loadu_pd(p);
    }
  };

  //------------------------------------------------------------------------------------------------
  // load from a pointer of single
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Pointer)
                          , bs::avx_
                          , bd::pointer_<bd::scalar_<bd::single_<Pointer>>,1u>
                          , bd::target_<bs::pack_<bd::single_<Target>,bs::avx_>>
                          )
  {
    using target = typename Target::type;

    BOOST_FORCEINLINE target operator()(Pointer p, Target const&) const
    {
      return _mm256_loadu_ps(p);
    }
  };
} } }

#endif
