//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/rem_pio2.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pio_2.hpp>

STF_CASE_TPL (" rem_pio2",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::rem_pio2;
  using iT = bd::as_integer_t<T>;
  using r_t = decltype(rem_pio2(T()));

  // specific values tests
  using r_t0 = typename boost::fusion::result_of::value_at_c<r_t,0>::type;
  using r_t1 = typename boost::fusion::result_of::value_at_c<r_t,1>::type;
  using r_t2 = typename boost::fusion::result_of::value_at_c<r_t,2>::type;

  {

    r_t res = rem_pio2(bs::Zero<T>());
    STF_ULP_EQUAL( boost::fusion::get<0>(res), bs::Zero<r_t0>(), 1);
    STF_ULP_EQUAL( boost::fusion::get<1>(res), bs::Zero<r_t1>(), 1);
    STF_ULP_EQUAL( boost::fusion::get<2>(res), bs::Zero<r_t2>(), 1);
    STF_ULP_EQUAL( boost::fusion::get<0>(res), bs::Zero<T>(), 1);
    STF_ULP_EQUAL( boost::fusion::get<1>(res), bs::Zero<T>(), 1);
    STF_ULP_EQUAL( boost::fusion::get<2>(res), bs::Zero<iT>(), 1);
    T xr;
    iT n = rem_pio2(bs::Zero<T>(), xr);
    STF_ULP_EQUAL( xr, bs::Zero<T>(), 1);
    STF_ULP_EQUAL( n, bs::Zero<iT>(), 1);

  }
} // end of test for floating_

STF_CASE_TPL (" rem_pio2 targeted",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::rem_pio2;
  using iT = bd::as_integer_t<T>;

  iT n;
  T x = bs::Pio_2<T>(), xr;
  n = rem_pio2(x, xr, bd::as_<bs::tag::big_tag>());
  STF_ULP_EQUAL( xr, bs::Zero<T>(), 0.5);
  STF_ULP_EQUAL( n, bs::One<iT>(), 0);

  n = rem_pio2(x, xr, bd::as_<bs::tag::medium_tag>());
  STF_ULP_EQUAL( xr, bs::Zero<T>(), 0.5);
  STF_ULP_EQUAL( n, bs::One<iT>(), 0);

  n = rem_pio2(x, xr, bd::as_<bs::tag::small_tag>());
  STF_ULP_EQUAL( xr, bs::Zero<T>(), 0.5);
  STF_ULP_EQUAL( n, bs::One<iT>(), 0);

  n = rem_pio2(x, xr, bd::as_<bs::tag::very_small_tag>());
  STF_ULP_EQUAL( xr, bs::Zero<T>(), 0.5);
  STF_ULP_EQUAL( n, bs::One<iT>(), 0);
}
