//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [rem]
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
    << " -> bs::rem(pf, qf) =                " << bs::rem(pf, qf) << '\n'
    << " -> bs::rem(bs::fix, pf, qf) =       " << bs::rem(bs::fix, pf, qf) << '\n'
    << " -> bs::rem(bs::ceil, pf, qf) =      " << bs::rem(bs::ceil, pf, qf) << '\n'
    << " -> bs::rem(bs::floor, pf, qf) =     " << bs::rem(bs::floor, pf, qf) << '\n'
    << " -> bs::rem(bs::round, pf, qf) =     " << bs::rem(bs::round, pf, qf) << '\n'
    << " -> bs::rem(bs::nearbyint, pf, qf) = " << bs::rem(bs::nearbyint, pf, qf) << '\n';

  float xf = 5.0, yf = 2.0f;

  std::cout
    << "---- scalar"  << '\n'
    << " <- xf =                             " << xf << '\n'
    << " <- yf =                             " << yf << '\n'
    << " -> bs::rem( xf, yf) =               " << bs::rem(xf, yf) << '\n'
    << " -> bs::rem(bs::fix, xf, yf) =       " << bs::rem(bs::fix, xf, yf) << '\n'
    << " -> bs::rem(bs::ceil, xf, yf) =      " << bs::rem(bs::ceil, xf, yf) << '\n'
    << " -> bs::rem(bs::floor, xf, yf) =     " << bs::rem(bs::floor, xf, yf) << '\n'
    << " -> bs::rem(bs::round, xf, yf) =     " << bs::rem(bs::round, xf, yf) << '\n'
    << " -> bs::rem(bs::nearbyint, xf, yf) = " << bs::rem(bs::nearbyint, xf, yf) << '\n';
  return 0;
}
//! [rem]
