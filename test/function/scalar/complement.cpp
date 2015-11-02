//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/complement.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <nontrivial.hpp>


STF_CASE_TPL ("check complement for floating",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::complement;
  using bs::tag::complement_;
  using r_t = decltype(complement(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(complement(bs::Nan<T>()), bs::Zero<r_t>());
#endif
  STF_IEEE_EQUAL(complement(bs::Zero<T>()), bs::Nan<r_t>());
} // end of test for floating_

STF_CASE_TPL ("check complement for integral",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  using bs::complement;
  using bs::tag::complement_;
  using r_t = decltype(complement(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(complement(bs::One<T>()), bs::shift_left(bs::Mone<r_t>(),1));
  STF_EQUAL(complement(bs::Three<T>()), bs::shift_left(bs::Mone<r_t>(),2));
  STF_EQUAL(complement(bs::Zero<T>()), bs::Mone<r_t>());
} // end of test for integer_

namespace foo
{
  template <class T>
  nontrivial<T> operator ~(const nontrivial<T> & z1)
  {
    return perform(z1);
  }
}

STF_CASE_TPL( "Check complement behavior with exotic type", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::complement;
  using foo::nontrivial;
  using r_t = decltype(complement(nontrivial<T>()));
  STF_TYPE_IS(r_t, nontrivial<T>);

  STF_EQUAL(complement(nontrivial<T>(1, 2)), nontrivial<T>(2, 6));
}
