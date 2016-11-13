//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/mask2logical.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/logical.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/constant/false.hpp>
#include <boost/simd/meta/as_logical.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;
  using pl_t = bs::pack<bs::logical<T>, N>;

  T a1[N];
  bs::logical<T> b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(0) : bs::Allbits<T>();
     b[i] = bs::mask2logical(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  pl_t bb(&b[0], &b[0]+N);
  STF_EQUAL(bs::mask2logical(aa1), bb);
}

STF_CASE_TPL("Check mask2logical on pack", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL (" mask2logical real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::mask2logical;
  using p_t = bs::pack<T>;

  using bs::logical;
  using lp_t =  bs::as_logical_t<p_t>;

  // return type conformity test
  STF_EXPR_IS( mask2logical(p_t()), lp_t );

  // specific values tests
  STF_EQUAL(mask2logical(p_t(0)), bs::False<p_t>());
  STF_EQUAL(mask2logical(bs::Nan<p_t>()) , bs::True<p_t>());
} // end of test for floating_

STF_CASE_TPL (" mask2logical signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::mask2logical;
  using bs::logical;
  using p_t = bs::pack<T>;
  using lp_t = bs::as_logical_t<p_t>;

  // return type conformity test
  STF_EXPR_IS( mask2logical(p_t()), lp_t );

  // specific values tests
  STF_EQUAL(mask2logical(p_t(0)), bs::False<p_t>());
  STF_EQUAL(mask2logical(p_t(-1)), bs::True<p_t>());
} // end of test for signed_int_
