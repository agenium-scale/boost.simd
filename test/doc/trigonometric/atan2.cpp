//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [atan2]
#include <boost/simd/trigonometric.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/reverse.hpp>
#include <iostream>


namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;

int main()
{
  pack_ft pf = {1.0f, 2.0f, -1.0f, 0.5f};
  pack_ft qf = bs::reverse(pf);

  std::cout
    << "---- simd" << '\n'
    << "<- pf =           " << pf << '\n'
    << "<- qf =           " << qf << '\n'
    << "-> bs::atan2(pf, qf) = " << bs::atan2(pf, qf) << '\n';

  float xf = 2.0f, yf = 3.0f;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =           " << xf << '\n'
    << "<- yf =           " << yf << '\n'
    << "-> bs::atan2(xf, yf) = " << bs::atan2(xf, yf) << '\n';
  return 0;
}
//! [atan2]
