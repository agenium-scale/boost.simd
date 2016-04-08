//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/remquo.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <utility>

#ifndef STF_NO_INVALIDS
STF_CASE_TPL(" remquo invalid", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::remquo;


  using iT =  bd::as_integer_t<T,signed>;

  STF_EXPR_IS( (remquo(T(), T()))
                  , (std::pair<T,iT>)
                  );

  T inf_  = bs::Inf<T>();
  T nan_  = bs::Nan<T>();
  T zero_ = bs::Zero<T>();
  T one_  = bs::One<T>();

  {
    // n is unspecified by the standard so we don't test it
    iT n;
    T  r;

    remquo(one_,nan_, r, n);
    STF_IEEE_EQUAL(r, nan_);

    remquo(one_,inf_, r, n);
    STF_IEEE_EQUAL(r, nan_);

    remquo(one_,zero_, r, n);
    STF_IEEE_EQUAL(r, nan_);

    remquo(inf_,zero_, r, n);
    STF_IEEE_EQUAL(r, nan_);

    remquo(nan_,zero_, r, n);
    STF_IEEE_EQUAL(r, nan_);

    remquo(nan_,one_, r, n);
    STF_IEEE_EQUAL(r, nan_);

    remquo(nan_,nan_, r, n);
    STF_IEEE_EQUAL(r, nan_);

    remquo(nan_,inf_, r, n);
    STF_IEEE_EQUAL(r, nan_);
  }

  {
    // n is unspecified by the standard so we don't test it
    iT n;
    T  r;

    r = remquo(one_,nan_, n);
    STF_IEEE_EQUAL(r, nan_);

    r = remquo(one_,inf_, n);
    STF_IEEE_EQUAL(r, nan_);

    r = remquo(one_,zero_, n);
    STF_IEEE_EQUAL(r, nan_);

    r = remquo(inf_,zero_, n);
    STF_IEEE_EQUAL(r, nan_);

    r = remquo(nan_,zero_, n);
    STF_IEEE_EQUAL(r, nan_);

    r = remquo(nan_,one_, n);
    STF_IEEE_EQUAL(r, nan_);

    r = remquo(nan_,nan_, n);
    STF_IEEE_EQUAL(r, nan_);

    r = remquo(nan_,inf_, n);
    STF_IEEE_EQUAL(r, nan_);
  }


  {
    // n is unspecified by the standard so we don't test it
    std::pair<T,iT> p;

    p =  remquo(one_,nan_);
    STF_IEEE_EQUAL(p.first, nan_);

    p =  remquo(one_,inf_);
    STF_IEEE_EQUAL(p.first, nan_);

    p =  remquo(one_,zero_);
    STF_IEEE_EQUAL(p.first, nan_);

    p =  remquo(inf_,zero_);
    STF_IEEE_EQUAL(p.first, nan_);

    p =  remquo(nan_,zero_);
    STF_IEEE_EQUAL(p.first, nan_);

    p =  remquo(nan_,one_);
    STF_IEEE_EQUAL(p.first, nan_);

    p =  remquo(nan_,nan_);
    STF_IEEE_EQUAL(p.first, nan_);

    p =  remquo(nan_,inf_);
    STF_IEEE_EQUAL(p.first, nan_);
  }
}
#endif

STF_CASE_TPL(" remquo valid", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::remquo;

  using iT =  bd::as_integer_t<T,signed>;

  STF_EXPR_IS( (remquo(T(), T()))
                  , (std::pair<T,iT>)
                  );

  T a0[] = { T(1), T(2), T(3), T(4.5) };
  T a1[] = { T(2), T(1), T(7), T(3.2) };

  std::size_t nb = sizeof(a0)/sizeof(T);

  {
    iT n;
    T  r;

    for(std::size_t i=0;i<nb;++i)
    {
      remquo(a0[i],a1[i], r, n);
      STF_EQUAL(n, iT(a0[i] / a1[i]));
      STF_EQUAL(r, a0[i] - n*a1[i]);
    }
  }

  {
    iT n;
    T  r;

    for(std::size_t i=0;i<nb;++i)
    {
      r = remquo(a0[i],a1[i], n);
      STF_EQUAL(n, iT(a0[i] / a1[i]));
      STF_EQUAL(r, a0[i] - n*a1[i]);
    }
  }

  {

    std::pair<T,iT> p;

    for(std::size_t i=0;i<nb;++i)
    {
      p = remquo(a0[i],a1[i]);
      STF_EQUAL(p.second, iT(a0[i] / a1[i]));
      STF_EQUAL(p.first, a0[i] - p.second*a1[i]);
    }
  }
}
