//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/range/segmented_aligned_range.hpp>
#include <boost/simd/memory/allocator.hpp>
#include <boost/simd/function/sum.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <vector>

template <typename T, typename Env>
bool is_not_unalignable(Env& runtime)
{
  // If alignment == sizeof(T) then moving data() by 1 won't change memory alignment, then if the
  // memory passed to segmented_aligned_*_range is already aligned to pack<T>::alignment, prologue will
  // be skiped.
  if (boost::simd::pack<T>::alignment == sizeof(T)) {
    STF_PASS("Data is not unalignable");
    return true;
  }
  return false;
}

STF_CASE_TPL("perfect iteration", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_aligned_range;

  std::vector<T,boost::simd::allocator<T>>  ref(pack<T>::static_size*3);

  for(std::size_t i=0;i<ref.size();i++) ref[i] = T(1);

  auto pr = segmented_aligned_range(ref);
  T value = 0;
  for( auto&& pe : pr.head ) value += pe;
  for( auto&& me : pr.body ) value += boost::simd::sum(me);
  for( auto&& ee : pr.tail ) value += ee;

  STF_EQUAL(std::distance(boost::begin(pr.head),boost::end(pr.head)), 0 );
  STF_EQUAL(std::distance(boost::begin(pr.tail),boost::end(pr.tail)), 0 );

  STF_EQUAL(value, T(ref.size()) );
}

STF_CASE_TPL("iteration with prologue", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_aligned_range;

  std::vector<T,boost::simd::allocator<T>> ref(pack<T>::static_size*3+pack<T>::alignment/sizeof(T));

  if (is_not_unalignable<T>(runtime)) return;

  for(std::size_t i=0;i<ref.size();i++) ref[i] = T(1);

  auto data = boost::make_iterator_range(ref.data()+1, ref.data()+ref.size());
  auto pr = segmented_aligned_range(data);

  T value = 0;
  for( auto&& pe : pr.head ) value += pe;
  for( auto&& me : pr.body ) value += boost::simd::sum(me);
  for( auto&& ee : pr.tail ) value += ee;

  STF_EQUAL(std::distance(boost::begin(pr.tail),boost::end(pr.tail)), 0 );
  STF_EQUAL(value, T(ref.size()-1) );
}

STF_CASE_TPL("iteration with epilogue", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_aligned_range;

  std::vector<T,boost::simd::allocator<T>>  ref(pack<T>::static_size*3);

  for(std::size_t i=0;i<ref.size();i++) ref[i] = T(1);

  auto data = boost::make_iterator_range(ref.data(), ref.data()+ref.size()-1);
  auto pr = segmented_aligned_range(data);

  T value = 0;
  for( auto&& pe : pr.head ) value += pe;
  for( auto&& me : pr.body ) value += boost::simd::sum(me);
  for( auto&& ee : pr.tail ) value += ee;

  STF_EQUAL(std::distance(boost::begin(pr.head),boost::end(pr.head)), 0 );
  STF_EQUAL(value, T(ref.size()-1) );
}

STF_CASE_TPL("iteration with epilogue & prologue", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_aligned_range;

  std::vector<T,boost::simd::allocator<T>>  ref(pack<T>::static_size*3);

  for(std::size_t i=0;i<ref.size();i++) ref[i] = T(1);

  auto data = boost::make_iterator_range(ref.data()+1, ref.data()+ref.size()-1);
  auto pr = segmented_aligned_range(data);

  T value = 0;
  for( auto&& pe : pr.head ) value += pe;
  for( auto&& me : pr.body ) value += boost::simd::sum(me);
  for( auto&& ee : pr.tail ) value += ee;

  STF_EQUAL(value, T(ref.size()-2) );
}

STF_CASE_TPL("iteration with only epilogue & prologue", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_aligned_range;

  std::vector<T,boost::simd::allocator<T>>  ref(pack<T>::static_size*2);

  for(std::size_t i=0;i<ref.size();i++) ref[i] = T(1);

  auto data = boost::make_iterator_range(ref.data()+1, ref.data()+pack<T>::static_size-1);
  auto pr = segmented_aligned_range(data);

  T value = 0;
  for( auto&& pe : pr.head ) value += pe;
  for( auto&& ee : pr.tail ) value += ee;

  STF_EQUAL(std::distance(boost::begin(pr.body),boost::end(pr.body)), 0);
  STF_EQUAL(value, T(std::distance(boost::begin(data),boost::end(data))) );
}
