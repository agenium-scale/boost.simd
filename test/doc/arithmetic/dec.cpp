//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [dec]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 4>;
using pack_it =  bs::pack <std::int16_t,4>;

int main()
{
  pack_ft pf = {-1.0f, 2.0f, -3.0f, -32768.0f};
  pack_it pi = {-1,    2,    -3,    -32768   };
  std::cout
    << "---- simd" << '\n'
    << "pf =                              " << pf << '\n'
    << "-> bs::dec(pf) =                  " << bs::dec(pf) << '\n'
    << "pi =                              " << pi << '\n'
    << "-> bs::dec(pi) =                  " << bs::dec(pi) << '\n'
    << "-> bs::saturated_(bs::dec(pi)) =  " << bs::saturated_(bs::dec)(pi) << '\n';

  float xf = -32768.0f;
  std::int16_t xi =  -32768;

  std::cout
    << "---- scalar"  << "\n"
    << " <- xf =                          " << xf << "\n"
    << " -> bs::dec(xf) =                 " << bs::dec(xf) << "\n"
    << " <- xi =                          " << xi << "\n"
    << " -> bs::dec(xi) =                 " << bs::dec(xi) << "\n"
    << " -> bs::saturated_(bs::dec(xi)) = " << bs::saturated_(bs::dec)(xi) << "\n";
  return 0;
}
//! [dec]
