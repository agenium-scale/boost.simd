//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/if_else.hpp>
#include <simd_test.hpp>
#include <nontrivial.hpp>

// // PAS FINI
// STF_CASE_TPL( "Check if_else behavior with floating", (double)(float) )
// {
//   namespace bs = boost::simd;
//   using bs::if_else;
//   using r_t = decltype(if_else(T()));
//   STF_TYPE_IS(r_t, T);

// #ifndef BOOST_SIMD_NO_INVALIDS
// //   STF_IEEE_EQUAL(divides(bs::Inf<T>(),  bs::Inf<T>()), bs::Nan<r_t>());
// //   STF_IEEE_EQUAL(divides(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<r_t>());
// //   STF_IEEE_EQUAL(divides(bs::Nan<T>(),  bs::Nan<T>()), bs::Nan<r_t>());
// #endif
// //   STF_IEEE_EQUAL(if_else(boost::simd::Mone<T>()), boost::simd::One<T>());
// //   STF_IEEE_EQUAL(if_else(boost::simd::One<T>()), boost::simd::One<T>());
// //   STF_IEEE_EQUAL(if_else(boost::simd::Valmax<T>()), boost::simd::Valmax<T>());
// //   STF_IEEE_EQUAL(if_else(boost::simd::Valmin<T>()), boost::simd::Valmax<T>());
// //   STF_IEEE_EQUAL(if_else(boost::simd::Zero<T>()), boost::simd::Zero<T>());
// }

// namespace foo
// {
//   template <class T>
//   nontrivial<T> if_else(const nontrivial<T> & z1)
//   {
//     return perform(z1);
//   }
// }

// STF_CASE_TPL( "Check if_else behavior with exotic type", (double)(float) )
// {
//   namespace bs = boost::simd;
//   using foo::nontrivial;
//   using r_t = decltype(bs::if_else(nontrivial<T>()));
//   STF_TYPE_IS(r_t, nontrivial<T>);
//   std::cout << stf::type_id<boost::dispatch::hierarchy_of_t<nontrivial<T>>>()<< std::endl;
//   STF_EQUAL(bs::if_else(nontrivial<T>(1, 2)), nontrivial<T>(2, 6));
// }

