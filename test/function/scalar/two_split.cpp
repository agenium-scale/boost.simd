//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/two_split.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
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

  std::pair<T,T> p;

  p = two_split(one_-eps_);
  STF_EQUAL(p.first, one_);
  STF_EQUAL(p.second, -eps_);
}

