//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [lookup]
#include <boost/simd/swar.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>


namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;
using pack_it = bs::pack <std::int32_t, 4>;

int main()
{
  pack_ft pf = {1.0f, 2.0f, -1.0f, 0.5f};
  pack_it qi = {1, 2, -1, 3};

  std::cout
    << "---- simd" << '\n'
    << "<- pf =                " << pf << '\n'
    << "<- qi =                " << qi << '\n'
    << "-> bs::lookup(pf, qi) = " << bs::lookup(pf, qi) << '\n';

  return 0;
}
//! [lookup]
