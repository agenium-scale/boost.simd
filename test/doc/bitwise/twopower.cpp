//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [twopower]
#include <boost/simd/bitwise.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using pack_it = bs::pack<std::int32_t, 4>;

int main() {
  pack_it pi = {1, 2, -1, 5};

  std::cout << "---- simd" << '\n'
            << "<- pi =               " << pi << '\n'
            << "-> bs::twopower(pi) = " << bs::twopower(pi) << '\n';

  std::int32_t xi = 4;

  std::cout << "---- scalar" << '\n'
            << "<- xi =               " << xi << '\n'
            << "-> bs::twopower(xi) = " << bs::twopower(xi) << '\n';
  return 0;
}
//! [twopower]
