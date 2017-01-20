//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [pow2]
#include <boost/simd/exponential.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using iT = std::int32_t;
using pack_it = bs::pack<iT, 4>;
using pack_ft = bs::pack<float, 4>;

int main() {
  pack_ft pf = {1.0f, 2.0f, -1.0f, 0.5f};
  pack_it qi = {1, 2, -1, 0};

  std::cout << "---- simd" << '\n'
            << "<- pf =               " << pf << '\n'
            << "<- qi =               " << qi << '\n'
            << "-> bs::pow2(qi) =     " << bs::pow2(qi) << '\n'
            << "-> bs::pow2(pf, qi) = " << bs::pow2(pf, qi) << '\n';

  float xf = 2.0f;
  iT yi = 3;

  std::cout << "---- scalar" << '\n'
            << "<- xf =               " << xf << '\n'
            << "<- yi =               " << yi << '\n'
            << "-> bs::pow2(yi) =     " << bs::pow2(yi) << '\n'
            << "-> bs::pow2(xf, yi) = " << bs::pow2(xf, yi) << '\n';
  return 0;
}
//! [pow2]
