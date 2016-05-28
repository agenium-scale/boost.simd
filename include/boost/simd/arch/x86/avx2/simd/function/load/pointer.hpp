//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_LOAD_POINTER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_LOAD_POINTER_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/dispatch/adapted/common/pointer.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // load from a pointer of integers
  BOOST_DISPATCH_OVERLOAD_IF( load_
                            , (typename Target, typename Pointer)
                            , (bs::is_pointing_to<Pointer,typename Target::type::value_type>)
                            , bs::avx2_
                            , bd::pointer_<bd::scalar_<bd::integer_<Pointer>>,1u>
                            , bd::target_<bs::pack_<bd::integer_<Target>,bs::avx_>>
                            )
  {
    using target = typename Target::type;
    BOOST_FORCEINLINE target operator()(Pointer p, Target const&) const
    {
      return _mm256_loadu_si256((__m256i*)(p));
    }
  };
} } }

#endif
