//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/invexp_1.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check invexp_1 behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::invexp_1;
  using boost::simd::Invexp_1;
  T ref = T(0);
  STF_TYPE_IS(decltype(Invexp_1<T>()), T);
  STF_EQUAL(Invexp_1<T>(), ref);
  STF_EQUAL(invexp_1( as(T{}) ),ref);
}

STF_CASE_TPL( "Check invexp_1 behavior for double/float"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::invexp_1;
  using boost::simd::Invexp_1;
  T ref = T(0.367879441171442321595523770161);

  STF_TYPE_IS(decltype(Invexp_1<T>()), T);
  STF_IEEE_EQUAL(Invexp_1<T>(), ref);
  STF_IEEE_EQUAL(invexp_1( as(T{}) ), ref);
}


