//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [fnms]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <iostream>

namespace bs = boost::simd;
using pack_ft = bs::pack <float, 4>;

int main()
{
  pack_ft pf = bs::enumerate<pack_ft>(-1, 2);
  pack_ft qf = bs::enumerate<pack_ft>( 0, 3);
  pack_ft rf = bs::enumerate<pack_ft>( 2, 5);

  std::cout
    << "---- simd" << '\n'
    << " <- pf =                   " << pf << '\n'
    << " <- qf =                   " << qf << '\n'
    << " <- rf =                   " << rf << '\n'
    << " -> bs::fnms(pf, qf, rf) = " << bs::fnms(pf, qf, rf) << '\n';

  float xf = 3.0f, yf = -3.0f, zf = 2.0f;

  std::cout
    << "---- scalar" << '\n'
    << " <- xf =                   " << xf << '\n'
    << " <- yf =                   " << yf << '\n'
    << " <- yf =                   " << zf << '\n'
    << " -> bs::fnms(xf, yf, rf) = " << bs::fnms(xf, yf, zf) << '\n';
  return 0;
}
//! [fnms]
