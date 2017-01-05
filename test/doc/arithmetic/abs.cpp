//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [abs]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/minf.hpp>
#include <iostream>
#include <iomanip>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 4>;
using pack_it =  bs::pack <std::int16_t,4>;

int main()
{
  using namespace std;
  pack_ft pf = {-1.0f, 2.0f, -3.0f, -32768.0f};
  pack_it pi = {-1,    2,    -3,    -32768   };
  cout <<  "simd" << endl
       << " pf =  " << pf  << " -> bs::abs(pf) =                  " << bs::abs(pf)                 << endl
       << " pi =  " << pi  << " -> bs::abs(pi) =                  " << bs::abs(pi)                 << endl
       << " pi =  " << pi  << " -> bs::saturated_(bs::abs(pi)) =  " << bs::saturated_(bs::abs)(pi) << endl
       << " pi =  " << pi  << " -> bs::std_(bs::abs)(pi) =        " << bs::std_(bs::abs)(pi)       << endl
       << "scalar"  << endl;
  for(size_t i=0; i < pack_ft::static_size; i++)
  {
    cout << " xf = " << setw(8) << left << pf[i] << " -> bs::abs(xf) =                  " << setw(8) << bs::abs(pf[i])                 << endl
         << " xi = " << setw(8) << left << pi[i] << " -> bs::abs(xi) =                  " << setw(8) << bs::abs(pi[i])                 << endl
         << " xi = " << setw(8) << left << pi[i] << " -> bs::saturated_(bs::abs(pi)) =  " << setw(8) << bs::saturated_(bs::abs)(pi[i]) << endl
         << " xi = " << setw(8) << left << pi[i] << " -> bs::std_(bs::abs)(pi) =        " << setw(8) << bs::std_(bs::abs)(pi[i])       << endl;
  }
  return 0;
}
//! [abs]
