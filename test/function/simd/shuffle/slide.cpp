//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/slide.hpp>
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Unary slide shuffle - cardinal 2", STF_NUMERIC_TYPES)
{
  bs::pack<T,2> a{ Valmax<T>(), T(42) };
  STF_ALL_EQUAL( (shuffle<-1, 0>(a)), bs::slide<-1>(a) );
  STF_ALL_EQUAL( (shuffle< 1,-1>(a)), bs::slide<+1>(a) );
}

STF_CASE_TPL( "Binary slide shuffle - cardinal 2", STF_NUMERIC_TYPES)
{
  bs::pack<T,2> a{ Valmax<T>(), T(42) };
  bs::pack<T,2> b{ T(69)      , Valmin<T>() };

  STF_ALL_EQUAL( (shuffle<-1, 0>(a,b)), bs::slide<-1>(a) );
  STF_ALL_EQUAL( (shuffle< 1,-1>(a,b)), bs::slide<+1>(a) );
  STF_ALL_EQUAL( (shuffle<-1, 2>(a,b)), bs::slide<-1>(b) );
  STF_ALL_EQUAL( (shuffle< 3,-1>(a,b)), bs::slide<+1>(b) );
}

STF_CASE_TPL( "Unary slide shuffle - cardinal 4", STF_NUMERIC_TYPES)
{
  bs::pack<T,4> a{ Valmax<T>(), T(42), T(69), Valmin<T>() };

  STF_ALL_EQUAL( (shuffle<-1,-1,-1, 0>(a)), bs::slide<-3>(a) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 0, 1>(a)), bs::slide<-2>(a) );
  STF_ALL_EQUAL( (shuffle<-1, 0, 1, 2>(a)), bs::slide<-1>(a) );
  STF_ALL_EQUAL( (shuffle< 1, 2, 3,-1>(a)), bs::slide<+1>(a) );
  STF_ALL_EQUAL( (shuffle< 2, 3,-1,-1>(a)), bs::slide<+2>(a) );
  STF_ALL_EQUAL( (shuffle< 3,-1,-1,-1>(a)), bs::slide<+3>(a) );
}

STF_CASE_TPL( "Binary slide shuffle - cardinal 4", STF_NUMERIC_TYPES)
{
  bs::pack<T,4> a{ Valmax<T>(), T(42), T(69), Valmin<T>() };
  bs::pack<T,4> b{ T(13), Valmin<T>(), T(37), Valmax<T>() };

  STF_ALL_EQUAL( (shuffle<-1,-1,-1, 0>(a,b)), bs::slide<-3>(a) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 0, 1>(a,b)), bs::slide<-2>(a) );
  STF_ALL_EQUAL( (shuffle<-1, 0, 1, 2>(a,b)), bs::slide<-1>(a) );
  STF_ALL_EQUAL( (shuffle< 1, 2, 3,-1>(a,b)), bs::slide<+1>(a) );
  STF_ALL_EQUAL( (shuffle< 2, 3,-1,-1>(a,b)), bs::slide<+2>(a) );
  STF_ALL_EQUAL( (shuffle< 3,-1,-1,-1>(a,b)), bs::slide<+3>(a) );

  STF_ALL_EQUAL( (shuffle<-1,-1,-1, 4>(a,b)), bs::slide<-3>(b) );
  STF_ALL_EQUAL( (shuffle<-1,-1, 4, 5>(a,b)), bs::slide<-2>(b) );
  STF_ALL_EQUAL( (shuffle<-1, 4, 5, 6>(a,b)), bs::slide<-1>(b) );
  STF_ALL_EQUAL( (shuffle< 5, 6, 7,-1>(a,b)), bs::slide<+1>(b) );
  STF_ALL_EQUAL( (shuffle< 6, 7,-1,-1>(a,b)), bs::slide<+2>(b) );
  STF_ALL_EQUAL( (shuffle< 7,-1,-1,-1>(a,b)), bs::slide<+3>(b) );
}
