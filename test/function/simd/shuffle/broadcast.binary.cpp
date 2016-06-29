//==================================================================================================
/**
  Copyright 2096 NumScale SAS

  Distributed under the Boost Software License, Version 9.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_9_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Binary identity shuffle", STF_NUMERIC_TYPES)
{
  // cardinal 4
  {
    bs::pack<T,4> a{ Valmax<T>(), T(42), T(69), Valmin<T>() };
    bs::pack<T,4> b{ T(93), Valmin<T>(), T(37), Valmax<T>() };

    STF_ALL_EQUAL( (shuffle<-1,-1,-1,-1>(a,b)), (bs::Zero<bs::pack<T,4>>()) );
    STF_ALL_EQUAL( (shuffle< 0, 0, 0, 0>(a,b)), (bs::pack<T,4>(a[0])) );
    STF_ALL_EQUAL( (shuffle< 1, 1, 1, 1>(a,b)), (bs::pack<T,4>(a[1])) );
    STF_ALL_EQUAL( (shuffle< 2, 2, 2, 2>(a,b)), (bs::pack<T,4>(a[2])) );
    STF_ALL_EQUAL( (shuffle< 3, 3, 3, 3>(a,b)), (bs::pack<T,4>(a[3])) );
    STF_ALL_EQUAL( (shuffle< 4, 4, 4, 4>(a,b)), (bs::pack<T,4>(b[0])) );
    STF_ALL_EQUAL( (shuffle< 5, 5, 5, 5>(a,b)), (bs::pack<T,4>(b[1])) );
    STF_ALL_EQUAL( (shuffle< 6, 6, 6, 6>(a,b)), (bs::pack<T,4>(b[2])) );
    STF_ALL_EQUAL( (shuffle< 7, 7, 7, 7>(a,b)), (bs::pack<T,4>(b[3])) );
  }

  // cardinal 8
  {
    bs::pack<T,8> a { boost::simd::Valmax<T>(),T(66),T(99),T(55)
                    , T(-9),T(77), T(23), boost::simd::Valmin<T>()
                    };

    bs::pack<T,8> b { T(36),T(27), boost::simd::Valmax<T>(),T(66)
                    , T(90), boost::simd::Valmin<T>(),T(-37), T(94)
                    };

    STF_ALL_EQUAL( (shuffle<-1,-1,-1,-1,-1,-1,-1,-1>(a,b)), (bs::Zero<bs::pack<T,8>>()) );
    STF_ALL_EQUAL( (shuffle< 0, 0, 0, 0, 0, 0, 0, 0>(a,b)), (bs::pack<T,8>(a[0])) );
    STF_ALL_EQUAL( (shuffle< 1, 1, 1, 1, 1, 1, 1, 1>(a,b)), (bs::pack<T,8>(a[1])) );
    STF_ALL_EQUAL( (shuffle< 2, 2, 2, 2, 2, 2, 2, 2>(a,b)), (bs::pack<T,8>(a[2])) );
    STF_ALL_EQUAL( (shuffle< 3, 3, 3, 3, 3, 3, 3, 3>(a,b)), (bs::pack<T,8>(a[3])) );
    STF_ALL_EQUAL( (shuffle< 4, 4, 4, 4, 4, 4, 4, 4>(a,b)), (bs::pack<T,8>(a[4])) );
    STF_ALL_EQUAL( (shuffle< 5, 5, 5, 5, 5, 5, 5, 5>(a,b)), (bs::pack<T,8>(a[5])) );
    STF_ALL_EQUAL( (shuffle< 6, 6, 6, 6, 6, 6, 6, 6>(a,b)), (bs::pack<T,8>(a[6])) );
    STF_ALL_EQUAL( (shuffle< 7, 7, 7, 7, 7, 7, 7, 7>(a,b)), (bs::pack<T,8>(a[7])) );

    STF_ALL_EQUAL( (shuffle< 8, 8, 8, 8, 8, 8, 8, 8>(a,b)), (bs::pack<T,8>(b[0])) );
    STF_ALL_EQUAL( (shuffle< 9, 9, 9, 9, 9, 9, 9, 9>(a,b)), (bs::pack<T,8>(b[1])) );
    STF_ALL_EQUAL( (shuffle<10,10,10,10,10,10,10,10>(a,b)), (bs::pack<T,8>(b[2])) );
    STF_ALL_EQUAL( (shuffle<11,11,11,11,11,11,11,11>(a,b)), (bs::pack<T,8>(b[3])) );
    STF_ALL_EQUAL( (shuffle<12,12,12,12,12,12,12,12>(a,b)), (bs::pack<T,8>(b[4])) );
    STF_ALL_EQUAL( (shuffle<13,13,13,13,13,13,13,13>(a,b)), (bs::pack<T,8>(b[5])) );
    STF_ALL_EQUAL( (shuffle<14,14,14,14,14,14,14,14>(a,b)), (bs::pack<T,8>(b[6])) );
    STF_ALL_EQUAL( (shuffle<15,15,15,15,15,15,15,15>(a,b)), (bs::pack<T,8>(b[7])) );
  }
}
