//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/dist.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/ten.hpp>
#include <boost/simd/constant/mten.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/ratio.hpp>

STF_CASE_TPL (" dist real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::dist;

  STF_EXPR_IS( dist(T(), T()), T );

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(dist(bs::Inf<T>() , bs::Inf<T>()) , bs::Nan<T>());
  STF_IEEE_EQUAL(dist(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(dist(bs::Nan<T>() , bs::Nan<T>()) , bs::Nan<T>());
#endif

  STF_EQUAL(dist(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(dist(bs::Mone<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(dist(bs::One<T>(), bs::Three<T>()), bs::Two<T>());
}

STF_CASE_TPL (" dist integer_ui",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::dist;

  STF_EXPR_IS( dist(T(), T()), T );

  STF_EQUAL(dist(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(dist(bs::One<T>(), bs::Three<T>()), bs::Two<T>());
  STF_EQUAL(dist(bs::Valmax<T>(), bs::Zero<T>()), bs::Valmax<T>());
  STF_EQUAL(dist(bs::Zero<T>(), bs::Valmax<T>()), bs::Valmax<T>());
}

STF_CASE_TPL (" dist integer_si",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::dist;
  STF_EXPR_IS( dist(T(), T()), T );

  STF_EQUAL(dist(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(dist(bs::Mone<T>(), bs::One<T>()), bs::Two<T>());
  STF_EQUAL(dist(bs::One<T>(), bs::Three<T>()), bs::Two<T>());
  STF_EQUAL(dist(bs::Valmax<T>(), bs::Zero<T>()), bs::Valmax<T>());
  STF_EQUAL(dist(bs::Zero<T>(), bs::Valmax<T>()), bs::Valmax<T>());
  STF_EQUAL(dist(bs::Zero<T>(), bs::Valmin<T>()), bs::Valmin<T>());

  STF_EQUAL(dist(bs::Ten<T>(), bs::Mten<T>()), (bs::Ratio<T, 20>()));
  STF_EQUAL(dist(bs::Mten<T>(), bs::Ten<T>()), (bs::Ratio<T, 20>()));
}

