//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/algorithm/min_element.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <numeric>
#include <vector>
#include <simd_test.hpp>

using namespace boost::simd;
using namespace boost::alignment;


STF_CASE_TPL( "Check unary simd::min_element", STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  std::vector<T> values(2*N+1);
  {
    std::iota(values.begin(), values.end(),T(1));
    values[N] = T(1000);
    auto f1 = std::min_element(values.begin(), values.end());
    auto f2 = boost::simd::min_element(values.data(), values.data()+2*N+1);
    STF_EQUAL ( *f1, *f2 );
  }
  {
    std::iota(values.begin(), values.end(),T(1));
    values[0] = T(1000);
    auto f1 = std::min_element(values.begin(), values.end());
    auto f2 = boost::simd::min_element(values.data(), values.data()+2*N+1);
    STF_EQUAL ( *f1, *f2 );
  }
  {
    std::iota(values.begin(), values.end(),T(1));
    values[2*N] = T(0);
    auto f1 = std::min_element(values.begin(), values.end());
    auto f2 = boost::simd::min_element(values.data(), values.data()+2*N+1);
    STF_EQUAL ( *f1, *f2 );
  }
  {
    std::iota(values.begin(), values.end(),T(1));
    values[N] = T(0);
    auto f1 = std::min_element(values.begin(), values.end(), bs::is_greater);
    auto f2 = boost::simd::min_element(values.data(), values.data()+2*N+1, bs::is_greater);
    STF_EQUAL ( *f1, *f2 );
  }
  {
    std::iota(values.begin(), values.end(),T(1));
    values[0] = T(0);
    auto f1 = std::min_element(values.begin(), values.end(), bs::is_greater);
    auto f2 = boost::simd::min_element(values.data(), values.data()+2*N+1, bs::is_greater);
    STF_EQUAL ( *f1, *f2 );
  }
  {
    std::iota(values.begin(), values.end(),T(1));
    values[2*N] = T(0);
    auto f1 = std::min_element(values.begin(), values.end(), bs::is_greater);
    auto f2 = boost::simd::min_element(values.data(), values.data()+2*N+1, bs::is_greater);
    STF_EQUAL ( *f1, *f2 );
  }

}


