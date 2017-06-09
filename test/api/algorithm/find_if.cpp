//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/algorithm/find_if.hpp>
#include <numeric>
#include <vector>
#include <simd_test.hpp>

using namespace boost::simd;

template<typename T> struct f
{
  using p_t = pack<T>;
  f(const T & n) :n_(n), vn_(n){}

  bool                  operator()(T a)           const {return a >= n_;  }
  bs::as_logical_t<p_t> operator()(const p_t & a) const {return a >= vn_; }
  T n_;
  p_t vn_;
};

STF_CASE_TPL( "Check unary simd::find_if", STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  std::vector<T> values(2*N+1);
  std::iota(values.begin(), values.end(),T(1));
  {
    auto f1 = std::find_if(values.begin(), values.end(), [](T e) { return e >= N; } );
    auto f2 = boost::simd::find_if(values.data(), values.data()+2*N+1, f<T>(T(N)));
    STF_EQUAL ( *f1, *f2 );
    auto f3 = std::find_if(values.begin(), values.end(), [](T e) { return e >= 104; } );
    auto f4 = boost::simd::find_if(values.data(), values.data()+2*N+1, f<T>(T(104)) );
    STF_EQUAL ( *f3, *f4 );
  }

  {
    auto f1 = std::find_if(values.begin(), values.end(), [](T e) { return e >= 0; } );
    auto f2 = boost::simd::find_if(values.data(), values.data()+2*N+1, f<T>(T(0)) );
    STF_EQUAL ( *f1, *f2 );
    auto f3 = std::find_if(values.begin(), values.end(), [](T e) { return e >= 2*N; });
    auto f4 = boost::simd::find_if(values.data(), values.data()+2*N+1, f<T>(T(2*N)));
    STF_EQUAL ( *f3, *f4 );
  }
}
