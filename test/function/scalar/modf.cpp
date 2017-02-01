//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/modf.hpp>
#include <scalar_test.hpp>
#include <boost/simd/function/trunc.hpp>
#include <boost/simd/function/frac.hpp>
#include <utility>



STF_CASE_TPL(" modf", STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::modf;


  STF_EXPR_IS( (modf(T()))
             , (std::pair<T,T>)
             );

  {
    T rest;
    T rounded;

    modf(T(1.5), rest, rounded);
    STF_EQUAL(rounded, bs::trunc(T(1.5)));
    STF_EQUAL(rest, T(.5));
  }

  {
    T rest;
    T rounded;

    rest = modf(T(1.5), rounded);
    STF_EQUAL(rounded, bs::trunc(T(1.5)));
    STF_EQUAL(rest, T(.5));
  }

  {
    std::pair<T,T> p;

    p = modf(T(1.5));
    STF_EQUAL(p.first , T(.5));
    STF_EQUAL(p.second  , bs::trunc(T(1.5)));
  }
}
