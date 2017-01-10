//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [remquo]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 4>;
using pack_it =  bs::pack <std::int32_t, 4>;

int main()
{
  pack_ft xf = { 3.0f, -2.0f, -3.0f, 1.0f };
  pack_ft yf = { 4.0f, -1.0f, -3.0f, 2.0f };
  pack_ft rf;
  pack_it qi;
  std::tie(rf, qi) = bs::remquo(xf, yf);

  std::cout
    <<  "---- simd:  std::tie(xf, yf) = bs::remquo(xf, yf)\n"
    << " <- xf = " << xf << '\n'
    << " <- yf = " << yf << '\n'
    << " -> rf = " << rf << '\n'
    << " -> qi = " << qi << '\n';

  float sxf = 3.0f, syf = 4.0f;
  float srf;
  std::int32_t sqi;
  std::tie(srf, sqi) = bs::remquo(sxf, syf);

  std::cout
    << "---- scalar: std::tie(srf, sqi) = bs::remquo(sxf, syf)\n"
    << " <- sxf =  " << sxf << '\n'
    << " <- syf =  " << syf << '\n'
    << " -> srf = " << srf << '\n'
    << " -> sqi = " << sqi << '\n';
  return 0;
}
//! [remquo]
