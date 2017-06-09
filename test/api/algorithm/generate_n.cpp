//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or generate_n at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/algorithm/generate_n.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <boost/simd/pack.hpp>
#include <numeric>
#include <vector>
#include <simd_test.hpp>

using namespace boost::simd;
using namespace boost::alignment;

struct g
{
  g(float seed = 0.0f, float step = 1.0f)
    : i_(seed),  step_(step)  {}
  template < typename T> T operator()(bs::as_<T>)
  {
    auto z = bs::enumerate<T>(i_, step_);
    i_+= bs::cardinal_of<T>::value*step_;
    return z;
  }
  float i_;
  float step_;
};

struct gstd
{
  gstd(float seed = 0.0f, float step = 1.0f)
    : i_(seed),  step_(step)  {}
  float operator()()
  {
    float z = i_;
    i_+= step_;
    return z;
  }
  float i_;
  float step_;
};

STF_CASE_TPL( "Check unary simd::generate_n", STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  std::vector<T> values(2*N+1), ref(2*N+1);
  std::generate(ref.begin(), ref.begin()+2*N+1, gstd());
  boost::simd::generate_n(values.data(), 2*N+1, g());
  STF_EQUAL( values, ref );
  std::generate(ref.begin(), ref.begin()+2*N+1, gstd(2, 3));
  boost::simd::generate_n(values.data(),2*N+1, g(2, 3));
  STF_EQUAL( values, ref );

}


