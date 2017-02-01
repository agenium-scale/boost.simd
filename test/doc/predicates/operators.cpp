//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [operators]
#include <boost/simd/predicates.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/function/if_else.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 8>;

int main()
{
  pack_ft p = {0.0f, 1.0f, -1.0f, 2.5f, -2.5f, bs::Nan<float>(), bs::Minf<float>(), bs::Inf<float>()};
  pack_ft q = bs::if_else(bs::is_odd(p), p, p*2.0f);

  std::cout << " p =  " << p << std::endl
            << " q =  " << q << std::endl
            <<  " -> (p == q) =  " << (p == q) << std::endl
            <<  " -> (p <= q) =  " << (p <= q) << std::endl
            <<  " -> (p >= q) =  " << (p >= q) << std::endl
            <<  " -> (p <  q) =  " << (p <  q) << std::endl
            <<  " -> (p >  q) =  " << (p >  q) << std::endl
            <<  " -> (p != q) =  " << (p != q) << std::endl
            <<  " -> !(p >= q) = " << !(p >= q)<< std::endl;
  return 0;
}
//! [operators]
