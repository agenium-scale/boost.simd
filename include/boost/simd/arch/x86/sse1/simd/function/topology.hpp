//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_TOPOLOGY_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_TOPOLOGY_HPP_INCLUDED

#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  // -----------------------------------------------------------------------------------------------
  // Local masking utility
  template<int P0,int P1, int P2, int P3>
  struct mask_ps : std::integral_constant<int, _MM_SHUFFLE(P3&3,P2&3,P1&3,P0&3)>
  {};

  // -----------------------------------------------------------------------------------------------
  // Markup for SSE topology
  // direct_    means the pattern is of the shape { a0 | a1 }
  // indirect_  means the pattern is of the shape { a1 | a0 }
  // mixed_     means the pattern is random
  // -----------------------------------------------------------------------------------------------
  typedef std::integral_constant<int,0x00>  mixed_;
  typedef std::integral_constant<int,0x01>  direct_;
  typedef std::integral_constant<int,0x02>  indirect_;

  // -----------------------------------------------------------------------------------------------
  // Check if a permutation follows SSE shuffle restriction in a way or another
  template<int Card, int... Ps> struct sse_topology;

  // -----------------------------------------------------------------------------------------------
  // SSE handle only cardinal 4 through float
  template<int P0, int P1, int P2, int P3> struct sse_topology<4,P0,P1,P2,P3>
  {
    // is the pattern lead to a direct or indirect shuffling ?
    static const bool direct   = (P0 < 4) && (P1 < 4) && (P2 >= 4) && (P3 >= 4);
    static const bool indirect = (P2 < 4) && (P3 < 4) && (P0 >= 4) && (P1 >= 4);
    using mode = std::integral_constant<int, 0x01 * direct + 0x02 * indirect>;

    // is the pattern one-sided ?
    static const bool unary_a0 = (P0 < 4 ) && (P1 < 4) && (P2 < 4 ) && (P3 < 4);
    static const bool unary_a1 = ((P0 >= 4) || (P0==-1)) && ((P1 >= 4) || (P1==-1))
                              && ((P2 >= 4) || (P2==-1)) && ((P3 >= 4) || (P3==-1));
    using is_left  = std::integral_constant<bool, unary_a0>;
    using is_right = std::integral_constant<bool, unary_a1>;
  };
} } }

#endif

