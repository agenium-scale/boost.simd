//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/iterator/input_iterator.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/splat.hpp>

#include <simd_test.hpp>

#include <vector>

STF_CASE_TPL("types", STF_NUMERIC_TYPES)
{
  using std::iterator_traits;
  using boost::simd::input_iterator;
  using boost::simd::pack;

  STF_TYPE_IS( typename iterator_traits< input_iterator<T*> >::value_type
                  , (pack<T>)
                  );
}

STF_CASE_TPL("distance", STF_NUMERIC_TYPES)
{
  using std::iterator_traits;
  using boost::simd::input_iterator;
  using boost::simd::input_begin;
  using boost::simd::input_end;
  using boost::simd::pack;

  std::vector<T> data(pack<T>::static_size*3);

  typedef typename std::vector<T>::iterator it_t;

  input_iterator<it_t> b = input_begin(data.begin());
  input_iterator<it_t> e = input_end(data.end());

  STF_EQUAL( std::distance(b,e), 3);
}

STF_CASE_TPL("iteration", STF_NUMERIC_TYPES)
{
  using std::iterator_traits;
  using boost::simd::input_iterator;
  using boost::simd::input_begin;
  using boost::simd::input_end;
  using boost::simd::pack;
  using boost::simd::splat;

  std::vector< pack<T> >  ref(3);
  std::vector<T>          data(pack<T>::static_size*3);

  typedef typename std::vector<T>::iterator it_t;

  for(std::size_t i=0;i<data.size();i++)
    data[i] = i/pack<T>::static_size+1;

  for(std::size_t i=0;i<ref.size();i++)
    ref[i] = splat< pack<T> >(i+1);

  input_iterator<it_t> b = input_begin(data.begin());

  STF_EQUAL( *b++, ref[0] );
  STF_EQUAL( *b++, ref[1] );
  STF_EQUAL( *b++, ref[2] );
}
