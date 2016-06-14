//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_SHUFFLE_TOPOLOGY_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_SHUFFLE_TOPOLOGY_HPP_INCLUDED

#include <type_traits>
#include <boost/simd/arch/x86/sse1/simd/function/topology.hpp>

namespace boost { namespace simd { namespace detail
{
  // -----------------------------------------------------------------------------------------------
  // Local masking utility
  template<int P0,int P1>
  struct mask_pd : std::integral_constant<int, _MM_SHUFFLE2(P1&1,P0&1)>
  {};

  // -----------------------------------------------------------------------------------------------
  // SSE cardinal 2 specialisation
  template<int P0, int P1> struct sse_topology<2,P0,P1>
  {
    // is the pattern leads to a direct shuffle call?
    static const bool direct   = (P0 <= 1) && (P1 >= 2);
    using mode = std::integral_constant<int, 0x01 * direct + 0x02 * !direct>;

    // is the pattern one-sided ?
    static const bool unary_a0 = (P0 <= 1) && (P1 <= 1);
    static const bool unary_a1 = ((P0 >= 2) || (P0==-1)) && ((P1 >= 2) || (P1==-1));
    using is_left  = std::integral_constant<bool, unary_a0>;
    using is_right = std::integral_constant<bool, unary_a1>;
  };
} } }

#endif

