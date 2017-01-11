//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [majority]
#include <boost/simd/predicates.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;

int main()
{
  pack_ft pf = { 0.0f, 1.0f, -1.0f, -2.0f  };
  pack_ft qf = { 0.0f, 0.0f, -0.0f, -2.0f  };
  pack_ft rf = { 0.0f, 1.0f, -0.0f, -2.0f  };

  std::cout
    << "---- simd" << '\n'
    << "<- pf =                  " << pf << '\n'
    << "<- qf =                  " << qf << '\n'
    << "<- rf =                  " << rf << '\n'
    << "-> bs::majority(pf, qf, rf) = " << bs::majority(pf, qf, rf) << '\n';

  float xf = 1.0f;
  float yf = 2.0;
  float zf = 0.0;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =                  " << xf << '\n'
    << "<- yf =                  " << yf << '\n'
    << "<- zf =                  " << zf << '\n'
    << "-> bs::majority(xf, yf, zf) = " << bs::majority(xf, yf, zf) << '\n';
  return 0;
}
//! [majority]
