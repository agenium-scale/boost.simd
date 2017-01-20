//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [bitwise_notand]
#include <boost/simd/bitwise.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using pack_it = bs::pack<std::uint32_t, 4>;

int main() {
  pack_it pi = {3, -2, 1, 0};
  pack_it qi = {4, -1, 5, 25};
  std::cout << "---- simd" << '\n'
            << " <- pi =                         " << pi << '\n'
            << " <- qi =                         " << qi << '\n'
            << " -> bs::bitwise_notand(pi, qi) = " << bs::bitwise_notand(pi, qi)
            << '\n';

  std::uint32_t xi = 3, yi = 5;

  std::cout << "---- scalar" << '\n'
            << " xi =                            " << xi << '\n'
            << " yi =                            " << yi << '\n'
            << " -> bs::bitwise_notand(xi, yi) = " << bs::bitwise_notand(xi, yi)
            << '\n';
  return 0;
}
//! [bitwise_notand]
