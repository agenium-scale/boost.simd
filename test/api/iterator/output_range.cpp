//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/iterator/output_range.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/range/algorithm/generate.hpp>
#include <simd_test.hpp>
#include <vector>

STF_CASE_TPL("distance", STF_NUMERIC_TYPES)
{
  using boost::simd::output_range;
  using boost::simd::pack;

  std::vector<T> data(pack<T>::static_size*3);
  std::vector<T> fixed_data(24);

  auto r  = output_range(data);
  auto rf = output_range<8>(fixed_data);

  STF_EQUAL( std::distance(std::begin(r), std::end(r))  , 3);
  STF_EQUAL( std::distance(std::begin(rf), std::end(rf)), 3);
}

template<class T> struct generate
{
  generate(T v) : value(v) {}
  boost::simd::pack<T> operator()() const
  {
    return boost::simd::pack<T>(value++);
  }

  private:
  mutable T value;
};

STF_CASE_TPL("iteration", STF_NUMERIC_TYPES)
{
  using boost::simd::output_range;
  using boost::simd::pack;

  std::vector<T>  ref (4*pack<T>::static_size);
  std::vector<T>  data(4*pack<T>::static_size);

  auto r = output_range(data);

  for(std::size_t i=0;i<data.size();i++)
    data[i] = T(0);

  for(std::size_t i=0;i<ref.size();i++)
    ref[i] = T(i/pack<T>::static_size+1);

  boost::generate( r, generate<T>(1));

  STF_ALL_EQUAL( ref, data );
}
