//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/interleave_even.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace tt = nsm::type_traits;

template <typename T, int N, typename Env>
void test(Env&, tt::false_type const&)
{}

template <typename T, int N, typename Env>
void test(Env& runtime, tt::true_type const& = {})
{
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N], b[N];

  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    a2[i] = (i%2) ? T(i+N) : T(-(i+N));
  }

  for(std::size_t i = 0; i < N; ++i)
  {
    b[i] = (i%2) ? a2[2*(i/2)] : a1[2*(i/2)];
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);

  STF_EQUAL(bs::interleave_even(aa1, aa2), bb);
}

STF_CASE_TPL("Check interleave_even on pack", STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N  >(runtime, nsm::bool_<(N>1)>());
  test<T, N/2>(runtime, nsm::bool_<(N>2)>());
  test<T, N*2>(runtime);
}
