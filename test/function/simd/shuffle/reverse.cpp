//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/function/reverse.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Unary reverse shuffle", STF_NUMERIC_TYPES)
{
  // cardinal 2
  {
    bs::pack<T,2> a{ Valmax<T>(), T(42) };
    STF_ALL_EQUAL( (shuffle<1,0>(a)), bs::reverse(a) );
  }

  // cardinal 4
  {
    bs::pack<T,4> a{ Valmax<T>(), T(42), T(69), Valmin<T>() };
    STF_ALL_EQUAL( (shuffle<3,2,1,0>(a)), bs::reverse(a) );
  }

  // cardinal 8
  {
    bs::pack<T,8> a { boost::simd::Valmax<T>(),T(66),T(99),T(55)
                    , T(-1),T(77), T(23), boost::simd::Valmin<T>()
                    };

    STF_ALL_EQUAL( (shuffle<7,6,5,4,3,2,1,0>(a)), bs::reverse(a) );
  }
}

STF_CASE_TPL( "Binary reverse shuffle", STF_NUMERIC_TYPES)
{
  // cardinal 2
  {
    bs::pack<T,2> a{ Valmax<T>(), T(42)       };
    bs::pack<T,2> b{ T(69)      , Valmin<T>() };

    STF_ALL_EQUAL( (shuffle<1,0>(a,b)), bs::reverse(a) );
    STF_ALL_EQUAL( (shuffle<3,2>(a,b)), bs::reverse(b) );
  }

  // cardinal 4
  {
    bs::pack<T,4> a{ Valmax<T>(), T(42), T(69), Valmin<T>() };
    bs::pack<T,4> b{ T(13), Valmin<T>(), T(37), Valmax<T>() };

    STF_ALL_EQUAL( (shuffle<3,2,1,0>(a,b)), bs::reverse(a) );
    STF_ALL_EQUAL( (shuffle<7,6,5,4>(a,b)), bs::reverse(b) );
  }

  // cardinal 8
  {
    bs::pack<T,8> a { boost::simd::Valmax<T>(),T(66),T(99),T(55)
                    , T(-1),T(77), T(23), boost::simd::Valmin<T>()
                    };

    bs::pack<T,8> b { T(36),T(27), boost::simd::Valmax<T>(),T(66)
                    , T(10), boost::simd::Valmin<T>(),T(-37), T(14)
                    };

    STF_ALL_EQUAL( (shuffle<7,6,5,4,3,2,1,0>(a,b)), bs::reverse(a) );
    STF_ALL_EQUAL( (shuffle<15,14,13,12,11,10,9,8>(a,b)), bs::reverse(b) );
  }
}
