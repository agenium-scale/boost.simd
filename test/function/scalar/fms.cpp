//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/fms.hpp>
#include <stf.hpp>


STF_CASE_TPL(" fms",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::fms;

  STF_EXPR_IS(fms(T(),T(),T()), T);

  STF_EQUAL(fms(T(2),T(2),T(4)) , T(0));
  STF_EQUAL(fms(T(2),T(2),T(-4)), T(8));
  STF_EQUAL(fms(T(2),T(-2),T(4)), T(-8));
  STF_EQUAL(fms(T(-2),T(2),T(4)), T(-8));
}


