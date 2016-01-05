//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/rem_pio2_straight.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/constant/pio_2.hpp>


STF_CASE_TPL (" rem_pio2_straight",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::rem_pio2_straight;
  using iT = bd::as_integer_t<T>;
  using r_t = decltype(rem_pio2_straight(T()));


  STF_EXPR_IS( (rem_pio2_straight(T()))
                  , (std::pair<iT,T>)
                  );

  {
    T r1;
    STF_EQUAL( rem_pio2_straight(bs::Pio_2<T>(), r1), bs::One<iT>());
    STF_ULP_EQUAL( r1, bs::Zero<T>(), 0.5);
    STF_EQUAL( rem_pio2_straight(bs::Pio_4<T>(), r1), bs::One<iT>());
    STF_ULP_EQUAL( r1, -bs::Pio_4<T>(), 0.5);
  }
  {
    r_t res = rem_pio2_straight(bs::Pio_4<T>());
    STF_ULP_EQUAL( res.first, bs::One<iT>(), 0.5);
    STF_ULP_EQUAL( res.second, -bs::Pio_4<T>(), 0.5);
  }
  {
    r_t res = rem_pio2_straight(bs::Zero<T>());
    STF_ULP_EQUAL( res.first, bs::One<iT>(), 0.5);
    STF_ULP_EQUAL( res.second, -bs::Pio_2<T>(), 0.5);
  }

}
