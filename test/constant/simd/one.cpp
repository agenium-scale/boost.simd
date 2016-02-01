//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/nbdigits.hpp>

#include <boost/simd/pack.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check one behavior"
            , (double)(float)
              (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t )(std::int16_t )(std::int32_t )(std::int64_t )
            )
{
  using boost::simd::as;
  using boost::simd::Nbdigits;

  std::cout << Nbdigits<boost::simd::pack<T,4>>() << "\n";
//  STF_IEEE_EQUAL(One<boost::simd::pack<T>>(), boost::simd::pack<T>(1));
}
