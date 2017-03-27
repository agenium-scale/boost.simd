//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/algorithm/iota.hpp>
#include <boost/simd/pack.hpp>
#include <numeric>
#include <vector>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Check unary simd::iota", (float)) // STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  std::vector<T> values(2*N+1), ref(2*N+1);
  std::iota(ref.begin(), ref.end(), T(3));

  boost::simd::iota(values.data(), values.data()+values.size(), T(3));

  STF_EQUAL( values, ref );
}
