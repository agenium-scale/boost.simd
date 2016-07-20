//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_ENUMERATE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_ENUMERATE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( enumerate_
                          , (typename T)
                          , bs::vmx_
                          , bd::target_<bs::pack_<bd::ints8_<T>, bs::vmx_>>
                          )
  {
    using target = typename T::type;

    BOOST_FORCEINLINE target operator()(T const& ) const BOOST_NOEXCEPT
    {
      using u8type = typename target::template rebind<unsigned char>;
      return bitwise_cast<target>(u8type(vec_lvsl(0,(unsigned char*)(0))));
    }
  };
} } }

#endif
