//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/rem_pio2_cephes.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pio_4.hpp>

STF_CASE_TPL (" rem_pio2_cephes",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::rem_pio2_cephes;
  using r_t = decltype(rem_pio2_cephes(T()));

  STF_EXPR_IS( (rem_pio2_cephes(T()))
                  , (std::pair<T,T>)
                  );

  {
    r_t res = rem_pio2_cephes(bs::Zero<T>());
    STF_ULP_EQUAL( res.first, bs::Zero<T>(), 0.5);
    STF_ULP_EQUAL( res.second, bs::Zero<T>(), 0.5);
  }
  {
    r_t res = rem_pio2_cephes(bs::Pio_4<T>());
    STF_ULP_EQUAL( res.first, bs::Zero<T>(), 0.5);
    STF_ULP_EQUAL( res.second, bs::Pio_4<T>(), 0.5);
  }
} // end of test for floating_


