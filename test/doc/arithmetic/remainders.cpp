//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [remainders]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 8>;

int main()
{
  pack_ft p = {-4, -3, -2, -1, 1, 2, 3, 4};
  pack_ft q = { 5,  2,  3,  2, 2, 3, 2, 5};
  std::cout << " p = " << p << std::endl
            << " q = " << q << std::endl
            <<  " -> bs::rem(bs::ceil,      p, q) = " << bs::rem(bs::ceil,      p, q) << std::endl
            <<  " -> bs::rem(bs::floor,     p, q) = " << bs::rem(bs::floor,     p, q) << std::endl
            <<  " -> bs::rem(bs::fix,       p, q) = " << bs::rem(bs::fix,       p, q) << std::endl
            <<  " -> bs::rem(bs::round,     p, q) = " << bs::rem(bs::round,     p, q) << std::endl
            <<  " -> bs::rem(bs::nearbyint, p, q) = " << bs::rem(bs::nearbyint, p, q) << std::endl;
  return 0;
}
//! [remainders]
