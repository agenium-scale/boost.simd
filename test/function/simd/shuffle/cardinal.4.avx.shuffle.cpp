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
            , (double)(std::uint64_t)(std::int64_t)
            )
{
  bs::pack<T,4> a{ Valmax<T>(), T(42), T(13), Valmin<T>() };
  bs::pack<T,4> b{ T(69), Valmin<T>(), T(37), T(0) };

  STF_ALL_EQUAL( (shuffle< 1, 4, 2, 6>(a,b)), (binary_ref< 1, 4, 2, 6>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 4, 2, 7>(a,b)), (binary_ref< 1, 4, 2, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 4, 3, 6>(a,b)), (binary_ref< 1, 4, 3, 6>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 4, 3, 7>(a,b)), (binary_ref< 1, 4, 3, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 5, 2, 6>(a,b)), (binary_ref< 1, 5, 2, 6>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 5, 2, 7>(a,b)), (binary_ref< 1, 5, 2, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 5, 3, 6>(a,b)), (binary_ref< 1, 5, 3, 6>(a,b)) );

  STF_ALL_EQUAL( (shuffle<-1, 4, 2, 6>(a,b)), (binary_ref<-1, 4, 2, 6>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 4, 2, 7>(a,b)), (binary_ref<-1, 4, 2, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 4, 3, 6>(a,b)), (binary_ref<-1, 4, 3, 6>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 4, 3, 7>(a,b)), (binary_ref<-1, 4, 3, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 5, 2, 6>(a,b)), (binary_ref<-1, 5, 2, 6>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 5, 2, 7>(a,b)), (binary_ref<-1, 5, 2, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 5, 3, 6>(a,b)), (binary_ref<-1, 5, 3, 6>(a,b)) );

  STF_ALL_EQUAL( (shuffle< 1,-1, 2, 6>(a,b)), (binary_ref< 1,-1, 2, 6>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1,-1, 2, 7>(a,b)), (binary_ref< 1,-1, 2, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1,-1, 3, 6>(a,b)), (binary_ref< 1,-1, 3, 6>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1,-1, 3, 7>(a,b)), (binary_ref< 1,-1, 3, 7>(a,b)) );

  STF_ALL_EQUAL( (shuffle< 1, 4,-1, 6>(a,b)), (binary_ref< 1, 4,-1, 6>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 4,-1, 7>(a,b)), (binary_ref< 1, 4,-1, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 5,-1, 6>(a,b)), (binary_ref< 1, 5,-1, 6>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 5,-1, 7>(a,b)), (binary_ref< 1, 5,-1, 7>(a,b)) );

  STF_ALL_EQUAL( (shuffle< 1, 4, 2,-1>(a,b)), (binary_ref< 1, 4, 2,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 4, 3,-1>(a,b)), (binary_ref< 1, 4, 3,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 5, 2,-1>(a,b)), (binary_ref< 1, 5, 2,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 5, 3,-1>(a,b)), (binary_ref< 1, 5, 3,-1>(a,b)) );

  STF_ALL_EQUAL( (shuffle<-1,-1, 2, 6>(a,b)), (binary_ref<-1,-1, 2, 6>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 2, 7>(a,b)), (binary_ref<-1,-1, 2, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 3, 6>(a,b)), (binary_ref<-1,-1, 3, 6>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 3, 7>(a,b)), (binary_ref<-1,-1, 3, 7>(a,b)) );

  STF_ALL_EQUAL( (shuffle<-1, 4, 2,-1>(a,b)), (binary_ref<-1, 4, 2,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 4, 3,-1>(a,b)), (binary_ref<-1, 4, 3,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 5, 2,-1>(a,b)), (binary_ref<-1, 5, 2,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 5, 3,-1>(a,b)), (binary_ref<-1, 5, 3,-1>(a,b)) );

  STF_ALL_EQUAL( (shuffle<0,-1,-1,6>(a,b)), (binary_ref<0,-1,-1,6>(a,b)) );
  STF_ALL_EQUAL( (shuffle<0,-1,-1,7>(a,b)), (binary_ref<0,-1,-1,7>(a,b)) );
  STF_ALL_EQUAL( (shuffle<1,-1,-1,6>(a,b)), (binary_ref<1,-1,-1,6>(a,b)) );
  STF_ALL_EQUAL( (shuffle<1,-1,-1,7>(a,b)), (binary_ref<1,-1,-1,7>(a,b)) );
}


