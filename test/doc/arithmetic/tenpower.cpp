//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [tenpower]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;
using pack_it = bs::pack <std::int32_t,4>;

int main()
{
  pack_it pi = {-1,    2,    -3,    4   };

  std::cout
    << "---- simd" << '\n'
    << "<- pi =               " << pi << '\n'
    << "-> bs::tenpower(pi) = " << bs::tenpower(pi) << '\n';

  std::int32_t xi =  4;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xi =               " << xi << '\n'
    << "-> bs::tenpower(xi) = " << bs::tenpower(xi) << '\n';
  return 0;
}
//! [tenpower]
