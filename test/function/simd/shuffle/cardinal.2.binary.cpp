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

STF_CASE_TPL( "binary shuffle of cardinal 2", STF_NUMERIC_TYPES)
{
  bs::pack<T,2> a{ Valmax<T>(), T(42) };
  bs::pack<T,2> b{ T(69), Valmin<T>() };

  STF_ALL_EQUAL( (shuffle<-1,-1>(a,b)), (binary_ref<-1,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 0>(a,b)), (binary_ref<-1, 0>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 1>(a,b)), (binary_ref<-1, 1>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 2>(a,b)), (binary_ref<-1, 2>(a,b)) );
  STF_ALL_EQUAL( (shuffle<-1, 3>(a,b)), (binary_ref<-1, 3>(a,b)) );

  STF_ALL_EQUAL( (shuffle< 0,-1>(a,b)), (binary_ref< 0,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0, 0>(a,b)), (binary_ref< 0, 0>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0, 1>(a,b)), (binary_ref< 0, 1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0, 2>(a,b)), (binary_ref< 0, 2>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 0, 3>(a,b)), (binary_ref< 0, 3>(a,b)) );

  STF_ALL_EQUAL( (shuffle< 1,-1>(a,b)), (binary_ref< 1,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 0>(a,b)), (binary_ref< 1, 0>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 1>(a,b)), (binary_ref< 1, 1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 2>(a,b)), (binary_ref< 1, 2>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 1, 3>(a,b)), (binary_ref< 1, 3>(a,b)) );

  STF_ALL_EQUAL( (shuffle< 2,-1>(a,b)), (binary_ref< 2,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 2, 0>(a,b)), (binary_ref< 2, 0>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 2, 1>(a,b)), (binary_ref< 2, 1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 2, 2>(a,b)), (binary_ref< 2, 2>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 2, 3>(a,b)), (binary_ref< 2, 3>(a,b)) );

  STF_ALL_EQUAL( (shuffle< 3,-1>(a,b)), (binary_ref< 3,-1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 3, 0>(a,b)), (binary_ref< 3, 0>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 3, 1>(a,b)), (binary_ref< 3, 1>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 3, 2>(a,b)), (binary_ref< 3, 2>(a,b)) );
  STF_ALL_EQUAL( (shuffle< 3, 3>(a,b)), (binary_ref< 3, 3>(a,b)) );

}
