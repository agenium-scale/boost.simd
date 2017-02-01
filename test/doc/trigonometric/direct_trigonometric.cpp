//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [direct_trigonometric]
#include <boost/simd/trigonometric.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <boost/simd/constant/pi.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 8>;

int main()
{
  pack_ft p_pi = bs::enumerate<pack_ft>(-1.0f, 0.25f);
  pack_ft p_ra = p_pi*bs::Pi<pack_ft>();
  pack_ft p_dg = bs::indeg(p_ra);
  std::cout << " p_ra =  " << p_ra << std::endl
            << " p_pi =  " << p_pi << std::endl
            << " p_dg =  " << p_dg << std::endl
            << " -> bs::cos(p_ra) =   " << bs::cos(p_ra)   << std::endl
            << " -> bs::cospi(p_pi) = " << bs::cospi(p_pi) << std::endl
            << " -> bs::cosd(p_dg) =  " << bs::cosd(p_dg)  << std::endl;
  return 0;
}
//! [direct_trigonometric]
