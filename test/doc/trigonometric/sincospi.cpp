//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [sincospi]
#include <boost/simd/trigonometric.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>


namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;

int main()
{
  pack_ft pf = {1.0f, 2.0f, -1.0f, 0.5f};
  pack_ft ps, pc;
  std::tie(ps, pc) =  bs::sincospi(pf);
  std::cout
    << "---- simd" << '\n'
    << "<- pf =           " << pf << '\n'
    << "-> std::tie(ps, pc) =  bs::sincospi(pf) " << '\n'
    << "-> ps =  " << ps <<  '\n'
    << "-> pc =  " << pc << '\n';

  float xf = 2.0f;
  float s, c;
  std::tie(s, c) = bs::sincospi(xf);
  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =           " << xf << '\n'
    << "-> std::tie(s, c) = bs::sincospi(xf) = " << '\n'
    << "-> s =  " << s <<  '\n'
    << "-> c =  " << c << '\n';
  return 0;
}
//! [sincospi]
