//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [sqr]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;
using pack_it = bs::pack <std::int16_t,4>;

int main()
{
  pack_ft pf = {-1.0f, 2.0f, -3.0f, -32768.0f};
  pack_it pi = {-1,    2,    -3,    -32768   };

  std::cout
    << "---- simd" << '\n'
    << "<- pf =                           " << pf << '\n'
    << "-> bs::sqr(pf) =                  " << bs::sqr(pf) << '\n'
    << "<- pi =                           " << pi << '\n'
    << "-> bs::sqr(pi) =                  " << bs::sqr(pi) << '\n'
    << "-> bs::saturated_(bs::sqr(pi)) =  " << bs::saturated_(bs::sqr)(pi) << '\n';

  float xf = -32768.0f;
  std::int16_t xi =  -32768;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =                           " << xf << '\n'
    << "-> bs::sqr(xf) =                  " << bs::sqr(xf) << '\n'
    << "<- xi =                           " << xi << '\n'
    << "-> bs::sqr(xi) =                  " << bs::sqr(xi) << '\n'
    << "-> bs::saturated_(bs::sqr(xi)) =  " << bs::saturated_(bs::sqr)(xi) << '\n';
  return 0;
}
//! [sqr]
