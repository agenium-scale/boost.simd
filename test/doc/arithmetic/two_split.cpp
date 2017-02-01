//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [two_split]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/pi.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 4>;

int main()
{
  pack_ft pf = { 1.0f, -2.0f, 3.0f, -4.0 };
  pf *=  bs::Pi<float>();
  pack_ft s, e;
  std::tie(s, e) = bs::two_split(pf);
  std::cout
    <<  "---- simd" << '\n'
    << " <- pf =                                  " << pf << '\n'
    << "  std::tie(s, e) = bs::two_split(pf)    " << '\n'
    << " ->  s =                                  " << s << '\n'
    << " ->  e =                                  " << e << '\n';

  float xf = 3.0f*bs::Pi<float>();
  float ss, se;
  std::tie(ss, se) = bs::two_split(xf);
  std::cout
    << "---- scalar"  << '\n'
    << " xf =                                     " << xf << '\n'
    << "  std::tie(ss, se) = bs::two_split(xf)  " << '\n'
    << " ->  ss =                                 " << ss << '\n'
    << " ->  se =                                 " << se << '\n';

  return 0;
}
//! [two_split]
