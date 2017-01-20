//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [nthroot]
#include <boost/simd/exponential.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using iT = std::int32_t;
using pack_it = bs::pack<iT, 4>;
using pack_ft = bs::pack<float, 4>;

int main() {
  pack_ft pf = {1, 2, -1, 8};
  pack_it qi = {1, 2, 3, 3};

  std::cout << "---- simd" << '\n'
            << "<- pf =                  " << pf << '\n'
            << "<- qi =                  " << qi << '\n'
            << "-> bs::nthroot(pf, qi) = " << bs::nthroot(pf, qi) << '\n';

  float xf = -8;
  iT yi = 3;

  std::cout << "---- scalar" << '\n'
            << "<- xf =                  " << xf << '\n'
            << "<- yi =                  " << yi << '\n'
            << "-> bs::nthroot(xf, yi) = " << bs::nthroot(xf, yi) << '\n';
  return 0;
}
//! [nthroot]
