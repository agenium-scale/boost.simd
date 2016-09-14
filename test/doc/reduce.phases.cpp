//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [reduce-phases]
#include <boost/simd/algorithm/reduce.hpp>
#include <iostream>
#include <numeric>

struct squared_sum
{
  template<typename T>
  T operator()(T const& a, T const& e) { return a + e*e; }
};

int main()
{
  float values[] = {1.f,2.f,3.f,4.f,5.f,6.f,7.f,8.f,9.f,};

  std::cout << "SIMD reduce    :"
            << boost::simd::reduce( &values[0], &values[0]+9, 0.f
                                  , squared_sum{}, 0.f
                                  , boost::simd::plus
                                  )
            << std::endl;

  return 0;
}
//! [reduce-phases]
