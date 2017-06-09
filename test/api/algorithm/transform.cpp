//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/algorithm/transform.hpp>
#include <numeric>
#include <vector>
#include <simd_test.hpp>

using namespace boost::simd;

struct f { template<typename T> T operator()(T const& e) const              { return e*2; } };
struct g { template<typename T> T operator()(T const& a, T const& b) const  { return a*b; } };

STF_CASE_TPL( "Check unary simd::transform", STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  std::vector<T> values(2*N+1);
  std::iota(values.begin(), values.end(),T(1));

  std::vector<T> ref(2*N+3);
  std::transform(values.begin(), values.end(), ref.begin(), f{});

  std::vector<T> out(2*N+3);

  // verify we stopped where we should
  STF_EQUAL ( (boost::simd::transform(values.data(), values.data()+values.size(), out.data(), f{}))
            , out.data()+values.size()
            );

  // verify values
  STF_EQUAL( out, ref );
}

STF_CASE_TPL( "Check in-place unary simd::transform", STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  std::vector<T> values(2*N);
  std::iota(values.begin(), values.end(),T(1));

  std::vector<T> ref(2*N);
  std::transform(values.begin(), values.end(), ref.begin(), f{});

  // verify we stopped where we should
  STF_EQUAL ( (boost::simd::transform(values.data(), values.data()+values.size(), values.data(), f{}))
            , values.data()+values.size()
            );

  // verify values
  STF_EQUAL( values, ref );
}

STF_CASE_TPL( "Check binary simd::transform", STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  std::vector<T> values1(2*N+1);
  std::vector<T> values2(2*N+1);
  std::iota(values1.begin(), values1.end(),T(1));
  std::iota(values2.begin(), values2.end(),T(1));

  std::vector<T> ref(2*N+3);
  std::transform(values1.begin(), values1.end(), values2.begin(), ref.begin(), g{});

  std::vector<T> out(2*N+3);

  // verify we stopped where we should
  STF_EQUAL ( (boost::simd::transform ( values1.data(), values1.data()+values1.size(), values2.data()
                                      , out.data(), g{}
                                      )
            )
            , out.data()+values1.size()
            );

  // verify values
  STF_EQUAL( out, ref );
}
