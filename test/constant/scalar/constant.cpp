//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/constant.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check constant behavior for signed integral values", STF_SIGNED_INTEGRAL_TYPES)
{
  using boost::simd::Constant;
  STF_EXPR_IS( (Constant<T,42>()  ) , T      );
  STF_EQUAL  ( (Constant<T,42>()  ) , T(42)  );

  STF_EXPR_IS( (Constant<T,-69>()  ) , T      );
  STF_EQUAL  ( (Constant<T,-69>()  ) , T(-69) );

  STF_EXPR_IS( (Constant<T,~0>()  ) , T      );
  STF_EQUAL  ( (Constant<T,~0>()  ) , T(~0) );
}

STF_CASE_TPL( "Check constant behavior for unsigned integral values", STF_UNSIGNED_INTEGRAL_TYPES)
{
  using boost::simd::Constant;

  STF_EXPR_IS( (Constant<T,42>()  ) , T      );
  STF_EQUAL  ( (Constant<T,42>()  ) , T(42)  );

  STF_EXPR_IS( (Constant<T,T(~0)>()  ) , T      );
  STF_EQUAL  ( (Constant<T,T(~0)>()  ) , T(~0) );
}

STF_CASE( "Check constant behavior for double values")
{
  using boost::simd::Constant;

  STF_EXPR_IS   ( (Constant<double,0x402ABD70A3D70A3DULL>()   ) , double  );
  STF_IEEE_EQUAL( (Constant<double,0x402ABD70A3D70A3DULL>()   ) , 13.37   );
  STF_IEEE_EQUAL( (Constant<double,13817391734754107382ULL>() ) , -0.13466110473359521604 );
}

STF_CASE( "Check constant behavior for single values")
{
  using boost::simd::Constant;

  STF_EXPR_IS   ( (Constant<float,0x4155EB85UL>() ) , float   );
  STF_IEEE_EQUAL( (Constant<float,0x4155EB85UL>() ) , 13.37f  );
}

