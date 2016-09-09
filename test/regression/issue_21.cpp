//==================================================================================================
/*!
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <iostream>

using namespace std;
using namespace boost::simd;

#define SECONDS_IN_ONE_DAY      86400

template <typename T>
class op_boost_utc_add
{
  typedef boost::simd::pack<T, 16 / sizeof(T)> p_t;
  const p_t seconds_in_one_day = boost::simd::splat<p_t>(SECONDS_IN_ONE_DAY);

  public:
  p_t operator()(p_t const &a0, p_t const &a1, p_t const &delta)
  {
    return a0 + (seconds_in_one_day * a1) + delta;
  }
};

int main()
{
  // long long is not supported, prefer std::int64_t
  typedef boost::simd::pack<std::int64_t, 2> p_l_t;

  p_l_t a(10, 100);
  p_l_t b(10, 100);
  p_l_t c(1, 1);

  p_l_t r = op_boost_utc_add<std::int64_t>()(a, b, c);

  cout << r << endl;

  return 0;
}
