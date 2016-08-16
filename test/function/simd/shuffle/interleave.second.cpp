//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/function/interleave_second.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "unary interleave_second based shuffle", STF_NUMERIC_TYPES)
{
  // cardinal 4
 {
    bs::pack<T,4> a{ bs::Valmax<T>(), T(42), T(69), bs::Valmin<T>() };
    bs::pack<T,4> b{ T(13), bs::Valmin<T>(), T(37), bs::Valmax<T>() };
    bs::pack<T,4> z(0);

    STF_ALL_EQUAL( (bs::shuffle< 2, 2, 3, 3>(a))  , (bs::interleave_second(a,a)) );
    STF_ALL_EQUAL( (bs::shuffle< 2, 2, 3, 3>(a,b)), (bs::interleave_second(a,a)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 2,-1, 3>(a))  , (bs::interleave_second(z,a)) );

    STF_ALL_EQUAL( (bs::shuffle< 6, 6, 7, 7>(a,b)), (bs::interleave_second(b,b)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 6,-1, 7>(a,b)), (bs::interleave_second(z,b)) );
  }

  // cardinal 8
  {
    bs::pack<T,8> a{ bs::Valmax<T>(), T(42), T(69), bs::Valmin<T>(), T(37), bs::Valmax<T>(), T(55), T(99) };
    bs::pack<T,8> b{ T(13), bs::Valmax<T>(), T(42), bs::Valmax<T>(), T(76), bs::Valmin<T>(), T(42), T(69) };
    bs::pack<T,8> z(0);

    STF_ALL_EQUAL( (bs::shuffle< 4,4, 5,5, 6,6, 7,7>(a))  , (bs::interleave_second(a,a)) );
    STF_ALL_EQUAL( (bs::shuffle< 4,4, 5,5, 6,6, 7,7>(a,b)), (bs::interleave_second(a,a)) );
    STF_ALL_EQUAL( (bs::shuffle<-1,4,-1,5,-1,6,-1,7>(a))  , (bs::interleave_second(z,a)) );

    STF_ALL_EQUAL( (bs::shuffle<12,12,13,13,14,14,15,15>(a,b)), (bs::interleave_second(b,b)) );
    STF_ALL_EQUAL( (bs::shuffle<-1,12,-1,13,-1,14,-1,15>(a,b)), (bs::interleave_second(z,b)) );
  }
}

STF_CASE_TPL( "binary interleave_second based shuffle", STF_NUMERIC_TYPES)
{
  // cardinal 4
 {
    bs::pack<T,4> a{ bs::Valmax<T>(), T(42), T(69), bs::Valmin<T>() };
    bs::pack<T,4> b{ T(13), bs::Valmin<T>(), T(37), bs::Valmax<T>() };
    bs::pack<T,4> z(0);

    STF_ALL_EQUAL( (bs::shuffle< 2, 6, 3, 7>(a,b)), (bs::interleave_second(a,b)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 6,-1, 7>(a,b)), (bs::interleave_second(z,b)) );
    STF_ALL_EQUAL( (bs::shuffle< 2,-1, 3,-1>(a,b)), (bs::interleave_second(a,z)) );

    STF_ALL_EQUAL( (bs::shuffle< 6, 2, 7, 3>(a,b)), (bs::interleave_second(b,a)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 2,-1, 3>(a,b)), (bs::interleave_second(z,a)) );
    STF_ALL_EQUAL( (bs::shuffle< 6,-1, 7,-1>(a,b)), (bs::interleave_second(b,z)) );
  }

  // cardinal 8
  {
    bs::pack<T,8> a{ bs::Valmax<T>(), T(42), T(69), bs::Valmin<T>(), T(37), bs::Valmax<T>(), T(55), T(99) };
    bs::pack<T,8> b{ T(13), bs::Valmax<T>(), T(42), bs::Valmax<T>(), T(76), bs::Valmin<T>(), T(42), T(69) };
    bs::pack<T,8> z(0);

    STF_ALL_EQUAL( (bs::shuffle< 4,12, 5,13, 6,14, 7,15>(a,b)), (bs::interleave_second(a,b)) );
    STF_ALL_EQUAL( (bs::shuffle<-1,12,-1,13,-1,14,-1,15>(a,b)), (bs::interleave_second(z,b)) );
    STF_ALL_EQUAL( (bs::shuffle< 4,-1, 5,-1, 6,-1, 7,-1>(a,b)), (bs::interleave_second(a,z)) );

    STF_ALL_EQUAL( (bs::shuffle<12, 4,13, 5,14, 6,15, 7>(a,b)), (bs::interleave_second(b,a)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 4,-1, 5,-1, 6,-1, 7>(a,b)), (bs::interleave_second(z,a)) );
    STF_ALL_EQUAL( (bs::shuffle<12,-1,13,-1,14,-1,15,-1>(a,b)), (bs::interleave_second(b,z)) );
  }
}
