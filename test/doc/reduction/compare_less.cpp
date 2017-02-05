//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [compare_less]
#include <boost/simd/pack.hpp>
#include <boost/simd/reduction.hpp>
#include <iostream>

namespace bs = boost::simd;
using pack_it = bs::pack<std::int32_t, 4>;

int main() {
  pack_it pi = {1, 2, 5, 2};
  pack_it qi = {1, 3, 2, 8};

  std::cout << "---- simd" << '\n'
            << "<- pi =                       " << pi << '\n'
            << "<- qi =                       " << qi << '\n'
            << "-> bs::compare_less(pi, qi) = " << bs::compare_less(pi, qi)
            << '\n';
  return 0;
}
//! [compare_less]
