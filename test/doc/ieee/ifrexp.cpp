//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [ifrexp]
#include <boost/simd/ieee.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>


namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;
using pack_it = bs::pack <int32_t, 4>;

int main()
{
  pack_ft pf = {1.0f, 2.0f, -1.0f, 0.5f};
  pack_ft pm;
  pack_it pie;
  std::tie(pm, pie) = bs::ifrexp(pf);
  std::cout
    << "---- simd" << '\n'
    << "<- pf =                                 " << pf << '\n'
    << "-> std::tie(pm, pie) = bs::ifrexp(pf) = " << '\n'
    << "-> pm  =                                " << pm << '\n'
    << "-> pie =                                " << pie<< '\n'   ;

  float xf = 2.0f;
  float m;
  std::int32_t ie;
  std::tie(m, ie) = bs::ifrexp(xf);
  std::cout
    << "---- scalar"  << '\n'
    << " xf =                                   " << xf << '\n'
    << "-> std::tie(m, ie) = bs::ifrexp(xf) =   " << '\n'
    << "-> m  =                                 " << m << '\n'
    << "-> ie =                                 " << ie << '\n'   ;

  return 0;
}
//! [ifrexp]
