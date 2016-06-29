//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/function/interleave_first.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;


STF_CASE_TPL( "unary interleave_first based shuffle", STF_NUMERIC_TYPES)
{
  // cardinal 4
 {
    bs::pack<T,4> a{ bs::Valmax<T>(), T(42), T(69), bs::Valmin<T>() };
    bs::pack<T,4> b{ T(13), bs::Valmin<T>(), T(37), bs::Valmax<T>() };
    bs::pack<T,4> z(0);

    STF_ALL_EQUAL( (bs::shuffle< 0, 0, 1, 1>(a))  , (bs::interleave_first(a,a)) );
    STF_ALL_EQUAL( (bs::shuffle< 0, 0, 1, 1>(a,b)), (bs::interleave_first(a,a)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 0,-1, 1>(a))  , (bs::interleave_first(z,a)) );

    STF_ALL_EQUAL( (bs::shuffle< 4, 4, 5, 5>(a,b)), (bs::interleave_first(b,b)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 4,-1, 5>(a,b)), (bs::interleave_first(z,b)) );

  }

  // cardinal 8
  {
    bs::pack<T,8> a{ bs::Valmax<T>(), T(42), T(69), bs::Valmin<T>(), T(37), bs::Valmax<T>(), T(55), T(99) };
    bs::pack<T,8> b{ T(13), bs::Valmax<T>(), T(42), bs::Valmax<T>(), T(76), bs::Valmin<T>(), T(42), T(69) };
    bs::pack<T,8> z(0);

    STF_ALL_EQUAL( (bs::shuffle< 0,0, 1,1, 2,2, 3,3>(a))  , (bs::interleave_first(a,a)) );
    STF_ALL_EQUAL( (bs::shuffle< 0,0, 1,1, 2,2, 3,3>(a,b)), (bs::interleave_first(a,a)) );
    STF_ALL_EQUAL( (bs::shuffle<-1,0,-1,1,-1,2,-1,3>(a))  , (bs::interleave_first(z,a)) );

    STF_ALL_EQUAL( (bs::shuffle< 8,8, 9,9,10,10,11,11>(a,b)), (bs::interleave_first(b,b)) );
    STF_ALL_EQUAL( (bs::shuffle<-1,8,-1,9,-1,10,-1,11>(a,b)), (bs::interleave_first(z,b)) );
  }
}


STF_CASE_TPL( "binary interleave_first based shuffle", STF_NUMERIC_TYPES)
{
  // cardinal 4
 {
    bs::pack<T,4> a{ bs::Valmax<T>(), T(42), T(69), bs::Valmin<T>() };
    bs::pack<T,4> b{ T(13), bs::Valmin<T>(), T(37), bs::Valmax<T>() };
    bs::pack<T,4> z(0);

    STF_ALL_EQUAL( (bs::shuffle< 0, 4, 1, 5>(a,b)), (bs::interleave_first(a,b)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 4,-1, 5>(a,b)), (bs::interleave_first(z,b)) );
    STF_ALL_EQUAL( (bs::shuffle< 0,-1, 1,-1>(a,b)), (bs::interleave_first(a,z)) );

    STF_ALL_EQUAL( (bs::shuffle< 4, 0, 5, 1>(a,b)), (bs::interleave_first(b,a)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 0,-1, 1>(a,b)), (bs::interleave_first(z,a)) );
    STF_ALL_EQUAL( (bs::shuffle< 4,-1, 5,-1>(a,b)), (bs::interleave_first(b,z)) );
  }

  // cardinal 8
  {
    bs::pack<T,8> a{ bs::Valmax<T>(), T(42), T(69), bs::Valmin<T>(), T(37), bs::Valmax<T>(), T(55), T(99) };
    bs::pack<T,8> b{ T(13), bs::Valmax<T>(), T(42), bs::Valmax<T>(), T(76), bs::Valmin<T>(), T(42), T(69) };
    bs::pack<T,8> z(0);

    STF_ALL_EQUAL( (bs::shuffle< 0, 8, 1, 9, 2,10, 3,11>(a,b)), (bs::interleave_first(a,b)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 8,-1, 9,-1,10,-1,11>(a,b)), (bs::interleave_first(z,b)) );
    STF_ALL_EQUAL( (bs::shuffle< 0,-1, 1,-1, 2,-1, 3,-1>(a,b)), (bs::interleave_first(a,z)) );

    STF_ALL_EQUAL( (bs::shuffle< 8, 0, 9, 1,10, 2,11, 3>(a,b)), (bs::interleave_first(b,a)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 0,-1, 1,-1, 2,-1, 3>(a,b)), (bs::interleave_first(z,a)) );
    STF_ALL_EQUAL( (bs::shuffle< 8,-1, 9,-1,10,-1,11,-1>(a,b)), (bs::interleave_first(b,z)) );
  }
}
