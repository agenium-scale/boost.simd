//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [subadd]
#include <boost/simd/swar.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>


namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;

int main()
{
  pack_ft pf = {2, 2,  1, 1};
  pack_ft qf = {3, 3,  0.5, 0.5};

  std::cout
    << "---- simd" << '\n'
    << "<- pf =                 " << pf << '\n'
    << "<- qf =                 " << qf << '\n'
    << "-> bs::subadd(pf, qi) = " << bs::subadd(pf, qf) << '\n';

  return 0;
}
//! [subadd]
