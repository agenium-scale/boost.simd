//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/erfcx.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/five.hpp>
#include <boost/simd/function/rsqrt.hpp>

STF_CASE_TPL (" erfcx",  (double))//STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::erfcx;
  using r_t = decltype(erfcx(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_ULP_EQUAL(erfcx(bs::Mzero<T>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(erfcx(bs::Zero<T>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(erfcx(bs::Halfeps<T>()),T(0.999999999999999874724746818321), 0.5);
  STF_ULP_EQUAL(erfcx(T(0.1)), T(0.896456979969126641931883748644), 0.5);
  STF_ULP_EQUAL(erfcx(T(0.4)), T(0.670787785294761523329412474468), 0.5);

  STF_ULP_EQUAL(erfcx(bs::Half<T>()), T(0.615690344192925874870793422684), 0.5);
  STF_ULP_EQUAL(erfcx(bs::One<T>()), T(0.427583576155807004410750344491), 0.5);
  STF_ULP_EQUAL(erfcx(bs::Two<T>()), T(0.255395676310505743865088580909), 0.5);
  STF_ULP_EQUAL(erfcx(bs::Four<T>()), T(0.1369994576250613898894451714), 0.5);
  STF_ULP_EQUAL(erfcx(bs::Five<T>()), T(0.110704637733068626370212086492), 0.5);
  STF_ULP_EQUAL(erfcx(T(27)), T(0.0208816079904209406740944901929), 0.5);
  STF_ULP_EQUAL(erfcx(T(100)), T(0.00564161378298943290355645700695), 0.5);
  STF_ULP_EQUAL(erfcx(bs::Valmax<T>())     ,bs::rsqrt(bs::Pi<T>())/bs::Valmax<T>(), 0.5);

  STF_ULP_EQUAL(erfcx(-bs::Halfeps<T>()), T(1.00000000000000012527525318168), 0.5);
  STF_ULP_EQUAL(erfcx(-T(0.1))          , T(1.12364335419920947315244716516), 0.5);
  STF_ULP_EQUAL(erfcx(-T(0.4))          , T(1.67623395668885894670780969932), 0.5);

  STF_ULP_EQUAL(erfcx(-bs::Half<T>())   , T(1.95236048918255709327604771344), 0.5);
  STF_ULP_EQUAL(erfcx(-bs::One<T>())    , T(5.00898008076228346630982459821), 0.5);
  STF_ULP_EQUAL(erfcx(-bs::Two<T>())    , T(108.940904389977972412355433825), 0.5);
  STF_ULP_EQUAL(erfcx(-bs::Four<T>())   , T(17772220.9040162876484646575921) , 0.5);
  STF_ULP_EQUAL(erfcx(-bs::Five<T>())   , T(144009798674.661040410589634306), 0.5);
  STF_ULP_EQUAL(erfcx(-T(27))           , bs::Inf<T>(), 0.5);
  STF_ULP_EQUAL(erfcx(-T(100))          , bs::Inf<T>(), 0.5);
  STF_ULP_EQUAL(erfcx(-bs::Valmax<T>())     , bs::Inf<T>(), 0.5);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(erfcx(bs::Inf<T>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(erfcx(bs::Nan<T>()), bs::Nan<r_t>());
#endif
}
