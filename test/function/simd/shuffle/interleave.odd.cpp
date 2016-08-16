//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/function/interleave_odd.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "interleave_odd based shuffle", STF_NUMERIC_TYPES)
{
  // cardinal 4
  {
    bs::pack<T,4> a{ bs::Valmax<T>(), T(42), T(69), bs::Valmin<T>() };
    bs::pack<T,4> b{ T(13), bs::Valmin<T>(), T(37), bs::Valmax<T>() };
    bs::pack<T,4> z(0);

    STF_ALL_EQUAL( (bs::shuffle< 1, 5, 3, 7>(a,b)), (bs::interleave_odd(a,b)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 5,-1, 7>(a,b)), (bs::interleave_odd(z,b)) );
    STF_ALL_EQUAL( (bs::shuffle< 1,-1, 3,-1>(a,b)), (bs::interleave_odd(a,z)) );

    STF_ALL_EQUAL( (bs::shuffle< 5, 1, 7, 3>(a,b)), (bs::interleave_odd(b,a)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 1,-1, 3>(a,b)), (bs::interleave_odd(z,a)) );
    STF_ALL_EQUAL( (bs::shuffle< 5,-1, 7,-1>(a,b)), (bs::interleave_odd(b,z)) );
  }

  // cardinal 8
  {
    bs::pack<T,8> a{ bs::Valmax<T>(), T(42), T(69), bs::Valmin<T>(), T(37), bs::Valmax<T>(), T(55), T(99) };
    bs::pack<T,8> b{ T(13), bs::Valmax<T>(), T(42), bs::Valmax<T>(), T(76), bs::Valmin<T>(), T(42), T(69) };
    bs::pack<T,8> z(0);

    STF_ALL_EQUAL( (bs::shuffle< 1, 9, 3,11, 5,13, 7,15>(a,b)), (bs::interleave_odd(a,b)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 9,-1,11,-1,13,-1,15>(a,b)), (bs::interleave_odd(z,b)) );
    STF_ALL_EQUAL( (bs::shuffle< 1,-1, 3,-1, 5,-1, 7,-1>(a,b)), (bs::interleave_odd(a,z)) );

    STF_ALL_EQUAL( (bs::shuffle< 9, 1,11, 3,13, 5,15, 7>(a,b)), (bs::interleave_odd(b,a)) );
    STF_ALL_EQUAL( (bs::shuffle<-1, 1,-1, 3,-1, 5,-1, 7>(a,b)), (bs::interleave_odd(z,a)) );
    STF_ALL_EQUAL( (bs::shuffle< 9,-1,11,-1,13,-1,15,-1>(a,b)), (bs::interleave_odd(b,z)) );
  }
}
