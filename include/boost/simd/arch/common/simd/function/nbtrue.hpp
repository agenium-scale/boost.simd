//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/scalar/is_nez.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>


namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  BOOST_DISPATCH_OVERLOAD ( nbtrue_
                          , (typename A0)
                          , bs::simd_
                          , bs::pack_<bd::fundamental_<A0>,bs::simd_emulation_>
                          )
  {
    BOOST_FORCEINLINE std::size_t operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      std::size_t n = 0;
      for(size_t i=0; i < A0::static_size; ++i) n += is_nez(a0[i]);
      return n;
    }
  };
  BOOST_DISPATCH_OVERLOAD ( nbtrue_
                          , (typename A0)
                          , bs::simd_
                          , bs::pack_<bs::logical_<A0>,bs::simd_emulation_>
                          )
  {
    BOOST_FORCEINLINE std::size_t operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      std::size_t n = 0;
      for(size_t i=0; i < A0::static_size; ++i) n += is_nez(a0[i]);
      return n;
    }
  };

} } }

#endif
