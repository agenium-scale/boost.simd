//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [ifix]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 8>;

int main()
{
  pack_ft pf = bs::enumerate<pack_ft>(-2.56, 0.51);
  std::cout
    << "---- simd" << '\n'
    << " <- pf =           " << pf  << '\n'
    << " -> bs::ifix(pf) = " << bs::ifix(pf) << '\n';

  float xf = 3.2f, yf = -3.2f;

  std::cout
    << "---- scalar" << '\n'
    << " <- xf =           " << xf<< '\n'
    << " -> bs::ifix(xf) = " << bs::ifix(xf) << '\n'
    << " <- yf =           " << yf << '\n'
    << " -> bs::ifix(yf) = " << bs::ifix(yf) << '\n';
  return 0;
}
//! [ifix]
