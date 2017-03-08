//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [ldexp]
#include <boost/simd/ieee.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>


namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;
using pack_it = bs::pack <std::int32_t, 4>;

int main()
{
  pack_ft pf = {1.0f, 2.0f, -1.0f, 0.5f};
  pack_ft qf = {1.0f, 2.0f, -1.0f, 3.0f};
  pack_it qi = {1, 2, -1, 3};

  std::cout
    << "---- simd" << '\n'
    << "<- pf =                " << pf << '\n'
    << "<- qf =                " << qf << '\n'
    << "-> bs::ldexp(pf, qf) = " << bs::ldexp(pf, qf) << '\n'
    << "<- qi =                " << qi << '\n'
    << "-> bs::ldexp(pf, qi) = " << bs::ldexp(pf, qi) << '\n';

  float xf = 2.0f, yf = 3.0;
  std::int32_t yi = 3;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =                " << xf << '\n'
    << "<- yf =                " << yf << '\n'
    << "-> bs::ldexp(xf, yf) = " << bs::ldexp(xf, yf) << '\n'
    << "<- yi =                " << yi << '\n'
    << "-> bs::ldexp(xf, yi) = " << bs::ldexp(xf, yi) << '\n';
  return 0;
}
//! [ldexp]
