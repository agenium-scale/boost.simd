//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_SPLAT_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( splat_
                          , (typename A0, typename Target)
                          , bs::vmx_
                          , bd::scalar_< bd::unspecified_<A0> >
                          , bd::target_<bs::pack_<bd::type8_<Target>, bs::vmx_>>
                           )
  {
    using target_t = typename Target::type;
    using value_t  = typename target_t::value_type;

    BOOST_FORCEINLINE target_t operator()(A0 const& a0, Target const&) const
    {
      return  { value_t(a0), value_t(a0), value_t(a0), value_t(a0)
              , value_t(a0), value_t(a0), value_t(a0), value_t(a0)
              , value_t(a0), value_t(a0), value_t(a0), value_t(a0)
              , value_t(a0), value_t(a0), value_t(a0), value_t(a0)
              };
    }
  };

  BOOST_DISPATCH_OVERLOAD ( splat_
                          , (typename A0, typename Target)
                          , bs::vmx_
                          , bd::scalar_< bd::unspecified_<A0> >
                          , bd::target_<bs::pack_<bd::type16_<Target>, bs::vmx_>>
                          )
  {
    using target_t = typename Target::type;
    using value_t  = typename target_t::value_type;

    BOOST_FORCEINLINE target_t operator()(A0 const& a0, Target const&) const
    {
      return  { value_t(a0), value_t(a0), value_t(a0), value_t(a0)
              , value_t(a0), value_t(a0), value_t(a0), value_t(a0)
              };
    }
  };

  BOOST_DISPATCH_OVERLOAD ( splat_
                          , (typename A0, typename Target)
                          , bs::vmx_
                          , bd::scalar_< bd::unspecified_<A0> >
                          , bd::target_<bs::pack_<bd::type32_<Target>, bs::vmx_>>
                          )
  {
    using target_t = typename Target::type;
    using value_t  = typename target_t::value_type;

    BOOST_FORCEINLINE target_t operator()(A0 const& a0, Target const&) const
    {
      return { value_t(a0), value_t(a0), value_t(a0), value_t(a0) };
    }
  };
} } }

#endif
