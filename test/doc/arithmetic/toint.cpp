//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [toint]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/inf.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;
using pack_it = bs::pack <std::uint16_t, 4>;

int main()
{
  pack_ft pf = {-1.0f, 2.6f, -3.4f, bs::Inf<float>()};
  pack_it pi = { 1, 2, 3, bs::Inf<std::uint16_t>()  };

  std::cout
    << "---- simd" << '\n'
    << "<- pf =                        " << pf << '\n'
    << "-> bs::toint(pf) =             " << bs::toint(pf) << '\n'
    << "-> saturated_(bs::toint)(pf) = " << bs::saturated_(bs::toint)(pf) << '\n'
    << "<- pi =                        " << pi << '\n'
    << "-> bs::toint(pi) =             " << bs::toint(pi) << '\n'
    << "-> saturated_(bs::toint)(pi) = " << bs::saturated_(bs::toint)(pi) << '\n';

  float xf = -2.5f;
  std::uint16_t xi = 65535;
  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =                        " << xf << '\n'
    << "-> bs::toint(xf) =             " << bs::toint(xf) << '\n'
    << "-> saturated_(bs::toint)(xf) = " << bs::saturated_(bs::toint)(xf) << '\n'
    << "<- xi =                        " << xi << '\n'
    << "-> bs::toint(xi) =             " << bs::toint(xi) << '\n'
    << "-> saturated_(bs::toint)(xi) = " << bs::saturated_(bs::toint)(xi) << '\n';
     return 0;
}
//! [toint]