STF_CASE_TPL( "Cardinal 4 binary shuffle resolving as AVX indirect mm_shuffle"
            , (double)(std::uint64_t)(std::int64_t)
            )
{
  bs::pack<T,4> a{ Valmax<T>(), T(42), T(13), Valmin<T>() };
  bs::pack<T,4> b{ T(69), Valmin<T>(), T(37), T(0) };

  STF_ALL_EQUAL( (shuffle<4,0,6,3>(a,b)), (binary_ref<4,0,6,3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<4,0,7,2>(a,b)), (binary_ref<4,0,7,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<4,0,7,3>(a,b)), (binary_ref<4,0,7,3>(a,b)) );

  STF_ALL_EQUAL( (shuffle<4,1,6,2>(a,b)), (binary_ref<4,1,6,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<4,1,7,2>(a,b)), (binary_ref<4,1,7,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<4,1,7,3>(a,b)), (binary_ref<4,1,7,3>(a,b)) );

  STF_ALL_EQUAL( (shuffle<5,0,6,2>(a,b)), (binary_ref<5,0,6,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<5,0,6,3>(a,b)), (binary_ref<5,0,6,3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<5,0,7,2>(a,b)), (binary_ref<5,0,7,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<5,0,7,3>(a,b)), (binary_ref<5,0,7,3>(a,b)) );

  STF_ALL_EQUAL( (shuffle<5,1,6,2>(a,b)), (binary_ref<5,1,6,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<5,1,6,3>(a,b)), (binary_ref<5,1,6,3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<5,1,7,2>(a,b)), (binary_ref<5,1,7,2>(a,b)) );

  STF_ALL_EQUAL( (shuffle<4,0,6,-1>(a,b)), (binary_ref<4,0,6,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<4,0,7,-1>(a,b)), (binary_ref<4,0,7,-1>(a,b)) );

  STF_ALL_EQUAL( (shuffle<4,1,7,-1>(a,b)), (binary_ref<4,1,7,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<4,1,7,-1>(a,b)), (binary_ref<4,1,7,-1>(a,b)) );

  STF_ALL_EQUAL( (shuffle<5,0,6,-1>(a,b)), (binary_ref<5,0,6,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<5,0,7,-1>(a,b)), (binary_ref<5,0,7,-1>(a,b)) );

  STF_ALL_EQUAL( (shuffle<5,1,6,-1>(a,b)), (binary_ref<5,1,6,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<5,1,7,-1>(a,b)), (binary_ref<5,1,7,-1>(a,b)) );

  STF_ALL_EQUAL( (shuffle<4,0,-1,3>(a,b)), (binary_ref<4,0,-1,3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<4,0,-1,2>(a,b)), (binary_ref<4,0,-1,2>(a,b)) );

  STF_ALL_EQUAL( (shuffle<4,1,-1,2>(a,b)), (binary_ref<4,1,-1,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<4,1,-1,3>(a,b)), (binary_ref<4,1,-1,3>(a,b)) );

  STF_ALL_EQUAL( (shuffle<5,0,-1,2>(a,b)), (binary_ref<5,0,-1,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<5,0,-1,3>(a,b)), (binary_ref<5,0,-1,3>(a,b)) );

  STF_ALL_EQUAL( (shuffle<5,1,-1,2>(a,b)), (binary_ref<5,1,-1,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<5,1,-1,3>(a,b)), (binary_ref<5,1,-1,3>(a,b)) );

  STF_ALL_EQUAL( (shuffle<4,-1,6,2>(a,b)), (binary_ref<4,-1,6,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<4,-1,6,3>(a,b)), (binary_ref<4,-1,6,3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<4,-1,7,2>(a,b)), (binary_ref<4,-1,7,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<4,-1,7,3>(a,b)), (binary_ref<4,-1,7,3>(a,b)) );

  STF_ALL_EQUAL( (shuffle<5,-1,6,2>(a,b)), (binary_ref<5,-1,6,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<5,-1,6,3>(a,b)), (binary_ref<5,-1,6,3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<5,-1,7,2>(a,b)), (binary_ref<5,-1,7,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<5,-1,7,3>(a,b)), (binary_ref<5,-1,7,3>(a,b)) );

  STF_ALL_EQUAL( (shuffle<-1,0,6,2>(a,b)), (binary_ref<-1,0,6,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,0,6,3>(a,b)), (binary_ref<-1,0,6,3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,0,7,2>(a,b)), (binary_ref<-1,0,7,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,0,7,3>(a,b)), (binary_ref<-1,0,7,3>(a,b)) );

  STF_ALL_EQUAL( (shuffle<-1,1,6,2>(a,b)), (binary_ref<-1,1,6,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,1,6,3>(a,b)), (binary_ref<-1,1,6,3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,1,7,2>(a,b)), (binary_ref<-1,1,7,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,1,7,3>(a,b)), (binary_ref<-1,1,7,3>(a,b)) );

  STF_ALL_EQUAL( (shuffle<-1,-1, 6, 2>(a,b)), (binary_ref<-1,-1, 6, 2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 6, 3>(a,b)), (binary_ref<-1,-1, 6, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 7, 2>(a,b)), (binary_ref<-1,-1, 7, 2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 7, 3>(a,b)), (binary_ref<-1,-1, 7, 3>(a,b)) );

  STF_ALL_EQUAL( (shuffle<-1, 0, 6,-1>(a,b)), (binary_ref<-1, 0, 6,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 0, 6,-1>(a,b)), (binary_ref<-1, 0, 6,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 1, 7,-1>(a,b)), (binary_ref<-1, 1, 7,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 1, 7,-1>(a,b)), (binary_ref<-1, 1, 7,-1>(a,b)) );

  STF_ALL_EQUAL( (shuffle<4,-1,-1,3>(a,b)), (binary_ref<4,-1,-1,3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<4,-1,-1,2>(a,b)), (binary_ref<4,-1,-1,2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<5,-1,-1,3>(a,b)), (binary_ref<5,-1,-1,3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<5,-1,-1,2>(a,b)), (binary_ref<5,-1,-1,2>(a,b)) );
}
