//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/sel.hpp>
#include <simd_test.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
// #include <boost/simd/constant/true.hpp>
// #include <boost/simd/constant/false.hpp>
//TODO LOGICAL

STF_CASE_TPL (" sel integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sel;
  using bs::logical;
  using r_t = decltype(sel(T(),T(),T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(sel( bs::One<T>(), bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(sel( bs::One<T>(), bs::Zero<T>(),bs::Two<T>()), bs::Zero<r_t>());
  STF_EQUAL(sel( bs::Zero<T>(), bs::One<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for integer_

STF_CASE_TPL (" sel real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::sel;

  using bs::logical;
  using r_t = decltype(sel(T(),T(),T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_IEEE_EQUAL(sel( bs::One<T>(), bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(sel( bs::One<T>(),bs::Zero<T>(),bs::Two<T>()), bs::Zero<r_t>());
  STF_EQUAL(sel( bs::Zero<T>(), bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_


// STF_CASE_TPL (" sel integer",  STF_INTEGRAL_TYPES)
// {
//   namespace bs = boost::simd;
//   namespace bd = boost::dispatch;
//   using bs::sel;
//   using bs::logical;
//   using r_t = decltype(sel(logical<T>(),T(),T()));

//   // return type conformity test
//   STF_TYPE_IS(r_t, T);

//   // specific values tests
//   STF_EQUAL(sel( bs::True< logical<T> >(), bs::One<T>(), bs::One<T>()), bs::One<r_t>());
//   STF_EQUAL(sel( bs::True< logical<T> >(), bs::Zero<T>(),bs::Two<T>()), bs::Zero<r_t>());
//   STF_EQUAL(sel( bs::False< logical<T> >(), bs::One<T>(), bs::Zero<T>()), bs::Zero<r_t>());
// } // end of test for integer_

// STF_CASE_TPL (" sel real",  STF_IEEE_TYPES)
// {
//   namespace bs = boost::simd;
//   namespace bd = boost::dispatch;

//   using bs::sel;

//   using bs::logical;
//   using r_t = decltype(sel(logical<T>(),T(),T()));

//   // return type conformity test
//   STF_TYPE_IS(r_t, T);

//   // specific values tests
// #ifndef STF_NO_INVALIDS
//   STF_EQUAL(sel( bs::True< logical<T> >(), bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
// #endif
//   STF_EQUAL(sel( bs::True< logical<T> >(),bs::Zero<T>(),bs::Two<T>()), bs::Zero<r_t>());
//   STF_EQUAL(sel( bs::False< logical<T> >(), bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
// } // end of test for floating_
