//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/bitfloating.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/bitincrement.hpp>

STF_CASE_TPL (" bitfloating int_convert",  (int32_t)(int64_t))
{
  namespace bs = boost::simd;
  using bs::bitfloating;
  using r_t = decltype(bitfloating(T()));
  typedef  boost::dispatch::as_floating_t<T>  wished_r_t;

  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
#if !defined(BOOST_SIMD_NO_DENORMALS)
  STF_EQUAL(bitfloating(bs::One<T>()), bs::Bitincrement<r_t>());
  STF_EQUAL(bitfloating(bs::Mone<T>()), -bs::Bitincrement<r_t>());
#endif
  STF_EQUAL(bitfloating(bs::Zero<T>()), bs::Zero<r_t>());
}

STF_CASE_TPL (" bitfloating uint_convert",  (uint32_t)(uint64_t))
{
  namespace bs = boost::simd;
  using bs::bitfloating;
  using r_t = decltype(bitfloating(T()));
  typedef boost::dispatch::as_floating_t<T>  wished_r_t;

  // return type conformity test
  STF_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  STF_EQUAL(bitfloating(bs::One<T>()), bs::Bitincrement<r_t>());
  STF_EQUAL(bitfloating(bs::Zero<T>()), bs::Zero<r_t>());
}
