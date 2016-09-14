//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [transform-unary]
#include <boost/simd/algorithm/transform.hpp>
#include <boost/simd/function/sqr.hpp>
#include <iostream>
#include <vector>

int main()
{
  std::vector<float> d{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f};

  boost::simd::transform( d.data(), d.data()+7, d.data(), boost::simd::sqr );

  for(auto e : d )
    std::cout << e << " ";

  return 0;
}
//! [transform-unary]
