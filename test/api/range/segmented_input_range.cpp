//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/range/segmented_input_range.hpp>
#include <boost/simd/memory/allocator.hpp>
#include <boost/simd/function/sum.hpp>
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
  using boost::simd::segmented_input_range;

  std::vector<T,boost::simd::allocator<T>>  ref(pack<T>::static_size*3);

  for(std::size_t i=0;i<ref.size();i++) ref[i] = T(1);

  auto pr = segmented_input_range<pack<T>::static_size>(ref);
  T value = 0;
  for( auto& pe : std::get<0>(pr) ) value += pe;
  for( auto& me : std::get<1>(pr) ) value += boost::simd::sum(me);
  for( auto& ee : std::get<2>(pr) ) value += ee;

  STF_EQUAL(std::distance(std::begin(std::get<0>(pr)),std::end(std::get<0>(pr))), 0 );
  STF_EQUAL(std::distance(std::begin(std::get<2>(pr)),std::end(std::get<2>(pr))), 0 );

  STF_EQUAL(value, T(ref.size()) );
}

STF_CASE_TPL("iteration with prologue", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_input_range;

  std::vector<T,boost::simd::allocator<T>> ref(pack<T>::static_size*3+pack<T>::alignment/sizeof(T));

  if (is_not_unalignable<T>($)) return;

  for(std::size_t i=0;i<ref.size();i++) ref[i] = T(1);

  auto data = boost::make_iterator_range(ref.data()+1, ref.data()+ref.size());
  auto pr = segmented_input_range<pack<T>::static_size>(data);

  T value = 0;
  for( auto& pe : std::get<0>(pr) ) value += pe;
  for( auto& me : std::get<1>(pr) ) value += boost::simd::sum(me);
  for( auto& ee : std::get<2>(pr) ) value += ee;

  STF_EQUAL(std::distance(std::begin(std::get<2>(pr)),std::end(std::get<2>(pr))), 0 );
  STF_EQUAL(value, T(ref.size()-1) );
}

STF_CASE_TPL("iteration with epilogue", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_input_range;

  std::vector<T,boost::simd::allocator<T>>  ref(pack<T>::static_size*3);

  for(std::size_t i=0;i<ref.size();i++) ref[i] = T(1);

  auto data = boost::make_iterator_range(ref.data(), ref.data()+ref.size()-1);
  auto pr = segmented_input_range<pack<T>::static_size>(data);

  T value = 0;
  for( auto& pe : std::get<0>(pr) ) value += pe;
  for( auto& me : std::get<1>(pr) ) value += boost::simd::sum(me);
  for( auto& ee : std::get<2>(pr) ) value += ee;

  STF_EQUAL(std::distance(std::begin(std::get<0>(pr)),std::end(std::get<0>(pr))), 0 );
  STF_EQUAL(value, T(ref.size()-1) );
}

STF_CASE_TPL("iteration with epilogue & prologue", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_input_range;

  std::vector<T,boost::simd::allocator<T>>  ref(pack<T>::static_size*3);

  for(std::size_t i=0;i<ref.size();i++) ref[i] = T(1);

  auto data = boost::make_iterator_range(ref.data()+1, ref.data()+ref.size()-1);
  auto pr = segmented_input_range<pack<T>::static_size>(data);

  T value = 0;
  for( auto& pe : std::get<0>(pr) ) value += pe;
  for( auto& me : std::get<1>(pr) ) value += boost::simd::sum(me);
  for( auto& ee : std::get<2>(pr) ) value += ee;

  STF_EQUAL(value, T(ref.size()-2) );
}

STF_CASE_TPL("iteration with only epilogue & prologue", STF_NUMERIC_TYPES)
{
  using boost::simd::pack;
  using boost::simd::segmented_input_range;

  std::vector<T,boost::simd::allocator<T>>  ref(pack<T>::static_size*2);

  for(std::size_t i=0;i<ref.size();i++) ref[i] = T(1);

  auto data = boost::make_iterator_range(ref.data()+1, ref.data()+pack<T>::static_size-1);
  auto pr = segmented_input_range<pack<T>::static_size>(data);

  T value = 0;
  for( auto& pe : std::get<0>(pr) ) value += pe;
  for( auto& ee : std::get<2>(pr) ) value += ee;

  STF_EQUAL(std::distance(std::begin(std::get<1>(pr)),std::end(std::get<1>(pr))), 0);
  STF_EQUAL(value, T(std::distance(std::begin(data),std::end(data))) );
}
