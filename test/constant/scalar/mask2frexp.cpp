//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/mask2frexp.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>
//TODO
STF_CASE_TPL( "Check mask2frexp behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::mask2frexp;
  using boost::simd::Mask2frexp;

  STF_TYPE_IS(decltype(Mask2frexp<T>()), T);
  STF_EQUAL(Mask2frexp<T>(), T(0));
  STF_EQUAL(mask2frexp( as(T{}) ),T(0));
}

// STF_CASE_TPL( "Check mask2frexp behavior for floating types"
//             , (double)(float)
//             )
// {
//   using boost::simd::as;
//   using boost::simd::functional::mask2frexp;
//   using boost::simd::Mask2frexp;

//   STF_TYPE_IS(decltype(Mask2frexp<T>()), T);
//   STF_IEEE_EQUAL(Mask2frexp<T>(), T(1));
//   STF_IEEE_EQUAL(mask2frexp( as(T{}) ), T(1));
// }
