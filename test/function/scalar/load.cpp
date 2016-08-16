//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/load.hpp>
#include <boost/simd/mask.hpp>
#include <boost/simd/logical.hpp>

#include <scalar_test.hpp>

STF_CASE_TPL( "Check load behavior with simple pointer", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;

  T src(42);
  bs::logical<T> lsrc{true};

  STF_EQUAL( bs::load<T>(&src), src );
  STF_EQUAL( bs::load<bs::logical<T>>(&src), lsrc );
}

STF_CASE_TPL( "Check load behavior with masked pointer", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;

  T src(42);
  bs::logical<T> lsrc{true};

  STF_EQUAL( bs::load<T>(bs::mask(&src, true)), src );
  STF_EQUAL( bs::load<T>(bs::mask(&src, false)), T{0} );
  STF_EQUAL( bs::load<T>(bs::mask(&src, true, T{69})) , src   );
  STF_EQUAL( bs::load<T>(bs::mask(&src, false, T{69})), T{69} );

  STF_EQUAL( bs::load<bs::logical<T>>(bs::mask(&src,true)) , lsrc );
  STF_EQUAL( bs::load<bs::logical<T>>(bs::mask(&src,false)), false);
}

STF_CASE_TPL( "Check load behavior with simple pointer and offset", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;

  T src[3] = { T(~0),T(42), T(~0) };
  bs::logical<T> lsrc[3] = { false, true, false };

  STF_EQUAL( bs::load<T>(&src[0],1), src[1] );
  STF_EQUAL( bs::load<bs::logical<T>>(&src[0],1), lsrc[1] );
}

STF_CASE_TPL( "Check load behavior with masked pointer and offset", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;

  T src[3] = { T(~0),T(42), T(~0) };
  bs::logical<T> lsrc[3] = { false, true, false };

  STF_EQUAL( bs::load<T>(bs::mask(&src[0], true),1), src[1] );
  STF_EQUAL( bs::load<T>(bs::mask(&src[0], false),1), T{0} );
  STF_EQUAL( bs::load<T>(bs::mask(&src[0], true, T{69}),1), src[1] );
  STF_EQUAL( bs::load<T>(bs::mask(&src[0], false, T{69}),1), T{69} );

  STF_EQUAL( bs::load<bs::logical<T>>(bs::mask(&src[0],true),1) , lsrc[1] );
  STF_EQUAL( bs::load<bs::logical<T>>(bs::mask(&src[0],false),1), false);
}
