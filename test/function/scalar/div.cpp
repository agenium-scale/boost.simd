//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/div.hpp>
#include <simd_test.hpp>
//#include <nontrivial.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/options.hpp>
#include <boost/simd/function/ceil.hpp>

STF_CASE_TPL( "Check div behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::div;
  using r_t = decltype(div(T(), T()));
  STF_TYPE_IS(r_t, T);

#ifndef STF_NO_INVALIDS
  STF_IEEE_EQUAL(div(bs::Inf<T>(),  bs::Inf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(div(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(div(bs::Nan<T>(),  bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_IEEE_EQUAL(div(bs::One<T>(),bs::Zero<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(div(bs::Zero<T>(), bs::Zero<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(div(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
}


// STF_CASE_TPL( "Check div behavior with fast option", STF_IEEE_TYPES )
// {
//   namespace bs = boost::simd;
//   using bs::div;
//   using bs::fast_;

//   STF_EQUAL(div(T(1), T(2), fast_), T(1/2.0));
// }


STF_CASE_TPL( "Check div behavior with options", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using bs::div;
//   using r_t = decltype(div(T(), T()));
//   STF_TYPE_IS(r_t, T);
  std::cout << stf::type_id(bs::ceil) << std::endl;//div(bs::One<T>(), bs::Two<T>(), bs::ceil);
//  STF_IEEE_EQUAL(div(bs::One<T>(), bs::Two<T>(), bs::ceil), bs::One<r_t>());
//   STF_IEEE_EQUAL(div(bs::One<T>(), bs::Two<T>(), bs::floor), bs::Zero<r_t>());
//   STF_IEEE_EQUAL(div(bs::One<T>(), bs::Two<T>(), bs::round), bs::One<r_t>());
//   STF_IEEE_EQUAL(div(bs::One<T>(), bs::Two<T>(), bs::round2even), bs::Zero<r_t>());
//   STF_IEEE_EQUAL(div(bs::One<T>(), bs::Two<T>(), bs::fix), bs::Zero<r_t>());
}
