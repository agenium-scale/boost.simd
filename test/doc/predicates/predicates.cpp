//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [predicates]
#include <boost/simd/predicates.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/mindenormal.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 8>;

int main()
{
  pack_ft p = {0.0f, 1.0f, -1.0f, 2.5f, -2.5f, bs::Nan<float>(), bs::Minf<float>(), bs::Mindenormal<float>()};
  std::cout << " p =  " << p << std::endl
            <<  " -> bs::is_finite(p) =    " << bs::is_finite(p)   << std::endl
            <<  " -> bs::is_inf(p) =       " << bs::is_inf(p)      << std::endl
            <<  " -> bs::is_denormal(p) =  " << bs::is_denormal(p) << std::endl
            <<  " -> bs::is_flint(p) =     " << bs::is_flint(p)    << std::endl
            <<  " -> bs::is_odd(p) =       " << bs::is_odd(p)      << std::endl
            <<  " -> bs::is_nan(p) =       " << bs::is_nan(p)      << std::endl;
  return 0;
}
//! [predicates]
