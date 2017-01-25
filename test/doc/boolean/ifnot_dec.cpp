//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [ifnot_dec]
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
    << " <- pf =                   " << pf << '\n'
    << " <- qf =                   " << qf << '\n'
    << " -> bs::ifnot_dec(pf, qf) =   " << bs::ifnot_dec(pf, qf) << '\n';

  std::int32_t xf = 3, yf = 0,  zf = 5;

  std::cout
    << "---- scalar"  << '\n'
    << " xf =                     " << xf << '\n'
    << " yf =                     " << yf << '\n'
    << " zf =                     " << zf << '\n'
    << " -> bs::ifnot_dec(xf, zf) =  " << bs::ifnot_dec(xf, zf) << '\n'
    << " -> bs::ifnot_dec(yf, zf) =  " << bs::ifnot_dec(yf, zf) << '\n';
  return 0;
}
//! [ifnot_dec]
