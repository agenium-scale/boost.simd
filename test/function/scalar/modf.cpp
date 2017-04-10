//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/modf.hpp>
#include <boost/simd/function/trunc.hpp>
#include <scalar_test.hpp>
#include <utility>


STF_CASE_TPL(" modf", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::modf;

  {
    std::pair<T,T> p;

    p = bs::modf(T(1.5));
    STF_EQUAL(p.first , T(.5));
    STF_EQUAL(p.second  , bs::trunc(T(1.5)));
  }
}
