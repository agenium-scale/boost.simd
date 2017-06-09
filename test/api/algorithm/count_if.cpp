//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/algorithm/count_if.hpp>
#include <numeric>
#include <vector>
#include <algorithm>
#include <simd_test.hpp>

using namespace boost::simd;
using namespace boost::alignment;


STF_CASE_TPL( "Check unary simd::count_if", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  static const int N = pack<T>::static_size;

  std::vector<T> values(2*N+1);
  std::iota(values.begin(), values.end(),T(1));

  auto c = std::count_if(values.begin(), values.end(), bs::is_odd);

  STF_EQUAL ( (boost::simd::count_if(values.data(), values.data()+2*N+1, bs::is_odd))
            , c
            );

}


