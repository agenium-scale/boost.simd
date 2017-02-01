//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [modf]
#include <boost/simd/ieee.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>


namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;

int main()
{
  pack_ft px = {1.0f, 2.0f, -1.0f, 0.5f};
  pack_ft pe, pf;
  std::tie(pe, pf) = bs::modf(pf);
  std::cout
    << "---- simd" << '\n'
    << "<- px =                              " << px << '\n'
    << "-> std::tie(pe, pf) = bs::modf(px) = " << '\n'
    << "-> pe =                              " << pe << '\n'
    << "-> pf =                              " << pf << '\n';

  float x = 2.0f;
  float e, f;
  std::tie(e, f) = bs::modf(x);

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =                              " << x << '\n'
    << "-> std::tie(e, f) = bs::modf(x) =    " << '\n'
    << "-> e =                               " << e << '\n'
    << "-> f =                               " << f << '\n';
  return 0;
}
//! [modf]
