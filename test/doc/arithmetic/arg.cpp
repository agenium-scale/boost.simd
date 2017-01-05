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
#include <boost/simd/constant/one.hpp>
#include <iostream>
#include <iomanip>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 8>;

int main()
{
  using namespace std;
  pack_ft pf = {-1.0f, -0.0f, 0.0f, 1.0f, -bs::Nan<float>(), bs::Nan<float>(), bs::Inf<float>(), bs::Minf<float>()};
  cout <<  "simd" << endl
       << " pf =  " << pf  << " -> bs::arg(pf) =                  " << bs::arg(pf)                 << endl
       << " pf =  " << pf  << " -> bs::pedantic_(bs::arg)(pf) =   " << bs::pedantic_(bs::arg)(pf)  << endl
       << "scalar"  << endl;
  for(size_t i=0; i < pack_ft::static_size; i++)
  {
    cout << " xf = " << setw(8) << left << pf[i] << " -> bs::arg(xf) =                  " << setw(8) << bs::arg(pf[i])                 << endl
         << " xf = " << setw(8) << left << pf[i] << " -> bs::pedantic_(bs::arg)(xf) =   " << setw(8) << bs::pedantic_(bs::arg)(pf[i])  << endl;
  }
  return 0;
}
//! [arg]
