//==================================================================================================
/*!
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/div.hpp>
#include <boost/simd/function/fix.hpp>
#include <iostream>

using std::cout;
using std::endl;

using namespace boost::simd;

int main()
{
  // long long is not supported
  typedef pack<std::int64_t, 2> p_l_t;

  p_l_t a(123, 178);
  p_l_t b(10, 10);

  // div is also in :: namespace
  auto c = boost::simd::div(boost::simd::fix, a, b) * b;

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;

  return 0;
}
