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
#include <boost/simd/function/enumerate.hpp>
#include <iostream>
#include <iomanip>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 8>;


int main()
{
  using namespace std;
  pack_ft pf = bs::enumerate<pack_ft>(-2.56, 0.51);
  cout <<  "simd" << endl
       << " pf =  " << pf  << " -> bs::ceil(pf) = " << bs::ceil(pf) << endl
       << "scalar"  << endl;
  for(size_t i=0; i < pack_ft::static_size; i++)
  {
    cout << " xf = " << setw(12) << left << pf[i] << endl
         << " -> bs::ceil(xf) = " << setw(5) << bs::ceil(pf[i]) << endl;
  }
  return 0;
}
//! [ceil]
