//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_PERMUTATION_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_PERMUTATION_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/shuffle.hpp>

// This macro helps making specific cases of shuffle
// CODE is the actual code
// ... contains the pattern descriptor
#define BOOST_SIMD_GENERIC_PATTERN(CODE,...)                                                        \
{                                                                                                   \
  BOOST_FORCEINLINE A0                                                                              \
  operator()(bsd::pattern_<__VA_ARGS__> const&, const A0 & a0) const BOOST_NOEXCEPT                 \
  {                                                                                                 \
    return CODE;                                                                                    \
  }                                                                                                 \
}                                                                                                   \
/**/

#define BOOST_SIMD_GENERIC_BINARY_PATTERN(CODE,...)                                                 \
{                                                                                                   \
  BOOST_FORCEINLINE A0                                                                              \
  operator()(bsd::pattern_<__VA_ARGS__> const&, const A0 & a0, const A0 & a1) const BOOST_NOEXCEPT  \
  {                                                                                                 \
    return CODE;                                                                                    \
  }                                                                                                 \
}                                                                                                   \
/**/

namespace boost { namespace simd { namespace detail
{
  // -----------------------------------------------------------------------------------------------
  // Check if any -1 is in a pattern pack
  template<int... Ps>
  struct  perform_zeroing
        : brigand::bool_< !std::is_same < brigand::detail::bools_<true       , (Ps != -1)...>
                                        , brigand::detail::bools_<(Ps != -1)... , true      >
                                        >::value
                        >
  {};

  // -----------------------------------------------------------------------------------------------
  // Checks if a binary shuffle is actually unary
  template<int... Ps> struct which_side
  {
    using card = std::integral_constant<int,sizeof...(Ps)>;

    using all_a0 = brigand::all < brigand::integral_list<int,Ps...>
                                , brigand::less<brigand::_1,card>
                                >;

    using all_a1 = brigand::all < brigand::integral_list<int,Ps...>
                                , brigand::or_<brigand::greater_equal<brigand::_1,card>
                                              ,brigand::equal_to< brigand::_1
                                                                , std::integral_constant<int,-1>
                                                                >
                                              >
                                >;

    using type = std::integral_constant<int, all_a0::value * 0x01 + all_a1::value * 0x02>;
  };

  // -----------------------------------------------------------------------------------------------
  // Side markups
  using a0_side     = std::integral_constant<int, 1>;
  using a1_side     = std::integral_constant<int, 2>;
  using mixed_side  = std::integral_constant<int, 0>;

  // -----------------------------------------------------------------------------------------------
  // Return a mask depending on a given pattern
  template<typename T, int P>
  struct  zeroing_mask
        : std::integral_constant<T, (P==-1) ? T(0) : ~(T(0))>
  {};
} } }

#endif
