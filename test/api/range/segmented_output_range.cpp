//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/range/segmented_output_range.hpp>
#include <boost/simd/memory/allocator.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <vector>

template <typename T, typename Env>
bool is_not_unalignable(Env& $)
{
  // If alignment == sizeof(T) then moving data() by 1 won't change memory alignment, then if the
  // memory passed to segmented_*_range is already aligned to pack<T>::alignment, prologue will
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
  using boost::simd::segmented_output_range;

  std::vector<T,boost::simd::allocator<T>>  data(pack<T>::static_size*5);
  std::vector<T,boost::simd::allocator<T>>  ref (pack<T>::static_size*5);

  for(std::size_t i=0;i<data.size();i++) ref[i] = i/pack<T>::static_size+1;
  auto pr = segmented_output_range(data);

  T k = 0;
  for( auto& pe : std::get<0>(pr) ) pe = ++k;
  for( auto& me : std::get<1>(pr) ) me = pack<T>(++k);
  for( auto& ee : std::get<2>(pr) ) ee = ++k;

  STF_EQUAL( std::distance(std::begin(std::get<0>(pr)),std::end(std::get<0>(pr))), 0);
  STF_EQUAL( std::distance(std::begin(std::get<2>(pr)),std::end(std::get<2>(pr))), 0);
  STF_ALL_EQUAL(ref, data);
}

STF_CASE_TPL("iteration with prologue", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_output_range;

  std::vector<T,boost::simd::allocator<T>>  base(pack<T>::static_size*5);
  std::vector<T,boost::simd::allocator<T>>  ref(pack<T>::static_size*5-1);

  if (is_not_unalignable<T>($)) return;

  T v = 0;
  std::size_t l0 = pack<T>::static_size-1;

  for(std::size_t i=0 ;i<l0        ;i++) ref[i] = ++v;
  for(std::size_t i=l0;i<ref.size();i+=pack<T>::static_size)
  {
    ++v;
    for(std::size_t j=0;j<pack<T>::static_size;j++) ref[i+j] = v;
  }

  auto data = boost::make_iterator_range(base.data()+1, base.data()+base.size());
  auto pr   = segmented_output_range(data);

  T k = 0;

  for( auto& pe : std::get<0>(pr) ) pe = ++k;
  for( auto& me : std::get<1>(pr) ) me = pack<T>(++k);
  for( auto& ee : std::get<2>(pr) ) ee = ++k;

  STF_EQUAL( std::distance(std::begin(std::get<2>(pr)),std::end(std::get<2>(pr))), 0);
  STF_ALL_EQUAL(ref, data);
}

STF_CASE_TPL("iteration with epilogue", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_output_range;

  std::vector<T,boost::simd::allocator<T>>  base(pack<T>::static_size*5);
  std::vector<T,boost::simd::allocator<T>>  ref(pack<T>::static_size*5-1);

  T v = 0;
  std::size_t l0 = pack<T>::static_size-1;

  for(std::size_t i=0;i<ref.size()-l0;i+=pack<T>::static_size)
  {
    ++v;
    for(std::size_t j=0;j<pack<T>::static_size;j++) ref[i+j] = v;
  }
  for(std::size_t i=ref.size()-l0;i<ref.size();i++) ref[i] = ++v;

  auto data = boost::make_iterator_range(base.data(), base.data()+base.size()-1);
  auto pr   = segmented_output_range(data);

  T k = 0;
  for( auto& pe : std::get<0>(pr) ) pe = ++k;
  for( auto& me : std::get<1>(pr) ) me = pack<T>(++k);
  for( auto& ee : std::get<2>(pr) ) ee = ++k;

  STF_EQUAL( std::distance(std::begin(std::get<0>(pr)),std::end(std::get<0>(pr))), 0);
  STF_ALL_EQUAL(ref, data);
}

STF_CASE_TPL("iteration with epilogue & prologue", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_output_range;

  std::vector<T,boost::simd::allocator<T>>  base(pack<T>::static_size*5);
  std::vector<T,boost::simd::allocator<T>>  ref(pack<T>::static_size*5-2);

  if (is_not_unalignable<T>($)) return;

  T v = 0;
  std::size_t l0 = pack<T>::static_size-1;
  for(std::size_t i=0;i<l0;i++) ref[i] = ++v;
  for(std::size_t i=l0;i<ref.size()-l0;i+=pack<T>::static_size)
  {
    ++v;
    for(std::size_t j=0;j<pack<T>::static_size;j++) ref[i+j] = v;
  }
  for(std::size_t i=ref.size()-l0;i<ref.size();i++) ref[i] = ++v;

  auto data = boost::make_iterator_range(base.data()+1, base.data()+base.size()-1);
  auto pr   = segmented_output_range(data);

  T k = 0;
  for( auto& pe : std::get<0>(pr) ) pe = ++k;
  for( auto& me : std::get<1>(pr) ) me = pack<T>(++k);
  for( auto& ee : std::get<2>(pr) ) ee = ++k;

  STF_EXPECT( std::distance(std::begin(std::get<0>(pr)),std::end(std::get<0>(pr))) != 0);
  STF_EXPECT( std::distance(std::begin(std::get<2>(pr)),std::end(std::get<2>(pr))) != 0);
  STF_ALL_EQUAL(ref, data);
}
