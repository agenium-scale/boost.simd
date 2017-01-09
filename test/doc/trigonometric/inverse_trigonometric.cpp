//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [inverse_trigonometric]
#include <boost/simd/trigonometric.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 8>;

int main()
{
  pack_ft p = bs::enumerate<pack_ft>(-1.0f, 0.25f);
  std::cout << " p =  " << p << std::endl
            << " -> bs::acos(p) =   " << bs::acos(p)   << std::endl
            << " -> bs::acospi(p) = " << bs::acospi(p) << std::endl
            << " -> bs::acosd(p) =  " << bs::acosd(p)  << std::endl;
  return 0;
}
//! [inverse_trigonometric]
