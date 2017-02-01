//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [sqrt1pm1]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/eps.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;

int main()
{
  pack_ft pf = {-1.0f, 0.0f, 1.0f, bs::Eps<float>()};

  std::cout
    << "---- simd" << '\n'
    << "<- pf =               " << pf << '\n'
    << "-> bs::sqrt1pm1(pf) = " << bs::sqrt1pm1(pf) << '\n';

  float xf = bs::Eps<float>();

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =               " << xf << '\n'
    << "-> bs::sqrt1pm1(xf) = " << bs::sqrt1pm1(xf) << '\n';
  return 0;
}
//! [sqrt1pm1]
