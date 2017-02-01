//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [rec]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 8>;
using pack_it = bs::pack <std::int16_t, 8>;

int main()
{
  pack_ft pf = {-2.0f,            2.0f,              0.0f,             -0.0f,
                bs::Inf<float>(), bs::Minf<float>(), bs::Nan<float>(),  1.5f  };
  pack_it pi = {-3, -2, -1, 0, 1, 2, 3, 4};

  std::cout
    << "---- simd" << '\n'
    << "<- pf =                           " << pf << '\n'
    << "-> bs::rec(pf) =                  " << bs::rec(pf) << '\n'
    << "<- pi =                           " << pi << '\n'
    << "-> bs::rec(pi) =                  " << bs::rec(pi) << '\n';

  float xf = 5.0f;
  std::int16_t xi =  0,  yi = 2;

   std::cout
     << "---- scalar"  << '\n'
     << "<- xf =                           " << xf << '\n'
     << "-> bs::rec(xf) =                  " << bs::rec(xf) << '\n'
     << "<- xi =                           " << xi << '\n'
     << "-> bs::rec(xi) =                  " << bs::rec(xi) << '\n'
     << "<- yi =                           " << yi << '\n'
     << "-> bs::rec(yi) =                  " << bs::rec(yi) << '\n';
   return 0;
}
//! [rec]
