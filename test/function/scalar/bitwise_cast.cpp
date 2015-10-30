//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/bitwise_cast.hpp>
#include <simd_test.hpp>
#include <nontrivial.hpp>
#include <boost/dispatch/as.hpp>


STF_CASE_TPL( "Check bitwise_cast behavior with floating", (float) )
{
  namespace bs = boost::simd;
  using bs::bitwise_cast;
  using rf_t = decltype(bitwise_cast<T>(T()));
  using rc_t = decltype(bitwise_cast(T(), boost::dispatch::as_<T>()));
  STF_TYPE_IS(rf_t, T);
  STF_TYPE_IS(rc_t, T);

  auto a = bitwise_cast(4.F, boost::dispatch::as_<T>());
  std::cout << a << std::endl;
//  auto b = bitwise_cast('a', boost::dispatch::as_<T>());
// #ifndef BOOST_SIMD_NO_INVALIDS
//   STF_IEEE_EQUAL(divides(bs::Inf<T>(),  bs::Inf<T>()), bs::Nan<r_t>());
//   STF_IEEE_EQUAL(divides(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<r_t>());
//   STF_IEEE_EQUAL(divides(bs::Nan<T>(),  bs::Nan<T>()), bs::Nan<r_t>());
// #endif
//   STF_IEEE_EQUAL(bitwise_cast(boost::simd::Mone<T>()), boost::simd::One<T>());
//   STF_IEEE_EQUAL(bitwise_cast(boost::simd::One<T>()), boost::simd::One<T>());
//   STF_IEEE_EQUAL(bitwise_cast(boost::simd::Valmax<T>()), boost::simd::Valmax<T>());
//   STF_IEEE_EQUAL(bitwise_cast(boost::simd::Valmin<T>()), boost::simd::Valmax<T>());
//   STF_IEEE_EQUAL(bitwise_cast(boost::simd::Zero<T>()), boost::simd::Zero<T>());
}

// namespace foo
// {
//   template <class T>
//   nontrivial<T> bitwise_cast(const nontrivial<T> & z1)
//   {
//     return perform(z1);
//   }
// }

// STF_CASE_TPL( "Check bitwise_cast behavior with exotic type", (double)(float) )
// {#include <boost/dispatch/meta/as_integer.hpp>
//   namespace bs = boost::simd;
//   using foo::nontrivial;
//   using r_t = decltype(bs::bitwise_cast(nontrivial<T>()));
//   STF_TYPE_IS(r_t, nontrivial<T>);
//   std::cout << stf::type_id<boost::dispatch::hierarchy_of_t<nontrivial<T>>>()<< std::endl;
//   STF_EQUAL(bs::bitwise_cast(nontrivial<T>(1, 2)), nontrivial<T>(2, 6));
// }

