//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [round]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 8>;
using pack_it =  bs::pack <std::int32_t, 8>;


int main()
{
  pack_ft pf = bs::enumerate<pack_ft>(-2.5678, 0.5123);
  pack_ft qf(1234.5678f);
  pack_it ni = bs::enumerate<pack_it>(-3, 1);

  std::cout
    << "---- simd" << '\n'
    << " <- pf =               " << pf  << '\n'
    << " -> bs::round(pf)    = " << bs::round(pf) << '\n'
    << " <- ni =               " << ni  << '\n'
    << " -> bs::round(qf, ni) = " << bs::round(qf, ni) << '\n'
    << " -> bs::round(pf, 2) = " << bs::round(pf, 2) << '\n';

  float xf = 3.225f;

  std::cout
    << "---- scalar" << '\n'
    << " <- xf =           " << xf<< '\n'
    << " -> bs::round(xf) = " << bs::round(xf) << '\n'
    << " -> bs::round(xf, 2) = " << bs::round(xf, 2) << '\n';
  return 0;
}
//! [round]
