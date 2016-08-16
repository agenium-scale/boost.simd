//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include "reference.hpp"

using namespace boost::simd;

STF_CASE_TPL( "Cardinal 4 binary shuffle resolving as AVX direct mm_shuffle"
            , (float)(std::uint32_t)(std::int32_t)
            )
{
  bs::pack<T,8> a{ Valmax<T>(), T(42), T(13), Valmin<T>(), T(19), T(7), T(63), T(101) };
  bs::pack<T,8> b{ T(69), Valmin<T>(), T(37), T(0), T(155), T(511), Valmax<T>(), T(69) };

  STF_ALL_EQUAL( (shuffle<0, 3, 8,11, 4, 7,12,15>(a,b)), (binary_ref<0, 3, 8,11, 4, 7,12,15>(a,b)) );
  STF_ALL_EQUAL( (shuffle<1, 2, 9,10, 5,-1,13,14>(a,b)), (binary_ref<1, 2, 9,10, 5,-1,13,14>(a,b)) );
  STF_ALL_EQUAL( (shuffle<2,-1,10, 9, 6, 5,14,13>(a,b)), (binary_ref<2,-1,10, 9, 6, 5,14,13>(a,b)) );
  STF_ALL_EQUAL( (shuffle<3,-1,11, 8, 7,-1,15,12>(a,b)), (binary_ref<3,-1,11, 8, 7,-1,15,12>(a,b)) );
  STF_ALL_EQUAL( (shuffle<3,-1,-1,-1, 7, 5,12,15>(a,b)), (binary_ref<3,-1,-1,-1, 7, 5,12,15>(a,b)) );
}

STF_CASE_TPL( "Cardinal 4 binary shuffle resolving as AVX indirect mm_shuffle"
            , (float)(std::uint32_t)(std::int32_t)
            )
{
  bs::pack<T,8> a{ Valmax<T>(), T(42), T(13), Valmin<T>(), T(19), T(7), T(63), T(101) };
  bs::pack<T,8> b{ T(69), Valmin<T>(), T(37), T(0), T(155), T(511), Valmax<T>(), T(69) };

  STF_ALL_EQUAL( (shuffle< 8,11, 0, 3,12,15, 4, 7>(a,b)), (binary_ref< 8,11, 0, 3,12,15, 4, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 9,10, 1, 2,13,14, 5,-1>(a,b)), (binary_ref< 9,10, 1, 2,13,14, 5,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<10, 9, 2,-1,14,13, 6, 5>(a,b)), (binary_ref<10, 9, 2,-1,14,13, 6, 5>(a,b)) );
  STF_ALL_EQUAL( (shuffle<11, 8, 3,-1,15,12, 7,-1>(a,b)), (binary_ref<11, 8, 3,-1,15,12, 7,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 9,-1,-1,-1,13,12, 6, 4>(a,b)), (binary_ref< 9,-1,-1,-1,13,12, 6, 4>(a,b)) );
}
