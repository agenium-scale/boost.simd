//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/range/segmented_range.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <vector>

STF_CASE_TPL("perfect iteration", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::enumerate;
  using boost::simd::segmented_range;

  auto sz = pack<T>::static_size;
  std::vector<T>  data(sz*5);
  std::vector<T>  ref (sz*5);

  for(std::size_t i=0;i<ref.size();++i) ref[i] = i;
  auto pr = segmented_range(data);

  T k = 0;
  for( auto&& pe : pr.head ) pe = k++;
  for( auto&& me : pr.body ) { me = enumerate<pack<T>>(k); k+=sz; }
  for( auto&& ee : pr.tail ) ee = k++;

  STF_EQUAL( std::distance(boost::begin(pr.head),boost::end(pr.head)), 0);
  STF_EQUAL( std::distance(boost::begin(pr.body),boost::end(pr.body)), 5);
  STF_EQUAL( std::distance(boost::begin(pr.tail),boost::end(pr.tail)), 0);
  STF_ALL_EQUAL(ref, data);
}


STF_CASE_TPL("iteration with tail", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::enumerate;
  using boost::simd::segmented_range;

  auto sz = pack<T>::static_size;
  std::vector<T>  base(sz*5-1);
  std::vector<T>  ref(sz*5-1);

  for(std::size_t i=0;i<ref.size();++i) ref[i] = i;

  auto data = boost::make_iterator_range(base.begin(), base.end());
  auto pr   = segmented_range(data);

  T k = 0;
  for( auto&& pe : pr.head ) pe = k++;
  for( auto&& me : pr.body ) { me = enumerate<pack<T>>(k); k+=sz; }
  for( auto&& ee : pr.tail ) ee = k++;

  STF_EQUAL( std::distance(boost::begin(pr.head),boost::end(pr.head)), 0);
  STF_EQUAL( std::distance(boost::begin(pr.body),boost::end(pr.body)), 4);
  STF_EQUAL( std::distance(boost::begin(pr.tail),boost::end(pr.tail)), sz-1);

  STF_ALL_EQUAL(ref, data);
}

STF_CASE_TPL("iteration with tail only", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::enumerate;
  using boost::simd::segmented_range;

  auto sz = pack<T>::static_size;
  std::vector<T>  base(pack<T>::static_size-1);
  std::vector<T>  ref(pack<T>::static_size-1);

  for(std::size_t i=0;i<ref.size();++i) ref[i] = i;

  auto data = boost::make_iterator_range(base.begin(), base.end());
  auto pr   = segmented_range(data);

  T k = 0;
  for( auto&& pe : pr.head ) pe = k++;
  for( auto&& me : pr.body ) { me = enumerate<pack<T>>(k); k+=sz; }
  for( auto&& ee : pr.tail ) ee = k++;

  STF_EQUAL( std::distance(boost::begin(pr.head),boost::end(pr.head)), 0);
  STF_EQUAL( std::distance(boost::begin(pr.body),boost::end(pr.body)), 0);
  STF_EQUAL( std::distance(boost::begin(pr.tail),boost::end(pr.tail)), sz-1);

  STF_ALL_EQUAL(ref, data);
}

