//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [inverse_hyperbolic]
#include <boost/simd/hyperbolic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 8>;

int main()
{
  pack_ft p = bs::enumerate<pack_ft>(-2.0f, 0.5f);
  std::cout << " p =  " << p << std::endl
            <<  " -> bs::acosh(p) =  " << bs::acosh(p) << std::endl
            <<  " -> bs::asinh(p) =  " << bs::asinh(p) << std::endl
            <<  " -> bs::atanh(p) =  " << bs::atanh(p) << std::endl
            <<  " -> bs::asech(p) =  " << bs::asech(p) << std::endl
            <<  " -> bs::acsch(p) =  " << bs::acsch(p) << std::endl;
  return 0;
}
//! [inverse_hyperbolic]
