//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [if_zero_else_allbits]
#include <boost/simd/boolean.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 4>;

int main()
{
  pack_ft pf = { 3.0f, 0.0f, -3.0f, -0.0 };

  std::cout
    <<  "---- simd" << '\n'
    << " <- pf =                           " << pf << '\n'
    << " -> bs::if_zero_else_allbits(pf) = " << bs::if_zero_else_allbits(pf) << '\n';


  std::int32_t xf = 3, yf = 0;

  std::cout
    << "---- scalar"  << '\n'
    << " xf =                              " << xf << '\n'
    << " yf =                              " << yf << '\n'
    << " -> bs::if_zero_else_allbits(xf) = " << bs::if_zero_else_allbits(xf) << '\n'
    << " -> bs::if_zero_else_allbits(yf) = " << bs::if_zero_else_allbits(yf) << '\n';
  return 0;
}
//! [if_zero_else_allbits]
