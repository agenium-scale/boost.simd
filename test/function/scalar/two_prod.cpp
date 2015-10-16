//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/two_prod.hpp>
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

STF_CASE_TPL(" two_prod", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::two_prod;


  STF_EXPR_IS( (two_prod(T(), T()))
                  , (std::pair<T,T>)
                  );

  T inf_    = bs::Inf<T>();
  T zero_   = bs::Zero<T>();
  T one_    = bs::One<T>();
  T eps_    = bs::Eps<T>();
  T meps2_   = -eps_*eps_;

  {
    T s,r;

    two_prod(inf_,one_, s, r);
    STF_EQUAL(s, inf_);
    STF_EQUAL(r, zero_);

    two_prod(one_, inf_, s, r);
    STF_EQUAL(s, inf_);
    STF_EQUAL(r, zero_);

    two_prod(one_ + eps_, one_ - eps_, s, r);
    STF_EQUAL(s, one_);
    STF_EQUAL(r, meps2_);

    two_prod(one_ - eps_,one_ + eps_, s, r);
    STF_EQUAL(s, one_);
    STF_EQUAL(r, meps2_);
  }

  {
    T s,r;

    s = two_prod(inf_,one_, r);
    STF_EQUAL(s, inf_);
    STF_EQUAL(r, zero_);

    s = two_prod(one_, inf_, r);
    STF_EQUAL(s, inf_);
    STF_EQUAL(r, zero_);

    s = two_prod(one_ + eps_, one_ - eps_, r);
    STF_EQUAL(s, one_);
    STF_EQUAL(r, meps2_);

    s = two_prod(one_ - eps_,one_ + eps_, r);
    STF_EQUAL(s, one_);
    STF_EQUAL(r, meps2_);
  }

  {
    std::pair<T,T> p;

    p = two_prod(inf_,one_);
    STF_EQUAL(p.first, inf_);
    STF_EQUAL(p.second, zero_);

    p = two_prod(one_, inf_);
    STF_EQUAL(p.first, inf_);
    STF_EQUAL(p.second, zero_);

    p = two_prod(one_ + eps_, one_ - eps_);
    STF_EQUAL(p.first, one_);
    STF_EQUAL(p.second, meps2_);

    p = two_prod(one_ - eps_,one_ + eps_);
    STF_EQUAL(p.first, one_);
    STF_EQUAL(p.second, meps2_);
  }
}
