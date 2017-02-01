//==================================================================================================
/*
  Copyright 2017 NumScale SAS

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
  pack_ft p =  {-4, -3, -2, -1, 1, 2, 3, 4};
  pack_ft q =  { 5,  2,  3,  2, 2, 3, 2, 5};
  std::cout << " p = " << p << std::endl
            << " q = " << q << std::endl
            <<  " -> bs::div(bs::ceil,      p, q) = " << bs::div(bs::ceil,      p, q) << std::endl
            <<  " -> bs::div(bs::floor,     p, q) = " << bs::div(bs::floor,     p, q) << std::endl
            <<  " -> bs::div(bs::fix,       p, q) = " << bs::div(bs::fix,       p, q) << std::endl
            <<  " -> bs::div(bs::round,     p, q) = " << bs::div(bs::round,     p, q) << std::endl
            <<  " -> bs::div(bs::nearbyint, p, q) = " << bs::div(bs::nearbyint, p, q) << std::endl;
  return 0;
}
//! [divisions]
