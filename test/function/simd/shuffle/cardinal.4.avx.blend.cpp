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

STF_CASE_TPL( "Cardinal 4 unary shuffle resolving as AVX blend", (double)(std::uint64_t)(std::int64_t))
{
  bs::pack<T,4> a{ Valmax<T>(), T(42), T(13), Valmin<T>() };
  bs::pack<T,4> b{ T(69), Valmin<T>(), T(37), T(0) };

  STF_ALL_EQUAL( (shuffle< 0, 1, 2,-1>(a)), (unary_ref< 0, 1, 2,-1>(a)) );
  STF_ALL_EQUAL( (shuffle< 0, 1,-1, 3>(a)), (unary_ref< 0, 1,-1, 3>(a)) );
  STF_ALL_EQUAL( (shuffle< 0, 1,-1,-1>(a)), (unary_ref< 0, 1,-1,-1>(a)) );
  STF_ALL_EQUAL( (shuffle< 0,-1, 2, 3>(a)), (unary_ref< 0,-1, 2, 3>(a)) );
  STF_ALL_EQUAL( (shuffle< 0,-1,-1, 3>(a)), (unary_ref< 0,-1,-1, 3>(a)) );
  STF_ALL_EQUAL( (shuffle< 0,-1,-1,-1>(a)), (unary_ref< 0,-1,-1,-1>(a)) );

  STF_ALL_EQUAL( (shuffle<-1, 1, 2, 3>(a)), (unary_ref<-1, 1, 2, 3>(a)) );
  STF_ALL_EQUAL( (shuffle<-1, 1, 2,-1>(a)), (unary_ref<-1, 1, 2,-1>(a)) );
  STF_ALL_EQUAL( (shuffle<-1, 1,-1,-1>(a)), (unary_ref<-1, 1,-1,-1>(a)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 2, 3>(a)), (unary_ref<-1,-1, 2, 3>(a)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 2, 3>(a)), (unary_ref<-1,-1, 2, 3>(a)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 2, 3>(a)), (unary_ref<-1,-1, 2, 3>(a)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 2,-1>(a)), (unary_ref<-1,-1, 2,-1>(a)) );
  STF_ALL_EQUAL( (shuffle<-1,-1,-1, 3>(a)), (unary_ref<-1,-1,-1, 3>(a)) );
}

STF_CASE_TPL( "Cardinal 4 binary shuffle resolving as AVX blend", (double)(std::uint64_t)(std::int64_t))
{
  bs::pack<T,4> a{ Valmax<T>(), T(42), T(13), Valmin<T>() };
  bs::pack<T,4> b{ T(69), Valmin<T>(), T(37), T(0) };

  STF_ALL_EQUAL( (shuffle< 0, 1, 2, 7>(a,b)), (binary_ref< 0, 1, 2, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0, 1, 2,-1>(a,b)), (binary_ref< 0, 1, 2,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0, 1, 6, 3>(a,b)), (binary_ref< 0, 1, 6, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0, 1, 6, 7>(a,b)), (binary_ref< 0, 1, 6, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0, 1,-1, 3>(a,b)), (binary_ref< 0, 1,-1, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0, 1,-1,-1>(a,b)), (binary_ref< 0, 1,-1,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0, 5, 2, 3>(a,b)), (binary_ref< 0, 5, 2, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0, 5, 2, 7>(a,b)), (binary_ref< 0, 5, 2, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0, 5, 6, 3>(a,b)), (binary_ref< 0, 5, 6, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0, 5, 6, 7>(a,b)), (binary_ref< 0, 5, 6, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0,-1, 2, 3>(a,b)), (binary_ref< 0,-1, 2, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0,-1,-1, 3>(a,b)), (binary_ref< 0,-1,-1, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0,-1,-1,-1>(a,b)), (binary_ref< 0,-1,-1,-1>(a,b)) );

  STF_ALL_EQUAL( (shuffle< 4, 1, 2, 3>(a,b)), (binary_ref< 4, 1, 2, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 4, 1, 2, 7>(a,b)), (binary_ref< 4, 1, 2, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 4, 1, 6, 3>(a,b)), (binary_ref< 4, 1, 6, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 4, 1, 6, 7>(a,b)), (binary_ref< 4, 1, 6, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 4, 5, 2, 3>(a,b)), (binary_ref< 4, 5, 2, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 4, 5, 2, 7>(a,b)), (binary_ref< 4, 5, 2, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 4, 5, 6, 3>(a,b)), (binary_ref< 4, 5, 6, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 4, 5, 6,-1>(a,b)), (binary_ref< 4, 5, 6,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 4, 5, 6, 7>(a,b)), (binary_ref< 4, 5, 6, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 4, 5,-1, 7>(a,b)), (binary_ref< 4, 5,-1, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 4, 5,-1,-1>(a,b)), (binary_ref< 4, 5,-1,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 4,-1, 6, 7>(a,b)), (binary_ref< 4,-1, 6, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 4,-1,-1,-1>(a,b)), (binary_ref< 4,-1,-1,-1>(a,b)) );

  STF_ALL_EQUAL( (shuffle<-1, 1, 2, 3>(a,b)), (binary_ref<-1, 1, 2, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 1, 2,-1>(a,b)), (binary_ref<-1, 1, 2,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 1,-1,-1>(a,b)), (binary_ref<-1, 1,-1,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 5, 6, 7>(a,b)), (binary_ref<-1, 5, 6, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 5, 6,-1>(a,b)), (binary_ref<-1, 5, 6,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 5,-1,-1>(a,b)), (binary_ref<-1, 5,-1,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 2, 3>(a,b)), (binary_ref<-1,-1, 2, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 2, 3>(a,b)), (binary_ref<-1,-1, 2, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 2, 3>(a,b)), (binary_ref<-1,-1, 2, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 2,-1>(a,b)), (binary_ref<-1,-1, 2,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 6, 7>(a,b)), (binary_ref<-1,-1, 6, 7>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 6,-1>(a,b)), (binary_ref<-1,-1, 6,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,-1,-1, 3>(a,b)), (binary_ref<-1,-1,-1, 3>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1,-1,-1, 7>(a,b)), (binary_ref<-1,-1,-1, 7>(a,b)) );
}
