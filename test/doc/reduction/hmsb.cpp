//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [hmsb]
#include <boost/simd/pack.hpp>
#include <boost/simd/reduction.hpp>
#include <iostream>

namespace bs = boost::simd;
using pack_it = bs::pack<std::int32_t, 4>;

int main() {
  pack_it pi = {1, 2, -1, 3};

  std::cout << "---- simd" << '\n'
            << "<- pi =           " << pi << '\n'
            << "-> bs::hmsb(pi) = " << bs::hmsb(pi) << '\n';
  return 0;
}
//! [hmsb]
