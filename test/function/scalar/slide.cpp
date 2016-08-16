//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/scalar/slide.hpp>
#include <scalar_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Check unary slide behavior", STF_NUMERIC_TYPES )
{
  STF_EQUAL( bs::slide< 0>(T(42)), T(42) );
}

STF_CASE_TPL( "Check binary slide behavior", STF_NUMERIC_TYPES )
{
  STF_EQUAL( bs::slide<-1>(T(13),T(37)), T(37)  );
  STF_EQUAL( bs::slide< 0>(T(13),T(37)), T(13)  );
  STF_EQUAL( bs::slide<+1>(T(13),T(37)), T(37)  );
}
