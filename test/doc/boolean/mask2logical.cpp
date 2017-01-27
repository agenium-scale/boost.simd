//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [mask2logical]
#include <boost/simd/boolean.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/nan.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 4>;

int main()
{
  pack_ft pf = { bs::Nan<float>(), 0.0f,  bs::Nan<float>(), 0.0 };

  std::cout
    <<  "---- simd" << '\n'
    << " <- pf =                   " << pf << '\n'
    << " -> bs::mask2logical(pf) = " << bs::mask2logical(pf) << '\n';


  std::int32_t xf =  bs::Nan<float>(), yf = 0.0f;

  std::cout
    << "---- scalar"  << '\n'
    << " xf =                      " << xf << '\n'
    << " yf =                      " << yf << '\n'
    << " -> bs::mask2logical(xf) = " << bs::mask2logical(xf) << '\n'
    << " -> bs::mask2logical(yf) = " << bs::mask2logical(yf) << '\n';
  return 0;
}
//! [mask2logical]
