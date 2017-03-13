//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/algorithm/count.hpp>
#include <numeric>
#include <vector>
#include <numeric>
#include <simd_test.hpp>

using namespace boost::simd;
using namespace boost::alignment;


STF_CASE_TPL( "Check unary simd::count", STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  std::vector<T> values(2*N+1);
  std::iota(values.begin(), values.end(),T(1));

  auto c = std::count(values.begin(), values.end(), T(5));

  STF_EQUAL ( (boost::simd::count(values.data(), values.data()+2*N+1, T(5)))
            , c
            );

}


