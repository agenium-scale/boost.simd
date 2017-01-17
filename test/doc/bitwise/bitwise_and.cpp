//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [bitwise_and]
#include <boost/simd/bitwise.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/nan.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_it =  bs::pack <std::uint32_t, 4>;

int main()
{
  pack_it pf = { 3, 2,  3,  3  };
  pack_it qf = { 4, 1,  1, ~0 };
  std::cout
    <<  "---- simd" << '\n'
    << " <- pf =                      " << pf << '\n'
    << " <- qf =                      " << qf << '\n'
    << " -> bs::bitwise_and(pf, qf) = " << bs::bitwise_and(pf, qf) << '\n';

  std::uint32_t xf = 3, yf = 5;

  std::cout
    << "---- scalar"  << '\n'
    << " xf =                         " << xf << '\n'
    << " yf =                         " << yf << '\n'
    << " -> bs::bitwise_and(xf, yf) = " << bs::bitwise_and(xf, yf) << '\n';
  return 0;
}
//! [bitwise_and]
