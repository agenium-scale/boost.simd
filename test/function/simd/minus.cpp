//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
//#define BOOST_SIMD_ONE_BYTE_ELEMENTS_SIMD_VECTORS_ARE_NUMERIC
#include <boost/simd/function/minus.hpp>
#include <simd_test.hpp>
#include <boost/simd/pack.hpp>

STF_CASE_TPL("minus", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::minus;
  using p_t = bs::pack < T> ;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  T a[16] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4 };
  p_t aa(&a[0], &a[N]);
  T b[16] = {5, 6, 7, 8, 5, 6, 7, 8, 5, 6, 7, 8, 5, 6, 7, 8 };
  p_t bb(&b[0], &b[N]);
  T c[16] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
  p_t cc(&c[0], &c[N]);
  p_t dd = (bb-aa);
  p_t ee = minus(bb, aa);
  STF_IEEE_EQUAL(cc, dd);
  STF_IEEE_EQUAL(cc, ee);
}

STF_CASE_TPL("minus", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::minus;
  static const std::size_t N = 4;
  using p_t = bs::pack < T, N> ;
  T a[16] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4 };
  p_t aa(&a[0], &a[N]);
  T b[16] = {5, 6, 7, 8, 5, 6, 7, 8, 5, 6, 7, 8, 5, 6, 7, 8 };
  p_t bb(&b[0], &b[N]);
  T c[16] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
  p_t cc(&c[0], &c[N]);
  p_t dd = (bb-aa);
  p_t ee = minus(bb, aa);
  STF_IEEE_EQUAL(cc, dd);
  STF_IEEE_EQUAL(cc, ee);
}

