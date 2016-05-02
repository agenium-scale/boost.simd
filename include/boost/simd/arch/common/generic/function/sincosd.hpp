//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_SINCOSD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_SINCOSD_HPP_INCLUDED


#include <boost/simd/arch/common/detail/generic/trigo.hpp>
#include <boost/simd/meta/is_not_scalar.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/fusion/include/std_pair.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( sincosd_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0,A0 & a2) const
    {
      return detail::trig_base <A0,tag::degree_tag,is_not_scalar_t<A0>,tag::big_tag>::sincosa(a0,a2);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( sincosd_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    using result_t = std::pair<A0, A0>                     ;
    BOOST_FORCEINLINE result_t operator() ( A0 const& a0) const
    {
      A0 first, second;
      sincosd(a0, first, second);
      return {first, second};
    }
  };

  BOOST_DISPATCH_OVERLOAD ( sincosd_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE void operator() ( A0 const& a0,A0 & a1,A0 & a2) const
    {
      a1 = sincosd(a0, a2);
    }
  };

} } }


#endif
