//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/minmod.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/mtwo.hpp>

STF_CASE_TPL (" minmod real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::minmod;
  using r_t = decltype(minmod(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(minmod(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(minmod(bs::Minf<T>(), bs::Minf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(minmod(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(minmod(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(minmod(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(minmod(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_IEEE_EQUAL(minmod(bs::Nan<T>(), bs::One<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(minmod(bs::One<T>(), bs::Nan<T>()), bs::One<T>());
  STF_IEEE_EQUAL(minmod(bs::Nan<T>(), bs::Zero<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(minmod(bs::Zero<T>(), bs::Nan<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::One<T>(), bs::Two<T>()), bs::One<T>());
  STF_EQUAL(minmod(bs::Two<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(minmod(bs::One<T>(), bs::Mtwo<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::Mtwo<T>(), bs::One<T>()), bs::Zero<T>());
} // end of test for floating_

STF_CASE_TPL (" minmodunsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::minmod;
  using r_t = decltype(minmod(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(minmod(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(minmod(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::One<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::Zero<T>(), bs::One<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" minmodsigned_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::minmod;
  using r_t = decltype(minmod(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(minmod(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(minmod(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(minmod(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::One<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::Zero<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::Mone<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::Zero<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::One<T>(), bs::Mtwo<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::Mtwo<T>(), bs::One<T>()), bs::Zero<T>());
} // end of test for signed_int_


STF_CASE_TPL("Check minmod on nans  pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<T>::static_size;
  {
    using p_t = bs::pack<T, N>;
    p_t n =  bs::Nan<p_t>();
    p_t o =  bs::One<p_t>();
    STF_IEEE_EQUAL(bs::minmod(n, o), n);
    STF_IEEE_EQUAL(bs::minmod(o, n), o);
  }

}
