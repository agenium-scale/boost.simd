//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [sqr_abs]
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
    << "-> bs::sqr_abs(pf) =                  " << bs::sqr_abs(pf) << '\n'
    << "<- pi =                           " << pi << '\n'
    << "-> bs::sqr_abs(pi) =                  " << bs::sqr_abs(pi) << '\n'
    << "-> bs::saturated_(bs::sqr_abs(pi)) =  " << bs::saturated_(bs::sqr_abs)(pi) << '\n';

  float xf = -32768.0f;
  std::int16_t xi =  -32768;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =                           " << xf << '\n'
    << "-> bs::sqr_abs(xf) =                  " << bs::sqr_abs(xf) << '\n'
    << "<- xi =                           " << xi << '\n'
    << "-> bs::sqr_abs(xi) =                  " << bs::sqr_abs(xi) << '\n'
    << "-> bs::saturated_(bs::sqr_abs(xi)) =  " << bs::saturated_(bs::sqr_abs)(xi) << '\n';
  return 0;
}
//! [sqr_abs]
