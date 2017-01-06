//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [dec]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
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
       << " pf =  " << pf  << endl
       << " -> bs::dec(pf) =                  " << bs::dec(pf)                 << endl
       << " pi =  " << pi  << endl
       << " -> bs::dec(pi) =                  " << bs::dec(pi)                 << endl
       << " -> bs::saturated_(bs::dec(pi)) =  " << bs::saturated_(bs::dec)(pi) << endl
       << "scalar"  << endl;
  for(size_t i=0; i < pack_ft::static_size; i++)
  {
    cout << " xf = " << setw(8) << left << pf[i] << endl
         << " -> bs::dec(xf) =                  " << setw(8) << bs::dec(pf[i])                 << endl
         << " xi = " << setw(8) << left << pi[i] << endl
         << " -> bs::dec(xi) =                  " << setw(8) << bs::dec(pi[i])                 << endl
         << " -> bs::saturated_(bs::dec(pi)) =  " << setw(8) << bs::saturated_(bs::dec)(pi[i]) << endl;
  }
  cout << bs::dec(0u) << std::endl;
}
//! [dec]
