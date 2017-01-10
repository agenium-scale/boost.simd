//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [arg]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <iostream>

namespace bs = boost::simd;
using pack_ft = bs::pack <float, 8>;

int main()
{
  pack_ft pf = {  -1.0f,             -0.0f,            0.0f,             1.0f
                , -bs::Nan<float>(), bs::Nan<float>(), bs::Inf<float>(), bs::Minf<float>() };

  std::cout
    <<  "---- simd" << '\n'
    << " <- pf =                         " << pf << '\n'
    << " -> bs::arg(pf) =                " << bs::arg(pf) << '\n'
    << " <- pf =                         " << pf << '\n'
    << " -> bs::pedantic_(bs::arg)(pf) = " << bs::pedantic_(bs::arg)(pf) << '\n'
    << "scalar"  << '\n';

  float xf =  1.0f;
  float yf = -1.0f;

  std::cout
    << "---- scalar"  << '\n'
    << " <- xf =                         "  << xf << '\n'
    << " -> bs::arg(xf) =                " << bs::arg(xf) << '\n'
    << " <- yf =                         "  << yf << '\n'
    << " -> bs::arg(yf) =                " << bs::arg(yf) << '\n';
  return 0;
}
//! [arg]
