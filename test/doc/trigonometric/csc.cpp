//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [csc]
#include <boost/simd/trigonometric.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>


namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;

int main()
{
  pack_ft pf = {1.0f, 2.0f, -1.0f, 0.5f};

  std::cout
    << "---- simd" << '\n'
    << "<- pf =           " << pf << '\n'
    << "-> bs::csc(pf) = " << bs::csc(pf) << '\n';

  float xf = 2.0f;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =           " << xf << '\n'
    << "-> bs::csc(xf) = " << bs::csc(xf) << '\n';
  return 0;
}
//! [csc]
