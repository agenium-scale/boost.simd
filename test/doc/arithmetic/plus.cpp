//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [plus]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 4>;
using pack_it =  bs::pack <std::int16_t,4>;

int main()
{
  pack_ft pf = { 1.0f, -2.0f, -3.0f, -32700.0f};
  pack_ft qf = { 2.0f, -1.0f, -3.0f,  32721   };
  pack_it pi = { 1,    -2,    -2,     32767   };
  pack_it qi = { 2,    -1,    -3,         1   };
  std::cout
    <<  "---- simd" << '\n'
    << " <- pf =                                " << pf << '\n'
    << " <- qf =                                " << qf << '\n'
    << " -> bs::plus(pf, qf) =                 " << bs::plus(pf, qf) << '\n'
    << " <- pi =                                " << pi << '\n'
    << " <- qi =                                " << qi << '\n'
    << " -> bs::plus(pi, qi) =                 " << bs::plus(pi, qi) << '\n'
    << " -> bs::saturated_(bs::plus)(pi, qi) = " << bs::saturated_(bs::plus)(pi, qi) << '\n';

  float        xf = 32767.0f, yf = -32000.0f;
  std::int16_t xi = 32767,    yi = -32000;

  std::cout
    << "---- scalar"  << '\n'
    << " xf =                                   " << xf << '\n'
    << " yf =                                   " << yf << '\n'
    << " -> bs::plus(xf, yf) =                 " << bs::plus(xf, yf) << '\n'
    << " xi =                                   " << xi << '\n'
    << " yi =                                   " << yi << '\n'
    << " -> bs::plus(xi, yi) =                 " << bs::plus(xi, yi) << '\n'
    << " -> bs::saturated_(bs::plus)(xi, yi) = " << bs::saturated_(bs::plus)(xi, yi) << '\n';
  return 0;
}
//! [plus]
