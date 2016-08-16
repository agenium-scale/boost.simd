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

STF_CASE_TPL( "unary shuffle of cardinal 2", STF_NUMERIC_TYPES)
{
  bs::pack<T,2> a{ Valmax<T>(), T(42) };

  STF_ALL_EQUAL( (shuffle< 0, 0>(a)), (unary_ref< 0, 0>(a)) );
  STF_ALL_EQUAL( (shuffle< 0, 1>(a)), (unary_ref< 0, 1>(a)) );
  STF_ALL_EQUAL( (shuffle< 0,-1>(a)), (unary_ref< 0,-1>(a)) );
  STF_ALL_EQUAL( (shuffle< 1,-1>(a)), (unary_ref< 1,-1>(a)) );
  STF_ALL_EQUAL( (shuffle< 1, 0>(a)), (unary_ref< 1, 0>(a)) );
  STF_ALL_EQUAL( (shuffle< 1, 1>(a)), (unary_ref< 1, 1>(a)) );
  STF_ALL_EQUAL( (shuffle<-1, 1>(a)), (unary_ref<-1, 1>(a)) );
  STF_ALL_EQUAL( (shuffle<-1, 0>(a)), (unary_ref<-1, 0>(a)) );
  STF_ALL_EQUAL( (shuffle<-1,-1>(a)), (unary_ref<-1,-1>(a)) );
}
