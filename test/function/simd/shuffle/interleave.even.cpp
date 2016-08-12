//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/function/interleave_even.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "interleave_even based shuffle", STF_NUMERIC_TYPES)
{
  // cardinal 4
  {
    bs::pack<T,4> a{ bs::Valmax<T>(), T(42), T(69), bs::Valmin<T>() };
    bs::pack<T,4> b{ T(13), bs::Valmin<T>(), T(37), bs::Valmax<T>() };
    bs::pack<T,4> z(0);

    STF_ALL_EQUAL( (bs::shuffle< 0, 4, 2, 6>(a,b)), (bs::interleave_even(a,b)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 4,-1, 6>(a,b)), (bs::interleave_even(z,b)) );
    STF_ALL_EQUAL( (bs::shuffle< 0,-1, 2,-1>(a,b)), (bs::interleave_even(a,z)) );

    STF_ALL_EQUAL( (bs::shuffle< 4, 0, 6, 2>(a,b)), (bs::interleave_even(b,a)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 0,-1, 2>(a,b)), (bs::interleave_even(z,a)) );
    STF_ALL_EQUAL( (bs::shuffle< 4,-1, 6,-1>(a,b)), (bs::interleave_even(b,z)) );
  }

  // cardinal 8
  {
    bs::pack<T,8> a{ bs::Valmax<T>(), T(42), T(69), bs::Valmin<T>(), T(37), bs::Valmax<T>(), T(55), T(99) };
    bs::pack<T,8> b{ T(13), bs::Valmax<T>(), T(42), bs::Valmax<T>(), T(76), bs::Valmin<T>(), T(42), T(69) };
    bs::pack<T,8> z(0);

    STF_ALL_EQUAL( (bs::shuffle< 0, 8, 2,10, 4,12, 6,14>(a,b)), (bs::interleave_even(a,b)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 8,-1,10,-1,12,-1,14>(a,b)), (bs::interleave_even(z,b)) );
    STF_ALL_EQUAL( (bs::shuffle< 0,-1, 2,-1, 4,-1, 6,-1>(a,b)), (bs::interleave_even(a,z)) );

    STF_ALL_EQUAL( (bs::shuffle< 8, 0,10, 2,12, 4,14, 6>(a,b)), (bs::interleave_even(b,a)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 0,-1, 2,-1, 4,-1, 6>(a,b)), (bs::interleave_even(z,a)) );
    STF_ALL_EQUAL( (bs::shuffle< 8,-1,10,-1,12,-1,14,-1>(a,b)), (bs::interleave_even(b,z)) );
  }
}
