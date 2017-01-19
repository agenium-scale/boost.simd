//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [logical_notand]
#include <boost/simd/boolean.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 4>;

int main()
{
  pack_ft pf = { 3.0f, -0.0f, -3.0f, bs::Valmax<float>() };
  pack_ft qf = { 4.0f, -1.0f, -3.0f, 0.0f                };
  std::cout
    <<  "---- simd" << '\n'
    << " <- pf =                      " << pf << '\n'
    << " <- qf =                      " << qf << '\n'
    << " -> bs::logical_notand(pf, qf) = " << bs::logical_notand(pf, qf) << '\n';

  float xf = 3.0f, yf = 4.0f;

  std::cout
    << "---- scalar"  << '\n'
    << " xf =                         " << xf << '\n'
    << " yf =                         " << yf << '\n'
    << " -> bs::logical_notand(xf, yf) = " << bs::logical_notand(xf, yf) << '\n';
  return 0;
}
//! [logical_notand]
