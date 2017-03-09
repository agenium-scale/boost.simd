//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/algorithm/transform_reduce.hpp>
#include <boost/align/aligned_allocator.hpp>
#include <numeric>
#include <vector>
#include <simd_test.hpp>

using namespace boost::simd;
using namespace boost::alignment;

STF_CASE_TPL( "Check simd::transform_reduce(f,l,i)", STF_NUMERIC_TYPES )
{
  namespace bs =  boost::simd;
  static const int N = pack<T>::static_size;

  std::vector<T,aligned_allocator<T,pack<T>::alignment>> d(2*N+1), e(2*N+1);
  std::iota(d.begin(), d.end(),T(1));
  std::iota(e.begin(), e.end(),T(1));

  auto s1  = bs::transform_reduce( d.data(), d.data()+2*N, e.data(), bs::multiplies, T(0), bs::plus);
  auto s1s = std::inner_product( d.data(), d.data()+2*N, e.data(), T(0));
  STF_EQUAL(s1, s1s);
  auto s2 =  bs::transform_reduce( d.data()+1, d.data()+2*N+1, e.data()+1, bs::multiplies, T(1), bs::plus);
  auto s2s = std::inner_product( d.data()+1, d.data()+2*N+1, e.data()+1, T(1));
  STF_EQUAL(s2, s2s);

  auto s3  = bs::transform_reduce( d.data()+1, d.data()+2*N+1, e.data(), bs::multiplies, T(0), bs::plus);
  auto s3s = std::inner_product( d.data()+1, d.data()+2*N+1, e.data(), T(0));
  STF_EQUAL(s3, s3s);


}


