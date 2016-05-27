//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_TANPI_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_TANPI_HPP_INCLUDED

#include <boost/simd/arch/common/detail/generic/trigo.hpp>
#include <boost/simd/meta/is_not_scalar.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( tanpi_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      return detail::trig_base<A0,tag::pi_tag,is_not_scalar_t<A0>,tag::big_tag>::tana(a0);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( tanpi_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::scalar_ < bd::unspecified_<A1> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0,  A1 const &) const BOOST_NOEXCEPT
    {
      return detail::trig_base<A0,tag::pi_tag,is_not_scalar_t<A0>,A1>::tana(a0);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( tanpi_
                          , (typename A0)
                          , bd::cpu_
                          , bs::fast_tag
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const fast_tag &,  A0 const& a0) const BOOST_NOEXCEPT
    {
      return detail::trig_base<A0,tag::pi_tag,is_not_scalar_t<A0>,tag::clipped_pio4_tag>::tana(a0);
    }
  };
} } }


#endif
