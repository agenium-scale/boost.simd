//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [log2]
#include <boost/simd/exponential.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using pack_ft = bs::pack<float, 4>;

int main() {
  pack_ft pf = {1.0f, 2.0f, 1024.0f, 0.5f};

  std::cout << "---- simd" << '\n'
            << "<- pf =           " << pf << '\n'
            << "-> bs::log2(pf) = " << bs::log2(pf) << '\n';

  float xf = 2.0f;

  std::cout << "---- scalar" << '\n'
            << "<- xf =           " << xf << '\n'
            << "-> bs::log2(xf) = " << bs::log2(xf) << '\n';
  return 0;
}
//! [log2]
