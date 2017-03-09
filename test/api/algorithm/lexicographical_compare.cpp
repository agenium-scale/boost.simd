//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/algorithm/lexicographical_compare.hpp>
#include <boost/simd/function/compare_greater.hpp>
#include <numeric>
#include <vector>
#include <simd_test.hpp>

using namespace boost::simd;
using namespace boost::alignment;


STF_CASE_TPL( "Check unary simd::lexicographical_compare", STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  std::vector<T> values1(2*N+1), values2(2*N+1);;
  std::iota(values1.begin(), values1.end(),T(1));
  std::iota(values2.begin(), values2.end(),T(2));

  {
    bool b1 = boost::simd::lexicographical_compare( values2.data(), values2.data()+2*N+1, values2.data(), values2.data()+2*N+1);
    bool sb1 = std::lexicographical_compare( values2.data(), values2.data()+2*N+1, values2.data(), values2.data()+2*N+1);
    STF_EQUAL(b1, sb1);
    bool b2 = boost::simd::lexicographical_compare( values1.data(), values1.data()+2*N+1, values2.data(), values2.data()+2*N+1);
    bool sb2 = std::lexicographical_compare( values1.data(), values1.data()+2*N+1, values2.data(), values2.data()+2*N+1);
    STF_EQUAL(b2, sb2);
    bool b3 = boost::simd::lexicographical_compare( values1.data(), values1.data()+2*N+1, values1.data(), values1.data()+2*N-1);
    bool sb3 = std::lexicographical_compare( values1.data(), values1.data()+2*N+1, values1.data(), values1.data()+2*N-1);
    STF_EQUAL(b3, sb3);
    bool b4 = boost::simd::lexicographical_compare( values2.data(), values2.data()+2*N+1, values1.data(), values1.data()+2*N-1);
    bool sb4 = std::lexicographical_compare( values2.data(), values2.data()+2*N+1, values1.data(), values1.data()+2*N-1);
    STF_EQUAL(b4, sb4);
    bool b5 = boost::simd::lexicographical_compare( values1.data(), values1.data()+2*N-1, values1.data(), values1.data()+2*N+1);
    bool sb5 = std::lexicographical_compare( values1.data(), values1.data()+2*N-1, values1.data(), values1.data()+2*N+1);
    STF_EQUAL(b5, sb5);
  }
  {
    bool b1 = boost::simd::lexicographical_compare( values2.data(), values2.data()+2*N+1, values2.data(), values2.data()+2*N+1, bs::compare_greater);
    bool sb1 = std::lexicographical_compare( values2.data(), values2.data()+2*N+1, values2.data(), values2.data()+2*N+1, bs::compare_greater);
    STF_EQUAL(b1, sb1);
    bool b2 = boost::simd::lexicographical_compare( values1.data(), values1.data()+2*N+1, values2.data(), values2.data()+2*N+1, bs::compare_greater);
    bool sb2 = std::lexicographical_compare( values1.data(), values1.data()+2*N+1, values2.data(), values2.data()+2*N+1, bs::compare_greater);
    STF_EQUAL(b2, sb2);
    bool b3 = boost::simd::lexicographical_compare( values1.data(), values1.data()+2*N+1, values1.data(), values1.data()+2*N-1, bs::compare_greater);
    bool sb3 = std::lexicographical_compare( values1.data(), values1.data()+2*N+1, values1.data(), values1.data()+2*N-1, bs::compare_greater);
    STF_EQUAL(b3, sb3);
    bool b4 = boost::simd::lexicographical_compare( values2.data(), values2.data()+2*N+1, values1.data(), values1.data()+2*N-1, bs::compare_greater);
    bool sb4 = std::lexicographical_compare( values2.data(), values2.data()+2*N+1, values1.data(), values1.data()+2*N-1, bs::compare_greater);
    STF_EQUAL(b4, sb4);
    bool b5 = boost::simd::lexicographical_compare( values1.data(), values1.data()+2*N-1, values1.data(), values1.data()+2*N+1, bs::compare_greater);
    bool sb5 = std::lexicographical_compare( values1.data(), values1.data()+2*N-1, values1.data(), values1.data()+2*N+1, bs::compare_greater);
    STF_EQUAL(b5, sb5);
  }
}


