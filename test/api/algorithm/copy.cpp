//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/algorithm/copy.hpp>
#include <numeric>
#include <vector>
#include <simd_test.hpp>

using namespace boost::simd;
using namespace boost::alignment;


STF_CASE_TPL( "Check unary simd::copy", STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  std::vector<T> values(2*N+1), ref(2*N+3), out(2*N+3);
  std::iota(values.begin(), values.end(),T(1));

  std::copy(values.begin(), values.end(), ref.begin());

  // verify we stopped where we should
  STF_EQUAL ( (boost::simd::copy(values.data(), values.data()+values.size(), out.data()))
            , out.data()+values.size()
            );

  // verify values
  STF_EQUAL( out, ref );
}


