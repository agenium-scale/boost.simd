//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/rem_2pi.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/twopi.hpp>
#include <boost/simd/constant/ten.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;

  T a1[N], m[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : -T((i));
     m[i] = bs::rem_2pi(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t mm(&m[0], &m[0]+N);
  STF_IEEE_EQUAL( bs::rem_2pi(aa1), mm);
}

STF_CASE_TPL("Check rem_2pi on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}


STF_CASE_TPL (" rem_2pi",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::rem_2pi;
  using p_t = bs::pack<T>;

  {
    p_t res = rem_2pi(bs::Zero<p_t>());
    STF_ULP_EQUAL( res, bs::Zero<p_t>(), 1.5);
    res = rem_2pi(bs::Pi<p_t>()-bs::Ten<p_t>()*bs::Eps<p_t>());
    STF_ULP_EQUAL( res, bs::Pi<p_t>()-bs::Ten<p_t>()*bs::Eps<p_t>(), 1.5);
    res = rem_2pi(bs::Pi<p_t>()+bs::Ten<p_t>()*bs::Eps<p_t>());
    STF_ULP_EQUAL( res, bs::Ten<p_t>()*bs::Eps<p_t>()-bs::Pi<p_t>(), 1.5);
    res = rem_2pi(bs::Twopi<p_t>());
    STF_ULP_EQUAL( res, bs::Zero<p_t>(), 1.5);
    res = rem_2pi(bs::Pio_2<p_t>());
    STF_ULP_EQUAL( res, bs::Pio_2<p_t>(), 1.5);
  }
} // end of test for floating_
