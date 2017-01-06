//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [div]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using pack_ft = bs::pack <float, 4>;

int main()
{
  pack_ft pf = { 5.0f, -5.0f, 3.0f,  5.0f };
  pack_ft qf = { 2.0f,  2.0f, 3.0f, -2.0f };

  std::cout
    <<  "---- simd" << '\n'
    << " <- pf =                             " << pf << '\n'
    << " <- qf =                             " << qf << '\n'
    << " -> bs::div(pf, qf) =                " << bs::div(pf, qf) << '\n'
    << " -> bs::div(bs::fix, pf, qf) =       " << bs::div(bs::fix, pf, qf) << '\n'
    << " -> bs::div(bs::ceil, pf, qf) =      " << bs::div(bs::ceil, pf, qf) << '\n'
    << " -> bs::div(bs::floor, pf, qf) =     " << bs::div(bs::floor, pf, qf) << '\n'
    << " -> bs::div(bs::round, pf, qf) =     " << bs::div(bs::round, pf, qf) << '\n'
    << " -> bs::div(bs::nearbyint, pf, qf) = " << bs::div(bs::nearbyint, pf, qf) << '\n';

  float xf = 5.0, yf = 2.0f;

  std::cout
    << "---- scalar"  << '\n'
    << " <- xf =                             " << xf << '\n'
    << " <- yf =                             " << yf << '\n'
    << " -> bs::div( xf, yf) =               " << bs::div(xf, yf) << '\n'
    << " -> bs::div(bs::fix, xf, yf) =       " << bs::div(bs::fix, xf, yf) << '\n'
    << " -> bs::div(bs::ceil, xf, yf) =      " << bs::div(bs::ceil, xf, yf) << '\n'
    << " -> bs::div(bs::floor, xf, yf) =     " << bs::div(bs::floor, xf, yf) << '\n'
    << " -> bs::div(bs::round, xf, yf) =     " << bs::div(bs::round, xf, yf) << '\n'
    << " -> bs::div(bs::nearbyint, xf, yf) = " << bs::div(bs::nearbyint, xf, yf) << '\n';
  return 0;
}
//! [div]
