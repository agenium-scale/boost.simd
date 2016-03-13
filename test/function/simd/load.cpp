//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/load.hpp>
#include <simd_test.hpp>
#include <list>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[3*N];
  std::list<T>l;
  STF_TYPE_IS(p_t, decltype(bs::load<p_t>(&a1[0])));
  STF_TYPE_IS(p_t, decltype(bs::load<p_t>(&a1[0], std::size_t())));

  for(std::size_t i = 0; i < 3*N; ++i){
    a1[i] = T(i);
  }
  for(std::size_t i = 0; i < N; ++i){
    l.push_back(a1[i]);
  }

  p_t aa1(&a1[0], &a1[N]);
  STF_IEEE_EQUAL(bs::load<p_t>(&a1[0]), aa1);
  STF_IEEE_EQUAL(bs::load<p_t>(l.begin(), l.end()), aa1);

  for(std::size_t i=0; i <N ; i++)
  {
    p_t aa2(&a1[N+i], &a1[2*N+i]);
    STF_IEEE_EQUAL(bs::load<p_t>(&a1[0], N+i), aa2);
  }

}

STF_CASE_TPL( "Check load behavior with all types", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = p_t::static_size;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

