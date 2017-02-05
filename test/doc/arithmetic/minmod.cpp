//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [minmod]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/nan.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 4>;

int main()
{
  pack_ft pf = { 3.0f, -2.0f, -5.0f, 0.0f };
  pack_ft qf = { 4.0f,  3.0f, -2.0f, 4.0f };
  std::cout
    <<  "---- simd" << '\n'
    << " <- pf =                                " << pf << '\n'
    << " <- qf =                                " << qf << '\n'
    << " -> bs::minmod(pf, qf) =                " << bs::minmod(pf, qf) << '\n';

  float xf = 3.0f, yf = 4.0f;

  std::cout
    << "---- scalar"  << '\n'
    << " xf =                                   " << xf << '\n'
    << " yf =                                   " << yf << '\n'
    << " -> bs::minmod(xf, yf) =                " << bs::minmod(xf, yf) << '\n'
    << " -> bs::minmod(xf,-yf) =                " << bs::minmod(xf, -yf) << '\n';
  return 0;
}
//! [minmod]
