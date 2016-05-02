//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/iterator/input_range.hpp>
#include <boost/simd/pack.hpp>
#include <boost/align/aligned_allocator.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/range.hpp>

#include <simd_test.hpp>

#include <vector>

template <typename T>
using allocator = boost::alignment::aligned_allocator<T>;

template<typename Range, typename Out>
inline Out mycopy(Range const& r, Out dst)
{
  typedef typename std::iterator_traits<Out>::value_type T;
  typedef typename boost::range_iterator<Range>::type it_t;

  it_t begin = boost::begin(r);
  it_t end = boost::end(r);

  for(; begin != end; ++begin) *dst++ = T(*begin);

  return dst;
}

STF_CASE_TPL("distance", STF_NUMERIC_TYPES)
{
  using std::iterator_traits;
  using boost::simd::input_range;
  using boost::simd::pack;

  std::vector<T> data(pack<T>::static_size*3);

  STF_EQUAL( std::distance ( boost::begin(input_range(data))
                                , boost::end(input_range(data))
                                )
                , 3
                );

  std::vector<T> fixed_data(24);

  STF_EQUAL( std::distance ( boost::begin(input_range<8>(fixed_data))
                                , boost::end  (input_range<8>(fixed_data))
                                )
                , 3
                );
}

/* Uncomment when STF_ASSERT is implemented
STF_CASE_TPL("size_check", STF_NUMERIC_TYPES)
{
  using std::iterator_traits;
  using boost::simd::input_range;
  using boost::simd::pack;
  using boost::begin;
  using boost::end;

  std::vector<T> data(pack<T>::static_size*3-1);
  STF_ASSERT( input_range(data) );

  std::vector<T> fixed_data(3*8-1);
  STF_ASSERT( input_range<8>(data) );
}
*/

STF_CASE_TPL("iteration", STF_NUMERIC_TYPES)
{
  using std::iterator_traits;
  using boost::simd::input_range;
  using boost::simd::pack;
  using boost::simd::splat;
  using boost::begin;
  using boost::end;

  std::vector< pack<T> > dst(3);
  std::vector< pack<T> > ref(3);

  std::vector<T>  data(pack<T>::static_size*3);

  for(std::size_t i=0;i<data.size();i++)
    data[i] = i/pack<T>::static_size+1;

  for(std::size_t i=0;i<ref.size();i++)
    ref[i] = splat< pack<T> >(i+1);

  mycopy( input_range(data), dst.begin());

  for ( std::size_t i = 0 ; i < ref.size() ; ++i )
    STF_EQUAL( ref[i], dst[i] );
}
