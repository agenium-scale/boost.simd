//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [stirling]
#include <boost/simd/eulerian.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>


namespace bs =  boost::simd;
using pack_fd = bs::pack <double, 4>;

int main() {
  pack_fd pd = {170.0, 2.0, 35.0, 10.0};

  std::cout
    << "---- simd" << '\n'
    << "<- pd =               " << pd << '\n'
    << "-> bs::stirling(pd) = " << bs::stirling(pd) << '\n';

  double xf = 40.0;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =               " << xf << '\n'
    << "-> bs::stirling(xf) = " << bs::stirling(xf) << '\n';
  return 0;
}
//! [stirling]
