//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/iterator/realigned_output_range.hpp>
#include <boost/align/aligned_allocator.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/range/algorithm/generate.hpp>

#include <simd_test.hpp>

#include <vector>

template <typename T>
using allocator = boost::alignment::aligned_allocator<T>;

STF_CASE_TPL("distance", STF_NUMERIC_TYPES)
{
  using std::iterator_traits;
  using boost::simd::realigned_output_range;
  using boost::simd::pack;

  // Take soemthign aligned and chirurgically unalign it
  std::vector<T, allocator<T> > data(pack<T>::static_size*4);
  typedef boost::iterator_range<typename std::vector<T, allocator<T> >::iterator> r_t;

  {
    STF_EQUAL( std::distance ( boost::begin(realigned_output_range(data))
                                  , boost::end  (realigned_output_range(data))
                                  )
                  , 4
                  );
  }

  {
    r_t r = boost::make_iterator_range( data.begin() + 1, data.end() );

    STF_EQUAL( std::distance ( boost::begin(realigned_output_range(r))
                                  , boost::end  (realigned_output_range(r))
                                  )
                  , 3
                  );
  }

  {
    r_t r = boost::make_iterator_range( data.begin(), data.end() -1 );

    STF_EQUAL( std::distance ( boost::begin(realigned_output_range(r))
                                  , boost::end  (realigned_output_range(r))
                                  )
                  , 3
                  );
  }

  {
    r_t r = boost::make_iterator_range( data.begin() + 1, data.end() -1 );

    STF_EQUAL( std::distance ( boost::begin(realigned_output_range(r))
                                  , boost::end  (realigned_output_range(r))
                                  )
                  , 2
                  );
  }
}

template<class T> struct generate
{
  generate(T v) : value(v) {}
  boost::simd::pack<T> operator()() const
  {
    return boost::simd::splat< boost::simd::pack<T> >(value++);
  }

  private:
  mutable T value;
};

STF_CASE_TPL("iteration", STF_NUMERIC_TYPES)
{
  using std::iterator_traits;
  using boost::simd::realigned_output_range;
  using boost::simd::aligned_output_iterator;
  using boost::simd::pack;

  std::size_t ps = pack<T>::static_size;
  std::vector<T, allocator<T> >  ref (4*ps-1);
  std::vector<T, allocator<T> >  data(4*ps-1);

  typedef typename std::vector<T, allocator<T> >::iterator it_t;

  boost::iterator_range<aligned_output_iterator<it_t> > r = realigned_output_range(data);

  for(std::size_t i=0;i<data.size();i++)
    data[i] = T(0);

  for(std::size_t i=0;i<boost::size(r)*ps;i++)
    ref[i] = T(i/pack<T>::static_size+1);

  for(std::size_t i=boost::size(r)*ps;i<ref.size();i++)
    ref[i] = T(0);

  boost::generate( r, generate<T>(1));

  STF_EQUAL( ref, data );
}
