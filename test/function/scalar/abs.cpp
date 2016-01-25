//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
//#include <nontrivial.hpp>

#include <simd_test.hpp>

STF_CASE_TPL( "Check abs behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::abs;
  using r_t = decltype(abs(T()));
  STF_TYPE_IS(r_t, T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_IEEE_EQUAL(abs(bs::Inf<T>()),  bs::Inf<r_t>());
  STF_IEEE_EQUAL(abs(bs::Minf<T>()), bs::Inf<r_t>());
  STF_IEEE_EQUAL(abs(bs::Nan<T>()),  bs::Nan<r_t>());
#endif
  STF_IEEE_EQUAL(abs(bs::Zero<T>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(abs(bs::One<T>()),  bs::One<r_t>());
  STF_IEEE_EQUAL(abs(bs::Mone<T>()), bs::One<r_t>());
}

// namespace foo
// {
//   template <class T>
//   nontrivial<T> abs(const nontrivial<T> & z1)
//   {
//     return perform(z1);
//   }
// }

// STF_CASE_TPL( "Check abs behavior with exotic type", STF_IEEE_TYPES )
// {
//   namespace bs = boost::simd;
//   using foo::nontrivial;
//   using r_t = decltype(bs::abs(nontrivial<T>()));
//   STF_TYPE_IS(r_t, nontrivial<T>);
//   STF_EQUAL(bs::abs(nontrivial<T>(1, 2)), nontrivial<T>(2, 6));
// }

// STF_CASE_TPL( "Check std abs behavior with floating", STF_IEEE_TYPES )
// {
//   namespace bs = boost::simd;
//   using bs::abs;
//   using r_t = decltype(abs(T()));
//   STF_TYPE_IS(r_t, T);

// #ifndef BOOST_SIMD_NO_INVALIDS
//   STF_IEEE_EQUAL(abs(bs::Inf<T>(), bs::std_),  bs::Inf<r_t>());
//   STF_IEEE_EQUAL(abs(bs::Minf<T>(), bs::std_), bs::Inf<r_t>());
//   STF_IEEE_EQUAL(abs(bs::Nan<T>(), bs::std_),  bs::Nan<r_t>());
// #endif
//   STF_IEEE_EQUAL(abs(bs::Zero<T>(), bs::std_), bs::Zero<r_t>());
//   STF_IEEE_EQUAL(abs(bs::One<T>(), bs::std_),  bs::One<r_t>());
//   STF_IEEE_EQUAL(abs(bs::Mone<T>(), bs::std_), bs::One<r_t>());
// }

