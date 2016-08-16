//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Unary broadcast shuffle", STF_NUMERIC_TYPES)
{
  // cardinal 4
  {
    bs::pack<T,4> a{ Valmax<T>(), T(42), T(69), Valmin<T>() };
    STF_ALL_EQUAL( (shuffle<-1,-1,-1,-1>(a)), (bs::Zero<bs::pack<T,4>>())  );
    STF_ALL_EQUAL( (shuffle< 0, 0, 0, 0>(a)), (bs::pack<T,4>(a[0])) );
    STF_ALL_EQUAL( (shuffle< 1, 1, 1, 1>(a)), (bs::pack<T,4>(a[1])) );
    STF_ALL_EQUAL( (shuffle< 2, 2, 2, 2>(a)), (bs::pack<T,4>(a[2])) );
    STF_ALL_EQUAL( (shuffle< 3, 3, 3, 3>(a)), (bs::pack<T,4>(a[3])) );
  }

  // cardinal 8
  {
    bs::pack<T,8> a { boost::simd::Valmax<T>(),T(66),T(99),T(55)
                    , T(-1),T(77), T(23), boost::simd::Valmin<T>()
                    };

    STF_ALL_EQUAL( (shuffle<-1,-1,-1,-1,-1,-1,-1,-1>(a)), (bs::Zero<bs::pack<T,8>>()) );
    STF_ALL_EQUAL( (shuffle< 0, 0, 0, 0, 0, 0, 0, 0>(a)), (bs::pack<T,8>(a[0])) );
    STF_ALL_EQUAL( (shuffle< 1, 1, 1, 1, 1, 1, 1, 1>(a)), (bs::pack<T,8>(a[1])) );
    STF_ALL_EQUAL( (shuffle< 2, 2, 2, 2, 2, 2, 2, 2>(a)), (bs::pack<T,8>(a[2])) );
    STF_ALL_EQUAL( (shuffle< 3, 3, 3, 3, 3, 3, 3, 3>(a)), (bs::pack<T,8>(a[3])) );
    STF_ALL_EQUAL( (shuffle< 4, 4, 4, 4, 4, 4, 4, 4>(a)), (bs::pack<T,8>(a[4])) );
    STF_ALL_EQUAL( (shuffle< 5, 5, 5, 5, 5, 5, 5, 5>(a)), (bs::pack<T,8>(a[5])) );
    STF_ALL_EQUAL( (shuffle< 6, 6, 6, 6, 6, 6, 6, 6>(a)), (bs::pack<T,8>(a[6])) );
    STF_ALL_EQUAL( (shuffle< 7, 7, 7, 7, 7, 7, 7, 7>(a)), (bs::pack<T,8>(a[7])) );
  }
}
