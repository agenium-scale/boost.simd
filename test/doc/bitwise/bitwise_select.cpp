//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [bitwise_select]
#include <boost/simd/bitwise.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using iT = std::uint32_t;
using pack_it = bs::pack<iT, 4>;

int main() {
  pack_it pi = {3, -2, -10, 0};
  pack_it qi = {4, -1, 0, 5};
  pack_it si = {2, bs::Allbits<iT>(), 0, 4};

  std::cout << "---- simd" << '\n'
            << " <- si =                              " << si << '\n'
            << " <- pi =                              " << pi << '\n'
            << " <- qi =                              " << qi << '\n'
            << " -> bs::bitwise_select(si, pi, qi) =  "
            << bs::bitwise_select(si, pi, qi) << '\n';

  iT ssi = 3, xi = 3, yi = 4;

  std::cout << "---- scalar" << '\n'
            << " ssi =                                " << ssi << '\n'
            << " xi =                                 " << xi << '\n'
            << " yi =                                 " << yi << '\n'
            << " -> bs::bitwise_select(ssi, xi, yi) = "
            << bs::bitwise_select(ssi, xi, yi) << '\n';
  return 0;
}
//! [bitwise_select]
