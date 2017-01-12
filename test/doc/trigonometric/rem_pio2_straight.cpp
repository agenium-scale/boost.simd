//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [rem_pio2_straight]
#include <boost/simd/trigonometric.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>


namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;

int main()
{
  pack_ft pf = {1.0f, 2.0f, -1.0f, 0.5f};
  pack_ft pe, pm;
  std::tie(pe, pm) = bs::rem_pio2_straight(pf);
  std::cout
    << "---- simd" << '\n'
    << "<- pf =           " << pf << '\n'
    << "-> std::tie(pe, pm) = bs::rem_pio2_straight(pf) = " << '\n'
    << "-> pe = " << pe << '\n'
    << "-> pm = " << pm << '\n';

  float xf = 2.0f;
  float e, m;
  std::tie(e, m) = bs::rem_pio2_straight(xf);
  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =           " << xf << '\n'
    << "-> std::tie(pe, pm) =  bs::rem_pio2_straight(xf) = " << '\n'
    << "-> e =  " << e <<  '\n'
    << "-> m =  " << m <<  '\n';
  return 0;
}
//! [rem_pio2_straight]
