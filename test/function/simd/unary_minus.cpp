//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define BOOST_SIMD_ONE_BYTE_ELEMENTS_SIMD_VECTORS_ARE_NUMERIC
#include <boost/simd/function/unary_minus.hpp>
#include <simd_test.hpp>
#include <boost/simd/pack.hpp>

STF_CASE_TPL("unary_minus", STF_SIGNED_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::unary_minus;
  using p_t = bs::pack < T> ;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  T a[16] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4 };
  p_t aa(&a[0], &a[N]);
  T c[16] = {-1, -2, -3, -4, -1, -2, -3, -4, -1, -2, -3, -4, -1, -2, -3, -4 };;

  p_t cc(&c[0], &c[N]);
  p_t ee = unary_minus(aa);
  STF_IEEE_EQUAL(cc, ee);
//  this fails for int8_t, int_16_t and int_32_t without redefining operator-(..)
   p_t dd = -aa;
   STF_IEEE_EQUAL(cc, dd);
}

