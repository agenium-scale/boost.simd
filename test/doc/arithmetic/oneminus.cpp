//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [oneminus]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;
using pack_it = bs::pack <std::uint16_t,4>;

int main()
{
  pack_ft pf = {-1.0f, 2.0f, -3.0f, -32768.0f};
  pack_it pi = { 0,   -1,    2,    3 };

  std::cout
    << "---- simd" << '\n'
    << "<- pf =                                " << pf << '\n'
    << "-> bs::oneminus(pf) =                  " << bs::oneminus(pf) << '\n'
    << "<- pi =                                " << pi << '\n'
    << "-> bs::oneminus(pi) =                  " << bs::oneminus(pi) << '\n'
    << "-> bs::saturated_(bs::oneminus(pi)) =  " << bs::saturated_(bs::oneminus)(pi) << '\n';

  float xf = -327.0f;
  std::uint16_t xi =  2;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =                                " << xf << '\n'
    << "-> bs::oneminus(xf) =                  " << bs::oneminus(xf) << '\n'
    << "<- xi =                                " << xi << '\n'
    << "-> bs::oneminus(xi) =                  " << bs::oneminus(xi) << '\n'
    << "-> bs::saturated_(bs::oneminus(xi)) =  " << bs::saturated_(bs::oneminus)(xi) << '\n';
  return 0;
}
//! [oneminus]
