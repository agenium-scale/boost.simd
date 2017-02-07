//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/bits.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(0) : T(2*i);
    b[i] = bs::genmask(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::genmask(aa1), bb);
}

STF_CASE_TPL("Check genmask on pack" , STF_SIGNED_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
// TODO when if_else_zero is available
#if 0
STF_CASE_TPL ("Check genmask behavior when re-targeted",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::genmask;
  static const std::size_t N = bs::pack<T>::static_size;

  STF_TYPE_IS ( decltype(bs::genmask<bs::pack<char,N*sizeof(T)>>(bs::pack<T,N>()))
              , (bs::pack<char,N*sizeof(T)>)
              );
  STF_TYPE_IS ( decltype(bs::genmask<bs::pack<char,(N*sizeof(T))/2>>(bs::pack<T,N>()))
              , (bs::pack<char,(N*sizeof(T))/2>)
              );
  STF_TYPE_IS ( decltype(bs::genmask<bs::pack<char,N*sizeof(T)*2>>(bs::pack<T,N>()))
              , (bs::pack<char,N*sizeof(T)*2>)
              );

  STF_EQUAL ( (genmask<bs::pack<char,N*sizeof(T)>>(bs::pack<T,N>(42)))
            , (bs::Allbits<bs::pack<char,N*sizeof(T)>>())
            );

  // STF_EQUAL(genmask<bs::pack<char,N*sizeof(T)>>(T(0)) , char(0));
}
#endif

#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>

STF_CASE_TPL ("Check genmask behavior on IEEE754 special values",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::genmask;
  static const std::size_t N = bs::pack<T>::static_size;

  STF_IEEE_EQUAL(genmask(bs::Inf <bs::pack<T,N>>()) , (bs::Allbits<bs::pack<T,N>>()) );
  STF_IEEE_EQUAL(genmask(bs::Minf<bs::pack<T,N>>()) , (bs::Allbits<bs::pack<T,N>>()) );
  STF_IEEE_EQUAL(genmask(bs::Nan <bs::pack<T,N>>()) , (bs::Allbits<bs::pack<T,N>>()) );

  STF_IEEE_EQUAL(genmask(bs::Inf <bs::pack<T,N/2>>()) , (bs::Allbits<bs::pack<T,N/2>>()) );
  STF_IEEE_EQUAL(genmask(bs::Minf<bs::pack<T,N/2>>()) , (bs::Allbits<bs::pack<T,N/2>>()) );
  STF_IEEE_EQUAL(genmask(bs::Nan <bs::pack<T,N/2>>()) , (bs::Allbits<bs::pack<T,N/2>>()) );

  STF_IEEE_EQUAL(genmask(bs::Inf <bs::pack<T,N*2>>()) , (bs::Allbits<bs::pack<T,N*2>>()) );
  STF_IEEE_EQUAL(genmask(bs::Minf<bs::pack<T,N*2>>()) , (bs::Allbits<bs::pack<T,N*2>>()) );
  STF_IEEE_EQUAL(genmask(bs::Nan <bs::pack<T,N*2>>()) , (bs::Allbits<bs::pack<T,N*2>>()) );
}
#endif

