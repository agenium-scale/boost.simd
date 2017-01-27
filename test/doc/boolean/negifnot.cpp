//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [negifnot]
#include <boost/simd/boolean.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/nan.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 4>;

int main()
{
  pack_ft pf = { 3.0f, 0.0f, -3.0f, -0.0 };
  pack_ft qf = { 3.0f, 0.5f, -3.0f, 1.0f };
  std::cout
    <<  "---- simd" << '\n'
    << " <- pf =                               " << pf << '\n'
    << " <- qf =                               " << qf << '\n'
    << " -> bs::negifnot(pf, qf) =      " << bs::ifnot_neg(pf, qf) << '\n';

  std::int32_t xf = 3, yf = 0,  zf = 5;

  std::cout
    << "---- scalar"  << '\n'
    << " xf =                                  " << xf << '\n'
    << " yf =                                  " << yf << '\n'
    << " zf =                                  " << zf << '\n'
    << " -> bs::negifnot(xf, zf) =      " << bs::ifnot_neg(xf, zf) << '\n'
    << " -> bs::negifnot(yf, zf) =      " << bs::ifnot_neg(yf, zf) << '\n';
  return 0;
}
//! [negifnot]
