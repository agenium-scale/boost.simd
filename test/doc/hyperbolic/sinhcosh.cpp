//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [sinhcosh]
#include <boost/simd/hyperbolic.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 4>;

int main()
{
  pack_ft pf = { 1.0f, -2.0f, 3.0f, -4.0 };
  pack_ft s, e;
  std::tie(s, e) = bs::sinhcosh(pf);
  std::cout
    <<  "---- simd" << '\n'
    << " <- pf =                                  " << pf << '\n'
    << "  std::tie(s, e) = bs::sinhcosh(pf, qf)   " << '\n'
    << " ->  s =                                  " << s << '\n'
    << " ->  e =                                  " << e << '\n';

  float xf = 3.0f;
  float ss, se;
  std::tie(ss, se) = bs::sinhcosh(xf);
  std::cout
    << "---- scalar"  << '\n'
    << " xf =                                     " << xf << '\n'
    << "  std::tie(ss, se) = bs::sinhcosh(xf, yf) " << '\n'
    << " ->  ss =                                 " << ss << '\n'
    << " ->  se =                                 " << se << '\n';

  return 0;
}
//! [sinhcosh]
