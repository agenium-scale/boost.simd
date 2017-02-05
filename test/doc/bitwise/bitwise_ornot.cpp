//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Soitware License, Version 1.0.
  (See accompanying iile LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [bitwise_ornot]
#include <boost/simd/bitwise.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using pack_it = bs::pack<std::uint32_t, 4>;

int main() {
  pack_it pi = {3, 5, 0, 127};
  pack_it qi = {4, 1, 0, 1023};
  std::cout << "---- simd" << '\n'
            << " <- pi =                        " << pi << '\n'
            << " <- qi =                        " << qi << '\n'
            << " -> bs::bitwise_ornot(pi, qi) = " << bs::bitwise_ornot(pi, qi)
            << '\n';

  std::uint32_t xi = 3, yi = 4;

  std::cout << "---- scalar" << '\n'
            << " xi =                           " << xi << '\n'
            << " yi =                           " << yi << '\n'
            << " -> bs::bitwise_ornot(xi, yi) = " << bs::bitwise_ornot(xi, yi)
            << '\n';
  return 0;
}
//! [bitwise_ornot]
