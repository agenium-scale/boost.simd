//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/maxleftshift.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

STF_CASE_TPL( "Check maxleftshift behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
              (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::detail::maxleftshift;
  using boost::simd::Maxleftshift;
  using int_t = typename boost::dispatch::as_integer<T>::type;
  STF_TYPE_IS(decltype(Maxleftshift<T>()), int_t);
  STF_EQUAL(Maxleftshift<T>(), (int_t)(sizeof(T)*8-1));
  STF_EQUAL(maxleftshift( as(T{}) ),(int_t)(sizeof(T)*8-1));
}


