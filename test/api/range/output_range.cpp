//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/range/range.hpp>
#include <boost/simd/literal.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/memory/allocator.hpp>
#include <boost/range/algorithm/generate.hpp>
#include <simd_test.hpp>
#include <vector>

using namespace boost::simd::literal;

STF_CASE_TPL("distance", STF_NUMERIC_TYPES)
{
  using boost::simd::range;
  using boost::simd::pack;

  std::vector<T> data(pack<T>::static_size*3);
  std::vector<T> fixed_data(24);

  auto r  = range(data);
  auto rf = range(fixed_data, 8_c);

  STF_EQUAL( std::distance(boost::begin(r), boost::end(r))  , 3);
  STF_EQUAL( std::distance(boost::begin(rf), boost::end(rf)), 3);
}

STF_CASE_TPL("iteration", STF_NUMERIC_TYPES)
{
  using boost::simd::range;
  using boost::simd::pack;

  std::vector<T>  ref (4*pack<T>::static_size);
  std::vector<T>  data(4*pack<T>::static_size);

  for(std::size_t i=0;i<data.size();i++)
    data[i] = T(0);

  auto simd_range = range(data);

  for(std::size_t i=0;i<ref.size();i++)
    ref[i] = T(i/pack<T>::static_size+1);

  T k = 0;
  for(auto&& e : simd_range) e = pack<T>(++k);

  STF_ALL_EQUAL( ref, data );
}
