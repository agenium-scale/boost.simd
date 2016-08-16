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
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Unary identity shuffle", STF_NUMERIC_TYPES)
{
  // cardinal 4
  {
    bs::pack<T,4> a{ Valmax<T>(), T(42), T(69), Valmin<T>() };
    STF_ALL_EQUAL( (shuffle<0,1,2,3>(a)), a );
  }

  // cardinal 8
  {
    bs::pack<T,8> a { boost::simd::Valmax<T>(),T(66),T(99),T(55)
                    , T(-1),T(77), T(23), boost::simd::Valmin<T>()
                    };

    STF_ALL_EQUAL( (shuffle<0,1,2,3,4,5,6,7>(a)), a );
  }
}

STF_CASE_TPL( "Binary identity shuffle", STF_NUMERIC_TYPES)
{
  // cardinal 4
  {
    bs::pack<T,4> a{ Valmax<T>(), T(42), T(69), Valmin<T>() };
    bs::pack<T,4> b{ T(13), Valmin<T>(), T(37), Valmax<T>() };

    STF_ALL_EQUAL( (shuffle<0,1,2,3>(a,b)), a );
    STF_ALL_EQUAL( (shuffle<4,5,6,7>(a,b)), b );
  }

  // cardinal 8
  {
    bs::pack<T,8> a { boost::simd::Valmax<T>(),T(66),T(99),T(55)
                    , T(-1),T(77), T(23), boost::simd::Valmin<T>()
                    };

    bs::pack<T,8> b { T(36),T(27), boost::simd::Valmax<T>(),T(66)
                    , T(10), boost::simd::Valmin<T>(),T(-37), T(14)
                    };

    STF_ALL_EQUAL( (shuffle<0,1,2,3,4,5,6,7>(a,b)), a );
    STF_ALL_EQUAL( (shuffle<8,9,10,11,12,13,14,15>(a,b)), b );
  }
}
