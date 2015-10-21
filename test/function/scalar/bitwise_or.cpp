//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/bitwise_or.hpp>
#include <stf.hpp>
#include <nontrivial.hpp>


STF_CASE_TPL( "Check bitwise_or behavior with floating", (float) )
{
  namespace bs = boost::simd;
  using bs::bitwise_or;
  using r_t = decltype(bitwise_or(T(), T()));
  STF_TYPE_IS(r_t, T);

  auto a = bitwise_or(4.f, 4.f);
  std::cout << a << std::endl;
//  auto b = bitwise_or(4.F, 'a');
// #ifndef BOOST_SIMD_NO_INVALIDS
//   STF_IEEE_EQUAL(divides(bs::Inf<T>(),  bs::Inf<T>()), bs::Nan<r_t>());
//   STF_IEEE_EQUAL(divides(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<r_t>());
//   STF_IEEE_EQUAL(divides(bs::Nan<T>(),  bs::Nan<T>()), bs::Nan<r_t>());
// #endif
//   STF_IEEE_EQUAL(bitwise_or(boost::simd::Mone<T>()), boost::simd::One<T>());
//   STF_IEEE_EQUAL(bitwise_or(boost::simd::One<T>()), boost::simd::One<T>());
//   STF_IEEE_EQUAL(bitwise_or(boost::simd::Valmax<T>()), boost::simd::Valmax<T>());
//   STF_IEEE_EQUAL(bitwise_or(boost::simd::Valmin<T>()), boost::simd::Valmax<T>());
//   STF_IEEE_EQUAL(bitwise_or(boost::simd::Zero<T>()), boost::simd::Zero<T>());
}

// namespace foo
// {
//   template <class T>
//   nontrivial<T> bitwise_or(const nontrivial<T> & z1)
//   {
//     return perform(z1);
//   }
// }

// STF_CASE_TPL( "Check bitwise_or behavior with exotic type", (double)(float) )
// {#include <boost/dispatch/meta/as_integer.hpp>
//   namespace bs = boost::simd;
//   using foo::nontrivial;
//   using r_t = decltype(bs::bitwise_or(nontrivial<T>()));
//   STF_TYPE_IS(r_t, nontrivial<T>);
//   std::cout << stf::type_id<boost::dispatch::hierarchy_of_t<nontrivial<T>>>()<< std::endl;
//   STF_EQUAL(bs::bitwise_or(nontrivial<T>(1, 2)), nontrivial<T>(2, 6));
// }

