//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/ffs.hpp>
#include <boost/simd/function/tofloat.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>



STF_CASE_TPL (" toint real", (double))
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::toint;
  using bs::tofloat;
  using p_t = bs::pack<T>;
  using r_t = decltype(toint(p_t()));
  STF_TYPE_IS(r_t, r_t);

// for(int64_t i=4294967296; i <8589934592*1000 ; i+= 100001)
//  {
//    int64_t j1 =  i&3ul;
//    r_t z = bs::bitwise_and(toint(p_t(i)), r_t(3));
//    if (z[0] !=  j1) {
//      std::cout << "failed at " << i << std::endl;
//      break;
//    }

//  }


  for(int64_t i=0; i < 10/*4.2950e+09*/ ; i++)
 {
//    int64_t j1 =  i&3ul;
    r_t z = bs::bitwise_and(toint(p_t(i)), r_t(3));
    int64_t e = ffs(tofloat(i));
    std::cout << i <<  "  " << e << std::endl;

//     int64_t mask =0x3ul;
//     if (z[0] !=  j1) {
//       std::cout << "failed at " << i << std::endl;
//       break;
//     }

 }

} // end of test for floating_

