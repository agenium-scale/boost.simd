//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [is_equal]
#include <boost/simd/predicates.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/mindenormal.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 8>;

int main()
{
  pack_ft pf = { 0.0f, 1.0f, -1.0f, -2.0f
                , bs::Mindenormal<float>(), bs::Inf<float>(), bs::Minf<float>(), bs::Nan<float>() };
  pack_ft qf = { bs::Mindenormal<float>(), bs::Inf<float>(), bs::Minf<float>(), bs::Nan<float>(),
                 0.0f, 1.0f, -1.0f, -2.0f };

  std::cout
    << "---- simd" << '\n'
    << "<- pf =                  " << pf << '\n'
    << "<- qf =                  " << qf << '\n'
    << "-> bs::is_equal(pf, qf) = " << bs::is_equal(pf, qf) << '\n';

  float xf = 1.0f;
  float yf = bs::Nan<float>();

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =                  " << xf << '\n'
    << "<- yf =                  " << yf << '\n'
    << "-> bs::is_equal(xf, yf) = " << bs::is_equal(xf, yf) << '\n';
  return 0;
}
//! [is_equal]
