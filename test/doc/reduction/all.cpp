//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [all]
#include <boost/simd/pack.hpp>
#include <boost/simd/reduction.hpp>
#include <iostream>

namespace bs = boost::simd;
using pack_ft = bs::pack<float, 4>;

int main() {
  pack_ft pf = {1.0f, 2.0f, -1.0f, 0.5f};
  pack_ft qf = {1.0f, 0.0f, -1.0f, 0.5f};

  std::cout << "---- simd" << '\n'
            << "<- pf =          " << pf << '\n'
            << "-> bs::all(pf) = " << bs::all(pf) << '\n'
            << "<- qf =          " << qf << '\n'
            << "-> bs::all(qf) = " << bs::all(qf) << '\n';

  return 0;
}
//! [all]
