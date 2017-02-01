//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [saturated_abs]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/minf.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 4>;
using pack_it =  bs::pack <std::int16_t,4>;

int main()
{
  pack_ft pf = {-1.0f, 2.0f, -3.0f, bs::Minf<float>()       };
  pack_it pi = {-1,    2,    -3,    bs::Minf<std::int16_t>()};
  std::cout << " pf =  " << pf  << " -> bs::abs(pf) =                  " << bs::abs(pf)                 << std::endl;
  std::cout << " pi =  " << pi  << " -> bs::abs(pi) =                  " << bs::abs(pi)                 << std::endl;
  std::cout << " pi =  " << pi  << " -> bs::saturated_(bs::abs(pi)) =  " << bs::saturated_(bs::abs)(pi) << std::endl;
  return 0;
}
//! [saturated_abs]
