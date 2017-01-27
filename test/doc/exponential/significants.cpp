//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [significants]
#include <boost/simd/exponential.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using iT = std::int32_t;
using pack_it = bs::pack<iT, 4>;
using pack_ft = bs::pack<float, 4>;

int main() {
  pack_ft pf(1234.567f);
  pack_it qi = {1, 2, 3, 4};

  std::cout << "---- simd" << '\n'
            << "<- pf =                       " << pf << '\n'
            << "<- qi =                       " << qi << '\n'
            << "-> bs::significants(pf, qi) = " << bs::significants(pf, qi)
            << '\n';

  float xf = 2.345678f;
  iT yi = 3;

  std::cout << "---- scalar" << '\n'
            << "<- xf =                       " << xf << '\n'
            << "<- yi =                       " << yi << '\n'
            << "-> bs::significants(xf, yi) = " << bs::significants(xf, yi)
            << '\n';
  return 0;
}
//! [significants]
