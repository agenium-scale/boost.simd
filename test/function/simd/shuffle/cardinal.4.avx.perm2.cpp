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

STF_CASE_TPL( "Cardinal 4 shuffles resolving as AVX permute2f"
            , (double)(std::int64_t)(std::uint64_t)
            )
{
  bs::pack<T,4> a{ Valmax<T>(), T(42), T(13), Valmin<T>() };
  bs::pack<T,4> b{ T(69), Valmin<T>(), T(37), T(0) };

  STF_ALL_EQUAL( (shuffle<2, 3, 0, 1>(a))  , ( unary_ref<2, 3, 0, 1>(a)  )  );

  STF_ALL_EQUAL( (shuffle<2, 3, 0, 1>(a,b)), (binary_ref<2, 3, 0, 1>(a,b))  );
  STF_ALL_EQUAL( (shuffle<4, 5, 0, 1>(a,b)), (binary_ref<4, 5, 0, 1>(a,b))  );
  STF_ALL_EQUAL( (shuffle<6, 7, 0, 1>(a,b)), (binary_ref<6, 7, 0, 1>(a,b))  );
  STF_ALL_EQUAL( (shuffle<6, 7, 2, 3>(a,b)), (binary_ref<6, 7, 2, 3>(a,b))  );
  STF_ALL_EQUAL( (shuffle<0, 1, 4, 5>(a,b)), (binary_ref<0, 1, 4, 5>(a,b))  );
  STF_ALL_EQUAL( (shuffle<2, 3, 4, 5>(a,b)), (binary_ref<2, 3, 4, 5>(a,b))  );
  STF_ALL_EQUAL( (shuffle<6, 7, 4, 5>(a,b)), (binary_ref<6, 7, 4, 5>(a,b))  );
  STF_ALL_EQUAL( (shuffle<2, 3, 6, 7>(a,b)), (binary_ref<2, 3, 6, 7>(a,b))  );
}
