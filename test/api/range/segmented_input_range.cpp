//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/range/segmented_range.hpp>
#include <boost/simd/function/sum.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <vector>

STF_CASE_TPL("perfect iteration", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_range;

  std::vector<T>  ref(pack<T>::static_size*3);

  for(std::size_t i=0;i<ref.size();i++) ref[i] = T(1);

  auto pr = segmented_range(ref);
  T value = 0;

  for( auto&& pe : pr.head ) value += pe;
  for( auto&& me : pr.body ) value += boost::simd::sum(me);
  for( auto&& ee : pr.tail ) value += ee;

  STF_EQUAL(std::distance(boost::begin(pr.head),boost::end(pr.head)), 0 );
  STF_EQUAL(std::distance(boost::begin(pr.body),boost::end(pr.body)), 3 );
  STF_EQUAL(std::distance(boost::begin(pr.tail),boost::end(pr.tail)), 0 );

  STF_EQUAL(value, T(ref.size()) );
}

STF_CASE_TPL("iteration with tail",STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_range;

  std::vector<T>  ref(pack<T>::static_size*3);

  for(std::size_t i=0;i<ref.size();i++) ref[i] = T(1);

  auto pr = segmented_range(ref.begin(), ref.begin()+ref.size() - 1);
  T value = 0;

  for( auto&& pe : pr.head ) value += pe;
  for( auto&& me : pr.body ) value += boost::simd::sum(me);
  for( auto&& ee : pr.tail ) value += ee;

  STF_EQUAL(std::distance(boost::begin(pr.head),boost::end(pr.head)), 0 );
  STF_EQUAL(std::distance(boost::begin(pr.body),boost::end(pr.body)), 2 );
  STF_EQUAL(std::distance(boost::begin(pr.tail),boost::end(pr.tail)), pack<T>::static_size - 1 );

  STF_EQUAL(value, T(ref.size())-1 );
}

STF_CASE_TPL("iteration with tail only", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_range;

  std::vector<T>  ref(pack<T>::static_size-1);

  for(std::size_t i=0;i<ref.size();i++) ref[i] = T(1);

  auto pr = segmented_range(ref.begin(), ref.end());
  T value = 0;

  for( auto&& pe : pr.head ) value += pe;
  for( auto&& me : pr.body ) value += boost::simd::sum(me);
  for( auto&& ee : pr.tail ) value += ee;

  STF_EQUAL(std::distance(boost::begin(pr.head),boost::end(pr.head)), 0 );
  STF_EQUAL(std::distance(boost::begin(pr.body),boost::end(pr.body)), 0 );
  STF_EQUAL(std::distance(boost::begin(pr.tail),boost::end(pr.tail)), pack<T>::static_size - 1 );

  STF_EQUAL(value, T(ref.size()) );
}

