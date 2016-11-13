//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/detail/constant/maxexponent.hpp>
#include <boost/simd/detail/constant/limitexponent.hpp>
#include <boost/simd/detail/constant/minexponent.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/function/scalar/dec.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using iT = bd::as_integer_t<T>;
  using p_t = bs::pack<T, N>;
  using pi_t = bs::pack<iT, N>;

  T a1[N],  b[N], d[N];
  iT a2[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     a2[i] = i%(sizeof(T)*8-1);
     b[i] = bs::ldexp(a1[i], a2[i]);
     d[i] = bs::fast_(bs::ldexp)(a1[i], a2[i]);
   }

  p_t aa1(&a1[0], &a1[0]+N);
  pi_t aa2(&a2[0], &a2[0]+N);
  p_t bb(&b[0], &b[0]+N);
  p_t dd(&d[0], &d[0]+N);
  STF_IEEE_EQUAL(bs::ldexp(aa1, aa2), bb);
  STF_IEEE_EQUAL(bs::fast_(bs::ldexp)(aa1, aa2), dd);
}

STF_CASE_TPL("Check ldexp on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, std::size_t N, typename Env>
void tests(Env& $)
{
  using p_t = bs::pack<T, N>;

  T a1[N],  b[N], c[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-1.*i);
    b[i] = bs::ldexp(a1[i], 2);
    c[i] = bs::fast_(bs::ldexp)(a1[i], 2);
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb(&b[0], &b[0]+N);
  p_t cc(&c[0], &c[0]+N);

  STF_IEEE_EQUAL(bs::ldexp(aa1, 2)            , bb);
  STF_IEEE_EQUAL(bs::fast_(bs::ldexp)(aa1, 2) , cc);
}

STF_CASE_TPL("Check ldexp on pack/scalar" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  tests<T, N>($);
  tests<T, N/2>($);
  tests<T, N*2>($);
}


STF_CASE_TPL("ldexp", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ldexp;
  using p_t = bs::pack<T>;

  using pi_t = bd::as_integer_t<p_t>;
  using r_t = decltype(ldexp(p_t(), pi_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(ldexp(bs::Inf<p_t>(),  2), bs::Inf<r_t>());
  STF_EQUAL(ldexp(bs::Minf<p_t>(), 2), bs::Minf<r_t>());
  STF_IEEE_EQUAL(ldexp(bs::Nan<p_t>(),  2), bs::Nan<r_t>());
#endif

  STF_EQUAL(ldexp(bs::Mone<p_t>(), 2), -bs::Four<r_t>());
  STF_EQUAL(ldexp(bs::One<p_t>(),  2), bs::Four<r_t>());
  STF_EQUAL(ldexp(bs::Zero<p_t>(), 2), bs::Zero<r_t>());
  STF_EQUAL(ldexp(bs::One <p_t>(), bs::Minexponent<p_t>()), bs::Smallestposval<r_t>());
  STF_EQUAL(ldexp(bs::One<p_t>()-bs::Halfeps<p_t>(),  bs::Maxexponent<p_t>()), bs::Valmax<p_t>()/2);
  STF_EQUAL(ldexp(bs::One<p_t>()-bs::Halfeps<p_t>(),  bs::Limitexponent<p_t>()), bs::Valmax<p_t>());

#ifndef BOOST_SIMD_NO_DENORMALS
  using bs::dec;
  STF_EQUAL(ldexp(bs::One <p_t>(), dec(bs::Minexponent<p_t>())), bs::Smallestposval<p_t>()/2);
  STF_EQUAL(ldexp(bs::Two <p_t>(), dec(bs::Minexponent<p_t>())), bs::Smallestposval<p_t>());
  STF_EQUAL(ldexp(bs::Two <p_t>(), dec(bs::Minexponent<p_t>()-1)), bs::Smallestposval<p_t>()/2);
  STF_EQUAL(ldexp(bs::One <p_t>(), bs::Minexponent<p_t>()-5), bs::Smallestposval<p_t>()/32);
#endif
}

STF_CASE_TPL("ldexp", STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ldexp;
 using p_t = bs::pack<T>;
  using pi_t = bd::as_integer_t<p_t>;
  using r_t = decltype(ldexp(p_t(), pi_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  STF_EQUAL(ldexp(bs::One <p_t>(), 2), r_t(4));
  STF_EQUAL(ldexp(bs::Three<p_t>(), 2), r_t(12));
  STF_EQUAL(ldexp(bs::Mone<p_t>(), 2), r_t(-4));
}

