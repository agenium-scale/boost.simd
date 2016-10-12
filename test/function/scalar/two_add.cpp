//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/two_add.hpp>
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

STF_CASE_TPL(" two_add", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::two_add;


  STF_EXPR_IS( (two_add(T(), T()))
                  , (std::pair<T,T>)
                  );

  T inf_    = bs::Inf<T>();
  T zero_   = bs::Zero<T>();
  T one_    = bs::One<T>();
  T half_   = bs::Half<T>();
  T eps_    = bs::Eps<T>();
  T eps_2_  = eps_/T(2);

  std::pair<T,T> p;

  p = two_add(inf_,zero_);
  STF_EQUAL(p.first, inf_);
  STF_EQUAL(p.second, zero_);

  p = two_add(zero_, inf_);
  STF_EQUAL(p.first, inf_);
  STF_EQUAL(p.second, zero_);

  p = two_add(half_+ eps_2_, half_);
  STF_EQUAL(p.first, one_);
  STF_EQUAL(p.second, eps_2_);

  p = two_add(half_, half_+ eps_2_);
  STF_EQUAL(p.first, one_);
  STF_EQUAL(p.second, eps_2_);
}
