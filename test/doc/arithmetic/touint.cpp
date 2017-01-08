//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [touint]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/inf.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;
using pack_it = bs::pack <std::int16_t, 4>;

int main()
{
  pack_ft pf = {-1.0f, 2.6f, 3.4f, bs::Inf<float>()};
  pack_it pi = { -1, 2, 3, bs::Inf<std::int16_t>() };

  std::cout
    << "---- simd" << '\n'
    << "<- pf =                        " << pf << '\n'
    << "-> bs::touint(pf) =             " << bs::touint(pf) << '\n'
    << "-> saturated_(bs::touint)(pf) = " << bs::saturated_(bs::touint)(pf) << '\n'
    << "<- pi =                        " << pi << '\n'
    << "-> bs::touint(pi) =             " << bs::touint(pi) << '\n'
    << "-> saturated_(bs::touint)(pi) = " << bs::saturated_(bs::touint)(pi) << '\n';

  float xf = -2.50f;
  std::int16_t xi = -1;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =                        " << xf << '\n'
    << "-> bs::touint(xf) =             " << bs::touint(xf) << '\n'
    << "-> saturated_(bs::touint)(xf) = " << bs::saturated_(bs::touint)(xf) << '\n'
    << "<- xi =                        " << xi << '\n'
    << "-> bs::touint(xi) =             " << bs::touint(xi) << '\n'
    << "-> saturated_(bs::touint)(xi) = " << bs::saturated_(bs::touint)(xi) << '\n';
    return 0;
}
//! [touint]
