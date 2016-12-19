//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/rem_pio2_medium.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/half.hpp>

STF_CASE_TPL (" rem_pio2_medium",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::rem_pio2_medium;
  using r_t = decltype(rem_pio2_medium(T()));

  STF_TYPE_IS( r_t, (std::pair<T,T>));

  {
    r_t res = rem_pio2_medium(bs::Zero<T>());
    STF_ULP_EQUAL( res.first, bs::Zero<T>(), 0.5);
    STF_ULP_EQUAL( res.second, bs::Zero<T>(), 0.5);
  }
  {
    r_t res = rem_pio2_medium(bs::Pio_4<T>());
    STF_ULP_EQUAL( res.first, bs::Zero<T>(), 0.5);
    STF_ULP_EQUAL( res.second, bs::Pio_4<T>(), 0.5);
  }
  {
    r_t res = rem_pio2_medium(bs::Pio_2<T>());
    STF_ULP_EQUAL( res.first, bs::One<T>(), 0.5);
    STF_ULP_EQUAL( res.second, bs::Zero<T>(), 0.5);
  }
  {
    r_t res = rem_pio2_medium(bs::Pio_4<T>()*bs::Half<T>());
    STF_ULP_EQUAL( res.first, bs::Zero<T>(), 0.5);
    STF_ULP_EQUAL(res.second, bs::Pio_4<T>()*bs::Half<T>(), 0.5);
  }
}


