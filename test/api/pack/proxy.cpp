//==================================================================================================
/*
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <algorithm>
#include <numeric>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test_cast(Env& $)
{
  std::array<T, N> a;
  std::iota(a.begin(), a.end(), T(1));
  bs::pack<T, N> p0(a.begin(), a.end()), ref;

  std::transform(p0.begin(),p0.end(),ref.begin(), [](T e) { return e; } );
  STF_EXPECT(( std::equal(ref.begin(),ref.end(), a.begin()) ));
}

template <typename T, std::size_t N, typename Env>
void test_is_equal(Env& $)
{
  std::array<T, N> a;
  std::iota(a.begin(), a.end(), T(1));
  bs::pack<T, N> p(a.begin(), a.end());

  STF_EXPECT(( std::all_of(p.begin() , p.end(), [](T e) { return e == e; } ) ));
}

template <typename T, std::size_t N, typename Env>
void test_not_equal(Env& $)
{
  std::array<T, N> a;
  std::iota(a.begin(), a.end(), T(1));
  bs::pack<T, N> p(a.begin(), a.end());

  STF_EXPECT(( std::none_of(p.begin() , p.end(), [](T e) { return e != e; } ) ));
}

template <typename T, std::size_t N, typename Env>
void test_not(Env& $)
{
  std::array<T, N> a;
  std::iota(a.begin(), a.end(), T(1));
  bs::pack<T, N> p0(a.begin(), a.end()), ref(a.begin(), a.end());

  bool supports_logical_not = true;
  for (auto it0 = p0.begin(); it0 != p0.end(); ++it0)
    supports_logical_not = supports_logical_not && !(!(*it0));

  STF_EXPECT( supports_logical_not );
}

template <typename T, std::size_t N, typename Env, typename Op>
void test_binop(Env& $, Op op)
{
  std::array<T, N> a;
  std::iota(a.begin(), a.end(), T(1));
  bs::pack<T, N> p0(a.begin(), a.end()), ref;

  std::transform(p0.begin(),p0.end(),p0.begin(),ref.begin(), op );
  std::transform(a.begin() ,a.end() ,a.begin() ,a.begin()  , op );
  STF_EXPECT(( std::equal(ref.begin(),ref.end(), a.begin()) ));
}

template <typename T, std::size_t N, typename Env, typename Op>
void test_selfop(Env& $, Op op)
{
  std::array<T, N> a;
  std::iota(a.begin(), a.end(), T(1));
  bs::pack<T, N> p0(a.begin(), a.end());

  for(std::size_t i=0;i<N;++i)
  {
    op(p0[i],p0[i]);
    op(a[i] ,a[i]);
  }

  STF_EXPECT(( std::equal(p0.begin(),p0.end(), a.begin()) ));
}

STF_CASE_TPL( "Check proxy access" , STF_NUMERIC_TYPES)
{
  test_cast<T,  2>($);
  test_cast<T,  4>($);
  test_cast<T,  8>($);
  test_cast<T, 16>($);
  test_cast<T, 32>($);
}

STF_CASE_TPL( "Check proxy comparison" , STF_NUMERIC_TYPES)
{
  test_is_equal<T,  2>($);
  test_is_equal<T,  4>($);
  test_is_equal<T,  8>($);
  test_is_equal<T, 16>($);
  test_is_equal<T, 32>($);
}

STF_CASE_TPL( "Check proxy non equal comparison" , STF_NUMERIC_TYPES)
{
  test_not_equal<T,  2>($);
  test_not_equal<T,  4>($);
  test_not_equal<T,  8>($);
  test_not_equal<T, 16>($);
  test_not_equal<T, 32>($);
}

STF_CASE_TPL( "Check proxy bitwise negation" , STF_NUMERIC_TYPES)
{
  test_not<T,  2>($);
  test_not<T,  4>($);
  test_not<T,  8>($);
  test_not<T, 16>($);
  test_not<T, 32>($);
}

STF_CASE_TPL( "Check proxy + operator" , STF_NUMERIC_TYPES)
{
  std::plus<T> op;
  test_binop<T,  2>($,op);
  test_binop<T,  4>($,op);
  test_binop<T,  8>($,op);
  test_binop<T, 16>($,op);
  test_binop<T, 32>($,op);
}

STF_CASE_TPL( "Check proxy - operator" , STF_NUMERIC_TYPES)
{
  std::minus<T> op;
  test_binop<T,  2>($,op);
  test_binop<T,  4>($,op);
  test_binop<T,  8>($,op);
  test_binop<T, 16>($,op);
  test_binop<T, 32>($,op);
}

STF_CASE_TPL( "Check proxy * operator" , STF_NUMERIC_TYPES)
{
  std::multiplies<T> op;
  test_binop<T,  2>($,op);
  test_binop<T,  4>($,op);
  test_binop<T,  8>($,op);
  test_binop<T, 16>($,op);
  test_binop<T, 32>($,op);
}

STF_CASE_TPL( "Check proxy / operator" , STF_NUMERIC_TYPES)
{
  std::divides<T> op;
  test_binop<T,  2>($,op);
  test_binop<T,  4>($,op);
  test_binop<T,  8>($,op);
  test_binop<T, 16>($,op);
  test_binop<T, 32>($,op);
}

struct op_plus
{
  template<typename T, typename U> void operator()(T&& out, U const& in) const
  {
    std::forward<T>(out) += in;
  }
};

struct op_minus
{
  template<typename T, typename U> void operator()(T&& out, U const& in) const
  {
    std::forward<T>(out) -= in;
  }
};

struct op_times
{
  template<typename T, typename U> void operator()(T&& out, U const& in) const
  {
    std::forward<T>(out) *= in;
  }
};

struct op_divides
{
  template<typename T, typename U> void operator()(T&& out, U const& in) const
  {
    std::forward<T>(out) /= in;
  }
};

STF_CASE_TPL( "Check proxy += operator" , STF_NUMERIC_TYPES)
{
  op_plus op;

  test_selfop<T,  2>($,op);
  test_selfop<T,  4>($,op);
  test_selfop<T,  8>($,op);
  test_selfop<T, 16>($,op);
  test_selfop<T, 32>($,op);
}

STF_CASE_TPL( "Check proxy -= operator" , STF_NUMERIC_TYPES)
{
  op_minus op;

  test_selfop<T,  2>($,op);
  test_selfop<T,  4>($,op);
  test_selfop<T,  8>($,op);
  test_selfop<T, 16>($,op);
  test_selfop<T, 32>($,op);
}

STF_CASE_TPL( "Check proxy *= operator" , STF_NUMERIC_TYPES)
{
  op_times op;

  test_selfop<T,  2>($,op);
  test_selfop<T,  4>($,op);
  test_selfop<T,  8>($,op);
  test_selfop<T, 16>($,op);
  test_selfop<T, 32>($,op);
}

STF_CASE_TPL( "Check proxy /= operator" , STF_NUMERIC_TYPES)
{
  op_divides op;

  test_selfop<T,  2>($,op);
  test_selfop<T,  4>($,op);
  test_selfop<T,  8>($,op);
  test_selfop<T, 16>($,op);
  test_selfop<T, 32>($,op);
}
