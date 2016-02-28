//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXTRACT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXTRACT_HPP_INCLUDED

#include <boost/simd/detail/aliasing.hpp>
#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( extract_
                          , (typename A0, typename Ext, typename A1)
                          , bs::simd_
                          , bs::pack_<bd::unspecified_<A0>,Ext>
                          , bd::scalar_< bd::integer_<A1> >
                          )
  {
    using value_t = typename A0::value_type;
    using cref_t  = typename A0::const_reference;
    using ref_t   = typename A0::reference;

    BOOST_FORCEINLINE cref_t operator() ( A0 const& a0, A1 a1) const BOOST_NOEXCEPT
    {
      return reinterpret_cast<typename detail::may_alias<value_t const>::type*>(&a0.storage())[a1];
    }

    BOOST_FORCEINLINE ref_t operator() ( A0& a0, A1 a1) const BOOST_NOEXCEPT
    {
      return reinterpret_cast<typename detail::may_alias<value_t>::type*>(&a0.storage())[a1];
    }
  };
} } }

#endif
