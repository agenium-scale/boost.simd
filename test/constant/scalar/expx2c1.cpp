//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/expx2c1.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check expx2c1 behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::expx2c1;
  using boost::simd::Expx2c1;
  T ref = T(0);
  STF_TYPE_IS(decltype(Expx2c1<T>()), T);
  STF_EQUAL(Expx2c1<T>(), ref);
  STF_EQUAL(expx2c1( as(T{}) ),ref);
}

STF_CASE_TPL( "Check expx2c1 behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::expx2c1;
  using boost::simd::Expx2c1;
  T ref = T(128);

  STF_TYPE_IS(decltype(Expx2c1<T>()), T);
  STF_IEEE_EQUAL(Expx2c1<T>(), ref);
  STF_IEEE_EQUAL(expx2c1( as(T{}) ), ref);
}

STF_CASE_TPL( "Check expx2c1 behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::expx2c1;
  using boost::simd::Expx2c1;
  T ref = T(32);
  STF_TYPE_IS(decltype(Expx2c1<T>()), T);
  STF_IEEE_EQUAL(Expx2c1<T>(), ref);
  STF_IEEE_EQUAL(expx2c1( as(T{}) ), ref);
}
