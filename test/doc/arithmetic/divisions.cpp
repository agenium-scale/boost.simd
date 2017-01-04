//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [divisions]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 8>;

int main()
{
  pack_ft p =    {-4, -3, -2, -1, 1, 2, 3, 4};
  pack_ft pp1 =  { 5,  2,  3,  2, 2, 3, 2, 5};
  std::cout << " p =   " << p << std::endl
            << " pp1 = " << pp1 << std::endl
            <<  " -> bs::div(bs::ceil,  p, pp1) =      " << bs::div(bs::ceil, p, pp1)      << std::endl
            <<  " -> bs::div(bs::floor, p, pp1) =      " << bs::div(bs::floor, p, pp1)     << std::endl
            <<  " -> bs::div(bs::fix,   p, pp1) =      " << bs::div(bs::fix,  p, pp1)     << std::endl
            <<  " -> bs::div(bs::round, p, pp1) =      " << bs::div(bs::round, p, pp1)     << std::endl
            <<  " -> bs::div(bs::nearbyint, p, pp1) =  " << bs::div(bs::nearbyint, p, pp1) << std::endl;
  return 0;
}
//! [divisions]
