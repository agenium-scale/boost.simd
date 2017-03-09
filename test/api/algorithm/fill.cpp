//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/algorithm/fill.hpp>
#include <numeric>
#include <vector>
#include <simd_test.hpp>

using namespace boost::simd;
using namespace boost::alignment;


STF_CASE_TPL( "Check unary simd::fill", STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  std::vector<T> values1(2*N+1), values2(2*N+1);;
  std::fill(values1.begin(), values1.end(),T(1));
  boost::simd::fill(values2.data(), values2.data()+values2.size(),T(1));

  STF_EQUAL (true, std::equal(values1.begin(), values1.end(), values2.begin()));


}


