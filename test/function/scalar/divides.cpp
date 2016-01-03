//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/divides.hpp>
#include <simd_test.hpp>
#include <nontrivial.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/options.hpp>

STF_CASE_TPL( "Check divides behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::divides;
  using r_t = decltype(divides(T(), T()));
  STF_TYPE_IS(r_t, T);

#ifndef STF_NO_INVALIDS
  STF_IEEE_EQUAL(divides(bs::Inf<T>(),  bs::Inf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(divides(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(divides(bs::Nan<T>(),  bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_IEEE_EQUAL(divides(bs::One<T>(),bs::Zero<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(divides(bs::Zero<T>(), bs::Zero<T>()), bs::Nan<r_t>());
  STF_IEEE_EQUAL(divides(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
}

namespace foo
{
  template <class T>
  nontrivial<T> operator /(const nontrivial<T> & z1, const nontrivial<T> z2)
  {
    return perform(z1, z2);
  }
}

STF_CASE_TPL( "Check divides behavior with exotic type", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::divides;
  using foo::nontrivial;
  using r_t = decltype(divides(nontrivial<T>(), nontrivial<T>()));
  STF_TYPE_IS(r_t, nontrivial<T>);

  STF_EQUAL(divides(nontrivial<T>(1, 2), nontrivial<T>(3, 4)), nontrivial<T>(4, 8));
}


STF_CASE_TPL( "Check divides behavior with fast option", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::divides;
  using bs::fast_;

  STF_EQUAL(divides(T(1), T(2), fast_), T(1/2.0));
}
