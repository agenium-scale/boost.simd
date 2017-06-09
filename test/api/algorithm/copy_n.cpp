//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy_n at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/algorithm/copy_n.hpp>
#include <numeric>
#include <vector>
#include <simd_test.hpp>

using namespace boost::simd;
using namespace boost::alignment;


STF_CASE_TPL( "Check unary simd::copy_n", STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  std::vector<T> values(2*N+1), ref(2*N+3), out(2*N+3);
  std::iota(values.begin(), values.end(),T(1));

  std::copy(values.begin(), values.begin()+N, ref.begin());

  // verify we stopped where we should
  STF_EQUAL ( (boost::simd::copy_n(values.data(), N, out.data()))
            , out.data()+N
            );

  // verify values
  STF_EQUAL( out, ref );
}


