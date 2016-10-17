//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/scalar/hmsb.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/constant/nan.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL ("Check hmsb", STF_NUMERIC_TYPES)
{
  STF_EQUAL(boost::simd::hmsb(boost::simd::Allbits<T>()).size(), 1ULL);

  STF_EXPECT(boost::simd::hmsb(boost::simd::Signmask<T>()).all());
  STF_EXPECT(boost::simd::hmsb(boost::simd::Allbits<T>()).all());
  STF_EXPECT(boost::simd::hmsb(T(-1)).all());

  STF_EXPECT(boost::simd::hmsb(T(0)).none());
  STF_EXPECT(boost::simd::hmsb(T(1)).none());
}
