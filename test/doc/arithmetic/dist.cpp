//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [dist]
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
  pack_ft pf = { 1.0f, -2.0f, -3.0f, -32700.0f};
  pack_ft qf = { 2.0f, -1.0f, -3.0f,  32721   };
  pack_it pi = { 1,    -2,    -2,    -32700   };
  pack_it qi = { 2,    -1,    -3,     32721   };
  cout <<  "simd" << endl
       << " pf =                                    " << pf  << endl
       << " qf =                                    " << qf  << endl
       << " -> bs::dist(pf, qf)                 =   " << bs::dist(pf, qf)  << endl
       << " pi =                                    " << pi  << endl
       << " qi =                                    " << qi  << endl
       << " -> bs::dist(pi, qi)                 =   " << bs::dist(pi, qi)  << endl
       << " -> bs::saturated_(bs::dist)(pi, qi) =   " << bs::saturated_(bs::dist)(pi, qi)  << endl
       << "scalar"  << endl;
  for(size_t i=0; i < pack_ft::static_size; i++)
  {
    cout
      << " xf =                                  " << setw(8) << left << pf[i] << endl
      << " yf =                                  " << setw(8) << left << qf[i] << endl
      << " -> bs::dist(xf, yf) =                 " << setw(8) << bs::dist(pf[i], qf[i]) << endl
      << " xi =                                  " << setw(8) << left << pi[i] << endl
      << " yi =                                  " << setw(8) << left << qi[i] << endl
      << " -> bs::dist(xi, yi) =                 " << setw(8) << bs::dist(pi[i], qi[i]) << endl
      << " -> bs::saturated_(bs::dist)(xi, yi) = " << setw(8)
                                              << bs::saturated_(bs::dist)(pi[i], qi[i]) << endl;
  }
  return 0;
}
//! [dist]
