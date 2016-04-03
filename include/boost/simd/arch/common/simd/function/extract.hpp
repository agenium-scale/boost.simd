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
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  BOOST_DISPATCH_OVERLOAD ( extract_
                          , (typename A0, typename Ext, typename A1)
                          , bs::simd_
                          , bs::pack_<bd::arithmetic_<A0>,Ext>
                          , bd::scalar_< bd::integer_<A1> >
                          )
  {
    using result_t = typename A0::value_type;
    BOOST_FORCEINLINE result_t operator() ( A0 const& a0, A1 i) const BOOST_NOEXCEPT
    {
      return result_t(reinterpret_cast<detail::may_alias_t<result_t const>*>( &(a0.storage()) )[i]);
    }
  };
} } }

#endif
