//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [direct_hyperbolic]
#include <boost/simd/hyperbolic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 8>;

int main()
{
  pack_ft p = bs::enumerate<pack_ft>(-4.0f, 1.0f);
  std::cout << " p =  " << p << std::endl
            <<  " -> bs::cosh(p) =  " << bs::cosh(p) << std::endl
            <<  " -> bs::sinh(p) =  " << bs::sinh(p) << std::endl
            <<  " -> bs::tanh(p) =  " << bs::tanh(p) << std::endl
            <<  " -> bs::sech(p) =  " << bs::sech(p) << std::endl
            <<  " -> bs::csch(p) =  " << bs::csch(p) << std::endl;
  pack_ft s, c;
  std::tie(s, c) = bs::sinhcosh(p);
  std::cout <<  " using sinhcosh " << std::endl
            <<  " -> bs::cosh(p) =  " << c << std::endl
            <<  " -> bs::sinh(p) =  " << s << std::endl;
  return 0;
}
//! [direct_hyperbolic]
