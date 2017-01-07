//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [sqrt]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;

int main()
{
  pack_ft pf = {1.0f, 2.0f, 3.0f, 4.0f};

  std::cout
    << "---- simd" << '\n'
    << "<- pf =          " << pf << '\n'
    << "-> bs::sqrt(pf) =" << bs::sqrt(pf) << '\n';

  float xf = 32768.0f;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =           " << xf << '\n'
    << "-> bs::sqrt(xf) = " << bs::sqrt(xf) << '\n';
  return 0;
}
//! [sqrt]
