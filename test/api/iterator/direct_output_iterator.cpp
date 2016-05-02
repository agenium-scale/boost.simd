//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/iterator/direct_output_iterator.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/align/aligned_allocator.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <vector>

template <typename T>
using allocator = boost::alignment::aligned_allocator<T>;

STF_CASE_TPL("types", STF_NUMERIC_TYPES)
{
  using std::iterator_traits;
  using boost::simd::direct_output_iterator;
  using boost::simd::pack;

  STF_TYPE_IS( typename iterator_traits< direct_output_iterator<T*> >::value_type
                  , (pack<T>)
                  );
}

STF_CASE_TPL("distance", STF_NUMERIC_TYPES)
{
  using std::iterator_traits;
  using boost::simd::direct_output_iterator;
  using boost::simd::direct_output_begin;
  using boost::simd::direct_output_end;
  using boost::simd::pack;

  std::vector<T,allocator<T> > data(pack<T>::static_size*3);
  typedef typename std::vector<T,allocator<T> >::iterator it_t;

  direct_output_iterator<it_t> b = direct_output_begin(data.begin());
  direct_output_iterator<it_t> e = direct_output_end(data.end());

  STF_EQUAL( std::distance(b,e), 3);
}

STF_CASE_TPL("iteration", STF_NUMERIC_TYPES)
{
  using std::iterator_traits;
  using boost::simd::direct_output_iterator;
  using boost::simd::direct_output_begin;
  using boost::simd::direct_output_end;
  using boost::simd::pack;
  using boost::simd::splat;

  std::vector<T,allocator<T> > ref(pack<T>::static_size*3);
  std::vector<T,allocator<T> > data(pack<T>::static_size*3);

  typedef typename std::vector<T,allocator<T> >::iterator it_t;

  for(std::size_t i=0;i<ref.size();i++)
    ref[i] = (i/pack<T>::static_size)+1;

  direct_output_iterator<it_t> b = direct_output_begin(data.begin());
  direct_output_iterator<it_t> e = direct_output_end(data.end());

  int i=0;
  while(b != e)
    *b++ = splat< pack<T> >(++i);

  STF_EQUAL( data, ref );
}
