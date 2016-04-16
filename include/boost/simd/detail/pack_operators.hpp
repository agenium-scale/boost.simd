//==================================================================================================
/*!
  @file

  Defines the abstraction for SIMD registers

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_PACK_OPERATORS_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_PACK_OPERATORS_HPP_INCLUDED

#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/modulo.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/is_less_equal.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/is_greater_equal.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/complement.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/logical_not.hpp>
#include <boost/simd/function/unary_plus.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/detail/brigand.hpp>

#include <boost/simd/meta/is_pack.hpp>

namespace boost { namespace simd
{

#define BOOST_SIMD_PACK_DEFINE_OP(type_, op, f)                                                    \
  template <typename T, std::size_t N, typename U> BOOST_FORCEINLINE                               \
  typename std::enable_if<is_not_pack_t<U>::value, pack<type_, N>>::type                           \
  op(pack<T, N> const& p0, U const& s1) BOOST_NOEXCEPT { return f(p0, s1); }                       \
                                                                                                   \
  template <typename T, std::size_t N, typename U> BOOST_FORCEINLINE                               \
  typename std::enable_if<is_not_pack_t<U>::value, pack<type_, N>>::type                           \
  op(U const& s0, pack<T, N> const& p1) BOOST_NOEXCEPT { return f(s0, p1); }                       \
                                                                                                   \
  template <typename T, std::size_t N> BOOST_FORCEINLINE                                           \
  auto op(pack<T, N> const& p0, pack<T, N> const& p1) BOOST_NOEXCEPT                               \
  -> decltype(f(p0, p1)) { return f(p0, p1); }                                                     \
/**/

BOOST_SIMD_PACK_DEFINE_OP(T, operator+, plus)
BOOST_SIMD_PACK_DEFINE_OP(T, operator-, minus)
BOOST_SIMD_PACK_DEFINE_OP(T, operator%, modulo)
BOOST_SIMD_PACK_DEFINE_OP(T, operator/, divides)
BOOST_SIMD_PACK_DEFINE_OP(T, operator*, multiplies)

BOOST_SIMD_PACK_DEFINE_OP(T, operator&, bitwise_and)
BOOST_SIMD_PACK_DEFINE_OP(T, operator|, bitwise_or)
BOOST_SIMD_PACK_DEFINE_OP(T, operator^, bitwise_xor)
BOOST_SIMD_PACK_DEFINE_OP(logical<T>, operator&&, logical_and)
BOOST_SIMD_PACK_DEFINE_OP(logical<T>, operator||, logical_or)

BOOST_SIMD_PACK_DEFINE_OP(T, operator << , shift_left)
BOOST_SIMD_PACK_DEFINE_OP(T, operator >> , shift_right)

BOOST_SIMD_PACK_DEFINE_OP(logical<T>, operator<,  is_less)
BOOST_SIMD_PACK_DEFINE_OP(logical<T>, operator>,  is_greater)
BOOST_SIMD_PACK_DEFINE_OP(logical<T>, operator==, is_equal)
BOOST_SIMD_PACK_DEFINE_OP(logical<T>, operator<=, is_less_equal)
BOOST_SIMD_PACK_DEFINE_OP(logical<T>, operator>=, is_greater_equal)
BOOST_SIMD_PACK_DEFINE_OP(logical<T>, operator!=, is_not_equal)

#undef BOOST_SIMD_PACK_DEFINE_OP

} }

#endif
