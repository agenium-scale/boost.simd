//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/erfcx.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
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

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = -7.0*T(i)/N;
    b[i] = bs::erfcx(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::erfcx(aa1), bb, 6);

}

STF_CASE_TPL("Check erfcx2 on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" erfcx",  (double))//STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::erfcx;
  using p_t = bs::pack<T>;
  using r_t = decltype(erfcx(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_ULP_EQUAL(erfcx(bs::Mzero<p_t>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(erfcx(bs::Zero<p_t>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(erfcx(bs::Halfeps<p_t>()),p_t(0.999999999999999874724746818321), 0);
  STF_ULP_EQUAL(erfcx(p_t(0.1)), p_t(0.896456979969126641931883748644), 0.5);
  STF_ULP_EQUAL(erfcx(p_t(0.4)), p_t(0.670787785294761523329412474468), 0);

  STF_ULP_EQUAL(erfcx(bs::Half<p_t>()), p_t(0.615690344192925874870793422684), 0);
  STF_ULP_EQUAL(erfcx(bs::One<p_t>()), p_t(0.427583576155807004410750344491), 0.5);
  STF_ULP_EQUAL(erfcx(bs::Two<p_t>()), p_t(0.255395676310505743865088580909), 0.5);
  STF_ULP_EQUAL(erfcx(bs::Four<p_t>()), p_t(0.1369994576250613898894451714), 0.5);
  STF_ULP_EQUAL(erfcx(bs::Five<p_t>()), p_t(0.110704637733068626370212086492), 0);
  STF_ULP_EQUAL(erfcx(p_t(27)), p_t(0.0208816079904209406740944901929), 0);
  STF_ULP_EQUAL(erfcx(p_t(100)), p_t(0.00564161378298943290355645700695), 0);
  STF_ULP_EQUAL(erfcx(bs::Valmax<p_t>())     ,bs::rsqrt(bs::Pi<p_t>())/bs::Valmax<p_t>(), 0);

  STF_ULP_EQUAL(erfcx(-bs::Halfeps<p_t>()), p_t(1.00000000000000012527525318168), 0);
  STF_ULP_EQUAL(erfcx(-p_t(0.1))          , p_t(1.12364335419920947315244716516), 0.5);
  STF_ULP_EQUAL(erfcx(-p_t(0.4))          , p_t(1.67623395668885894670780969932), 0);

  STF_ULP_EQUAL(erfcx(-bs::Half<p_t>())   , p_t(1.95236048918255709327604771344), 0.5);
  STF_ULP_EQUAL(erfcx(-bs::One<p_t>())    , p_t(5.00898008076228346630982459821), 0.5);
  STF_ULP_EQUAL(erfcx(-bs::Two<p_t>())    , p_t(108.940904389977972412355433825), 0);
  STF_ULP_EQUAL(erfcx(-bs::Four<p_t>())   , p_t(17772220.9040162876484646575921) , 0.5);
  STF_ULP_EQUAL(erfcx(-bs::Five<p_t>())   , p_t(144009798674.661040410589634306), 0);
  STF_ULP_EQUAL(erfcx(-p_t(27))           , bs::Inf<p_t>(), 0);
  STF_ULP_EQUAL(erfcx(-p_t(100))          , bs::Inf<p_t>(), 0);
  STF_ULP_EQUAL(erfcx(-bs::Valmax<p_t>())     , bs::Inf<p_t>(), 0);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(erfcx(bs::Inf<p_t>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(erfcx(bs::Nan<p_t>()), bs::Nan<r_t>(), 0);
#endif
}
