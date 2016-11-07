//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FREXP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FREXP_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/ifrexp.hpp>
#include <boost/simd/function/tofloat.hpp>
#include <utility>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(frexp_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
     BOOST_FORCEINLINE std::pair<A0,A0> operator()(A0 const& a0) const
     {
       A0 r0;
       using i_t = bd::as_integer_t<A0, signed>;
       i_t r1;
       std::tie(r0, r1) = ifrexp(a0);
       return {r0, tofloat(r1)};
     }
   };

  BOOST_DISPATCH_OVERLOAD( frexp_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , boost::simd::fast_tag
                          , bs::pack_< bd::floating_<A0>, X>
                          )
  {
    BOOST_FORCEINLINE std::pair<A0,A0> operator() (const fast_tag &
                                                   , A0 const& a0 ) const BOOST_NOEXCEPT
    {
       A0 r0;
       using i_t = bd::as_integer_t<A0, signed>;
       i_t r1;
       std::tie(r0, r1) = fast_(ifrexp)(a0);
       return {r0, tofloat(r1)};
    }
  };

} } }

#endif

