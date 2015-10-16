//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/two_split.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/half.hpp>
#include <utility>

STF_CASE_TPL(" two_split", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::two_split;


  STF_EXPR_IS( (two_split(T()))
                  , (std::pair<T,T>)
                  );

  T eps_ = bs::Eps<T>();
  T one_ = bs::One<T>();

  {
    T f,s;

    two_split(one_-eps_, f, s);
    STF_EQUAL(f, one_);
    STF_EQUAL(s, -eps_);
  }

  {
    T f,s;

    f = two_split(one_-eps_, s);
    STF_EQUAL(f, one_);
    STF_EQUAL(s, -eps_);
  }

  {
    std::pair<T,T> p;

    p = two_split(one_-eps_);
    STF_EQUAL(p.first, one_);
    STF_EQUAL(p.second, -eps_);
  }
}

