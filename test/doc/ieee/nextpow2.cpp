//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [nextpow2]
#include <boost/simd/ieee.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>


namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;

int main()
{
  pack_ft pf = {1.0f, 3.0f, -1.0f, 0.5f};

  std::cout
    << "---- simd" << '\n'
    << "<- pf =               " << pf << '\n'
    << "-> bs::nextpow2(pf) = " << bs::nextpow2(pf) << '\n';

  float xf = 7.0f;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =               " << xf << '\n'
    << "-> bs::nextpow2(xf) = " << bs::nextpow2(xf) << '\n';
  return 0;
}
//! [nextpow2]
