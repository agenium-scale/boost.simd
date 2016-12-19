//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/successor.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/logical.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/bitincrement.hpp>
#include <boost/simd/constant/two.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{

  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using p_t = bs::pack<T, N>;
  using iT = bd::as_integer_t<T>;
  using i_t =  bs::pack<iT, N>;
  T a1[N],  b[N];
  iT a2[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     a2[i] = i;
     b[i] = bs::successor(a1[i], a2[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  i_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);//logical
  STF_IEEE_EQUAL(bs::successor(aa1, aa2), bb);
}

STF_CASE_TPL("Check successor on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" successor real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::successor;
  using p_t = bs::pack<T>;
  using r_t = decltype(successor(p_t()));

  // specific values tests
  STF_IEEE_EQUAL(successor(bs::Inf<p_t>()), bs::Nan<r_t>());
  STF_EQUAL(successor(bs::Minf<p_t>()), bs::Valmin<r_t>());
  STF_EQUAL(successor(bs::Mone<p_t>()), bs::Mone<r_t>()+bs::Eps<r_t>()/2);
  STF_IEEE_EQUAL(successor(bs::Nan<p_t>()), bs::Nan<r_t>());
  STF_EQUAL(successor(bs::One<p_t>()), bs::One<r_t>()+bs::Eps<r_t>());
  STF_EQUAL(successor(bs::Valmax<p_t>()), bs::Inf<r_t>());
  STF_EQUAL(successor(bs::Zero<p_t>()), bs::Bitincrement<p_t>());
} // end of test for floating_

STF_CASE_TPL (" successor unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::successor;
  using p_t = bs::pack<T>;
  using r_t = decltype(successor(p_t()));

  // specific values tests
  STF_EQUAL(successor(bs::One<p_t>()), bs::Two<r_t>());
  STF_EQUAL(successor(bs::Valmax<p_t>()), bs::Valmax<r_t>());
  STF_EQUAL(successor(bs::Zero<p_t>()), bs::One<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" successor signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::successor;
  using p_t = bs::pack<T>;
  using r_t = decltype(successor(p_t()));

  // specific values tests
  STF_EQUAL(successor(bs::Mone<p_t>()), bs::Zero<r_t>());
  STF_EQUAL(successor(bs::One<p_t>()), bs::Two<r_t>());
  STF_EQUAL(successor(bs::Valmax<p_t>()), bs::Valmax<r_t>());
  STF_EQUAL(successor(bs::Zero<p_t>()), bs::One<r_t>());
} // end of test for signed_int_


STF_CASE_TPL (" successor real 2",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::successor;
  using p_t = bs::pack<T>;

  using ip_t = bd::as_integer_t<p_t>;
  using r_t = decltype(successor(p_t(), ip_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(successor(bs::Inf<p_t>(), bs::Two<ip_t>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(successor(bs::Nan<p_t>(), bs::Two<ip_t>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(successor(bs::Mone<p_t>(), bs::Two<ip_t>()), bs::Mone<r_t>()+bs::Eps<r_t>());
  STF_EQUAL(successor(bs::One<p_t>(), bs::Two<ip_t>()), bs::One<r_t>()+bs::Eps<r_t>()+bs::Eps<r_t>());
  STF_IEEE_EQUAL(successor(bs::Valmax<p_t>(), bs::Two<ip_t>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(successor(bs::Valmax<p_t>(), bs::Four<ip_t>()), bs::Nan<r_t>());
#if !defined(BOOST_SIMD_NO_DENORMALS)
  STF_EQUAL(successor(bs::Zero<p_t>(), bs::Two<ip_t>()), bs::Bitincrement<r_t>()+bs::Bitincrement<r_t>());
#endif
}

STF_CASE_TPL (" successorui_2",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::successor;
  using p_t = bs::pack<T>;

  using ip_t = bd::as_integer_t<p_t>;
  using r_t = decltype(successor(p_t(), ip_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);
  STF_EQUAL(successor(bs::Four<p_t>(), bs::Two<ip_t>()), r_t(6));
  STF_EQUAL(successor(bs::One<p_t>(), bs::Two<ip_t>()), r_t(3));
  STF_EQUAL(successor(bs::Valmax<p_t>(), bs::Two<ip_t>()), bs::Valmax<r_t>());
  STF_EQUAL(successor(bs::Valmax<p_t>(), bs::Four<ip_t>()), bs::Valmax<r_t>());
}

STF_CASE_TPL (" successorsi_2",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::successor;
  using p_t = bs::pack<T>;

  using ip_t = bd::as_integer_t<p_t>;
  using r_t = decltype(successor(p_t(), ip_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);
  STF_EQUAL(successor(bs::Mone<p_t>(), bs::Two<ip_t>()), bs::One<r_t>());
  STF_EQUAL(successor(bs::One<p_t>(), bs::Two<ip_t>()), r_t(3));
  STF_EQUAL(successor(bs::Valmax<p_t>(), bs::Two<ip_t>()), bs::Valmax<r_t>());
  STF_EQUAL(successor(bs::Valmax<p_t>(), bs::Four<ip_t>()), bs::Valmax<r_t>());
} // end of test for signed_int_
