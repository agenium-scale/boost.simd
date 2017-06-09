//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [lexicographical_comparerange]
#include <boost/simd/algorithm/lexicographical_compare.hpp>
#include <boost/simd/function/inc.hpp>
#include <iostream>
#include <vector>

int main()
{
  std::vector<float> c{1.f, 2.f, 2.f, 3.f, 4.f, 5.f, 6.f};
  std::vector<float> d{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f};


  bool b1 = boost::simd::lexicographical_compare( d.data(), d.data()+7, d.data(), d.data()+7);
  bool b2 = boost::simd::lexicographical_compare( c.data(), c.data()+7, d.data(), d.data()+7);
  bool b3 = boost::simd::lexicographical_compare( c.data(), c.data()+7, c.data(), c.data()+5);
  bool b4 = boost::simd::lexicographical_compare( d.data(), d.data()+7, c.data(), c.data()+5);
  bool b5 = boost::simd::lexicographical_compare( c.data(), c.data()+5, c.data(), c.data()+7);

  std::cout << "b1  " << b1 << '\n';
  std::cout << "b2  " << b2 << '\n';
  std::cout << "b3  " << b3 << '\n';
  std::cout << "b4  " << b4 << '\n';
  std::cout << "b5  " << b5 << '\n';

  return 0;
}
//! [lexicographical_comparerange]
