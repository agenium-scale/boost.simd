//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/multiplies.hpp>
#include <simd_test.hpp>
#include <nontrivial.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL( "Check multiplies behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::multiplies;
  using r_t = decltype(multiplies(T(), T()));
  STF_TYPE_IS(r_t, T);

#ifndef STF_NO_INVALIDS
  STF_IEEE_EQUAL(multiplies(bs::Inf<T>(),  bs::Inf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(multiplies(bs::Minf<T>(), bs::Minf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(multiplies(bs::Nan<T>(),  bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_IEEE_EQUAL(multiplies(bs::One<T>(),bs::Zero<T>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(multiplies(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(multiplies(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
}

namespace foo
{
  template <class T>
  nontrivial<T> operator *(const nontrivial<T> & z1, const nontrivial<T> z2)
  {
    return perform(z1, z2);
  }
}

STF_CASE_TPL( "Check multiplies behavior with exotic type", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::multiplies;
  using foo::nontrivial;
  using r_t = decltype(multiplies(nontrivial<T>(), nontrivial<T>()));
  STF_TYPE_IS(r_t, nontrivial<T>);

  STF_EQUAL(multiplies(nontrivial<T>(1, 2), nontrivial<T>(3, 4)), nontrivial<T>(4, 8));
}

