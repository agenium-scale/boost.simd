//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [nextafter]
#include <boost/simd/ieee.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>
#include <iomanip>


namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;

int main()
{
  pack_ft pf = {1.0f, 2.0f, -1.0f, 0.5f};
  pack_ft qf = {2.0f, -1.0f, 0.5f, 1.0f};


  std::cout
    << "---- simd" << std::setprecision(10) << '\n'
    << "<- pf =                    " << pf << '\n'
    << "<- qf =                    " << qf << '\n'
    << "-> bs::nextafter(pf, qf) = " << bs::nextafter(pf, qf) << '\n';

  float xf = 2.0f, yf = -1.0f;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =                    " << xf << '\n'
    << "<- yf =                    " << yf << '\n'
    << "-> bs::nextafter(xf, yf) = " << bs::nextafter(xf, yf) << '\n';
  return 0;
}
//! [nextafter]
