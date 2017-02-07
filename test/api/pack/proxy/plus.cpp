//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <algorithm>
#include <numeric>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env, typename Op>
void test_binop(Env& runtime, Op op)
{
  std::array<T, N> a;
  std::iota(a.begin(), a.end(), T(1));
  bs::pack<T, N> p0(a.begin(), a.end()), ref;

  std::transform(p0.begin(),p0.end(),p0.begin(),ref.begin(), op );
  std::transform(a.begin() ,a.end() ,a.begin() ,a.begin()  , op );
  STF_ALL_EQUAL(ref, a);
}

template <typename T, std::size_t N, typename Env, typename Op>
void test_selfop(Env& runtime, Op op)
{
  std::array<T, N> a;
  std::iota(a.begin(), a.end(), T(1));
  bs::pack<T, N> p0(a.begin(), a.end());

  for(std::size_t i=0;i<N;++i)
  {
    op(p0[i],p0[i]);
    op(a[i] ,a[i]);
  }

  STF_ALL_EQUAL(p0, a);
}

struct op_plus
{
  template<typename T, typename U> void operator()(T&& out, U const& in) const
  {
    std::forward<T>(out) += in;
  }
};

STF_CASE_TPL( "Check proxy + operator" , STF_NUMERIC_TYPES)
{
  std::plus<T> op;
  test_binop<T,  1>(runtime,op);
  test_binop<T,  2>(runtime,op);
  test_binop<T,  4>(runtime,op);
  test_binop<T,  8>(runtime,op);
  test_binop<T, 16>(runtime,op);
  test_binop<T, 32>(runtime,op);
}

STF_CASE_TPL( "Check proxy += operator" , STF_NUMERIC_TYPES)
{
  op_plus op;
  test_selfop<T,  1>(runtime,op);
  test_selfop<T,  2>(runtime,op);
  test_selfop<T,  4>(runtime,op);
  test_selfop<T,  8>(runtime,op);
  test_selfop<T, 16>(runtime,op);
  test_selfop<T, 32>(runtime,op);
}
