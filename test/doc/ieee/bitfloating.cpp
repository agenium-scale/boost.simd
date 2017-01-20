//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [bitfloating]
#include <boost/simd/ieee.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>


namespace bs =  boost::simd;
using pack_ft = bs::pack <std::int32_t, 4>;

int main()
{
  pack_ft pf = {1, 2, -1, 5};

  std::cout
    << "---- simd" << '\n'
    << "<- pf =                  " << pf << '\n'
    << "-> bs::bitfloating(pf) = " << bs::bitfloating(pf) << '\n';

  std::int32_t xf = 2;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =                  " << xf << '\n'
    << "-> bs::bitfloating(xf) = " << bs::bitfloating(xf) << '\n';
  return 0;
}
//! [bitfloating]
