//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [hi]
#include <boost/simd/bitwise.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using iT = std::int32_t;
using pack_it = bs::pack<iT, 4>;

int main() {
  pack_it pi = {1, 2, -1, 32769};

  std::cout << "---- simd" << '\n'
            << "<- pi =           " << pi << '\n'
            << "-> bs::hi(pi) =   " << bs::hi(pi) << '\n';

  iT xi = 2;

  std::cout << "---- scalar" << '\n'
            << "<- xi =           " << xi << '\n'
            << "-> bs::hi(xi) =   " << bs::hi(xi) << '\n';
  return 0;
}
//! [hi]
