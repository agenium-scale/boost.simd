//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [roundings]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 8>;

int main()
{
  pack_ft p = {-1.1f, -1.5f, -1.6f, -2.1f, -2.5f, -2.6f,  1.1f, 1.5f };
  std::cout << " p =  " << p << std::endl
            <<  " -> bs::ceil(p) =       " << bs::ceil(p)      << std::endl
            <<  " -> bs::floor(p) =      " << bs::floor(p)     << std::endl
            <<  " -> bs::fix(p) =        " << bs::fix(p)       << std::endl
            <<  " -> bs::round(p) =      " << bs::round(p)     << std::endl
            <<  " -> bs::nearbyint(p) =  " << bs::nearbyint(p) << std::endl;
  return 0;
}
//! [roundings]
