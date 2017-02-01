//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [tofloat]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_it = bs::pack <std::int32_t,4>;

int main()
{
  pack_it pi = {-1, 2, -3, bs::Valmax<std::int32_t>() };

  std::cout
    << "---- simd" << '\n'
    << "<- pi =              " << pi << '\n'
    << "-> bs::tofloat(pi) = " << bs::tofloat(pi) << '\n';

  std::int16_t xi = -2;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xi =              " << xi << '\n'
    << "-> bs::tofloat(xi) = " << bs::tofloat(xi) << '\n';
  return 0;
}
//! [tofloat]
