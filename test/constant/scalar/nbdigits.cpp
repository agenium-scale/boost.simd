//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/nbdigits.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/as.hpp>
#include <limits>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check inf behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::detail::nbdigits;
  using boost::simd::Nbdigits;

  STF_TYPE_IS(decltype(Nbdigits<T>()), T);
  STF_EQUAL(Nbdigits<T>(), T(0));
}

STF_CASE_TPL( "Check inf behavior for float type"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::nbdigits;
  using boost::simd::Nbdigits;

  STF_TYPE_IS(decltype(Nbdigits<T>()), boost::dispatch::as_integer_t<T>);
  STF_EQUAL(Nbdigits<T>(), 24 );
}
STF_CASE_TPL( "Check inf behavior for double type"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::detail::nbdigits;
  using boost::simd::Nbdigits;

  STF_TYPE_IS(decltype(Nbdigits<T>()), boost::dispatch::as_integer_t<T>);
  STF_EQUAL(Nbdigits<T>(), 53 );
}
