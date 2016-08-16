//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/function/deinterleave_first.hpp>
#include <boost/simd/function/deinterleave_second.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Direct deinterleave shuffle", STF_NUMERIC_TYPES)
{
  // cardinal 2
  {
    bs::pack<T,2> a{ bs::Valmax<T>(), T(42) };
    bs::pack<T,2> b{ T(13), bs::Valmin<T>() };

    STF_ALL_EQUAL( (bs::shuffle<0,2>(a,b)), (bs::deinterleave_first (a,b)) );
    STF_ALL_EQUAL( (bs::shuffle<1,3>(a,b)), (bs::deinterleave_second(a,b)) );
    STF_ALL_EQUAL( (bs::shuffle<2,0>(a,b)), (bs::deinterleave_first (b,a)) );
    STF_ALL_EQUAL( (bs::shuffle<3,1>(a,b)), (bs::deinterleave_second(b,a)) );
  }

 // cardinal 4
  {
    bs::pack<T,4> a{ bs::Valmax<T>(), T(42), T(69), bs::Valmin<T>() };
    bs::pack<T,4> b{ T(13), bs::Valmin<T>(), T(37), bs::Valmax<T>() };

    STF_ALL_EQUAL( (bs::shuffle<0,2,4,6>(a,b)), (bs::deinterleave_first (a,b)) );
    STF_ALL_EQUAL( (bs::shuffle<1,3,5,7>(a,b)), (bs::deinterleave_second(a,b)) );
    STF_ALL_EQUAL( (bs::shuffle<4,6,0,2>(a,b)), (bs::deinterleave_first (b,a)) );
    STF_ALL_EQUAL( (bs::shuffle<5,7,1,3>(a,b)), (bs::deinterleave_second(b,a)) );
  }

  // cardinal 8
  {
    bs::pack<T,8> a { bs::Valmax<T>(),T(66),T(99),T(55), T(-1),T(77), T(23), bs::Valmin<T>()};
    bs::pack<T,8> b{ T(13), bs::Valmin<T>(), T(37), bs::Valmax<T>(), T(54),T(13),T(37),T(69) };

    STF_ALL_EQUAL( (bs::shuffle<0,2,4,6,8,10,12,14>(a,b)), (bs::deinterleave_first (a,b)) );
    STF_ALL_EQUAL( (bs::shuffle<1,3,5,7,9,11,13,15>(a,b)), (bs::deinterleave_second(a,b)) );
    STF_ALL_EQUAL( (bs::shuffle<8,10,12,14,0,2,4,6>(a,b)), (bs::deinterleave_first (b,a)) );
    STF_ALL_EQUAL( (bs::shuffle<9,11,13,15,1,3,5,7>(a,b)), (bs::deinterleave_second(b,a)) );
  }
}
