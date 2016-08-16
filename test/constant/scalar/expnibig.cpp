//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/expnibig.hpp>
#include <boost/simd/as.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check expnibig behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::expnibig;
  using boost::simd::Expnibig;
  T ref = T(0);
  STF_TYPE_IS(decltype(Expnibig<T>()), T);
  STF_EQUAL(Expnibig<T>(), ref);
  STF_EQUAL(expnibig( as(T{}) ),ref);
}

STF_CASE_TPL( "Check expnibig behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::expnibig;
  using boost::simd::Expnibig;
  T ref = T(144115188075855872.0);

  STF_TYPE_IS(decltype(Expnibig<T>()), T);
  STF_IEEE_EQUAL(Expnibig<T>(), ref);
  STF_IEEE_EQUAL(expnibig( as(T{}) ), ref);
}

STF_CASE_TPL( "Check expnibig behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::expnibig;
  using boost::simd::Expnibig;
  T ref = T(16777216);
  STF_TYPE_IS(decltype(Expnibig<T>()), T);
  STF_IEEE_EQUAL(Expnibig<T>(), ref);
  STF_IEEE_EQUAL(expnibig( as(T{}) ), ref);
}
