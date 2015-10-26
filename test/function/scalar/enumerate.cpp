//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/enumerate.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL( "Check enumerate behavior with all types", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using bs::enumerate;
//   using r_t = decltype(enumerate(1, bs::as_<T>()));
//   STF_TYPE_IS(r_t, T);

  STF_EQUAL(enumerate<T>(1),  T(1));
  STF_EQUAL(enumerate<T>() ,  T(0));
  STF_EQUAL(enumerate<T>(1, 2) ,  T(1));
}
