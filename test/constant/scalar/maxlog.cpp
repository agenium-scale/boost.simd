//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/maxlog.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check maxlog behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::maxlog;
  using boost::simd::Maxlog;
  T ref = T(0);
  STF_TYPE_IS(decltype(Maxlog<T>()), T);
  STF_EQUAL(Maxlog<T>(), ref);
  STF_EQUAL(maxlog( as(T{}) ),ref);
}

STF_CASE_TPL( "Check maxlog behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::functional::maxlog;
  using boost::simd::Maxlog;
  T ref = T(709.78271289338400);

  STF_TYPE_IS(decltype(Maxlog<T>()), T);
  STF_IEEE_EQUAL(Maxlog<T>(), ref);
  STF_IEEE_EQUAL(maxlog( as(T{}) ), ref);
}

STF_CASE_TPL( "Check maxlog behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::maxlog;
  using boost::simd::Maxlog;
  T ref = T(88.3762626647949);
  STF_TYPE_IS(decltype(Maxlog<T>()), T);
  STF_IEEE_EQUAL(Maxlog<T>(), ref);
  STF_IEEE_EQUAL(maxlog( as(T{}) ), ref);
}
