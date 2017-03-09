//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/algorithm/reduce.hpp>
#include <boost/align/aligned_allocator.hpp>
#include <numeric>
#include <vector>
#include <simd_test.hpp>

using namespace boost::simd;
using namespace boost::alignment;

STF_CASE_TPL( "Check simd::reduce(f,l,i)", STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  std::vector<T,aligned_allocator<T,pack<T>::alignment>> values(2*N);
  std::iota(values.begin(), values.end(),T(0));

  auto ab = values.data();
  auto ae = values.data()+values.size();

  // All aligned
  STF_EQUAL ( (std::accumulate(values.begin(), values.end(), T(3)))
            , (boost::simd::reduce(ab,ae, T(3)))
            );

  // prologue + aligned
  STF_EQUAL ( (std::accumulate(values.begin()+1, values.end(), T(3)))
            , (boost::simd::reduce(ab+1,ae, T(3)))
            );

  // aligned + epilogue
  STF_EQUAL ( (std::accumulate(values.begin(), values.end()-1, T(3)))
            , (boost::simd::reduce(ab,ae-1, T(3)))
            );

  // prologue + epilogue
  STF_EQUAL ( (std::accumulate(values.begin(), values.end()-1, T(3)))
            , (boost::simd::reduce(ab+1,ae-1, T(3)))
            );
}

struct fake_sum
{
  template<typename T> T operator()(T const& a, T const& e) { return a + e; }
};

STF_CASE_TPL( "Check simd::reduce(f,l,i,f)", STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  std::vector<T,aligned_allocator<T,pack<T>::alignment>> values(2*N);
  std::iota(values.begin(), values.end(),T(0));

  STF_EQUAL ( (std::accumulate(values.begin(), values.end(), T(3), fake_sum{}))
            , (boost::simd::reduce( values.data(), values.data()+values.size()
                                  , T(3)
                                  , fake_sum{}
                                  )
              )
            );

}

