//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/types.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check constant behavior for integral values", STF_NATIVE_TYPES)
{
  using std::integral_constant;
  using boost::simd::Constant;
  using boost::simd::functional::constant;

  STF_EXPR_IS( (Constant<integral_constant<T,42>>()  ) , T      );
  STF_EQUAL  ( (Constant<integral_constant<T,42>>()  ) , T(42)  );
  STF_EQUAL  ( (constant(integral_constant<T,42>{})  ) , T(42)  );
}

STF_CASE( "Check constant behavior for double values")
{
  using boost::simd::double_;
  using boost::simd::Constant;
  using boost::simd::functional::constant;

  STF_EXPR_IS   ( (Constant<double_<0x402ABD70A3D70A3DULL>>() ) , double  );
  STF_IEEE_EQUAL( (Constant<double_<0x402ABD70A3D70A3DULL>>() ) , 13.37   );
  STF_IEEE_EQUAL( (constant(double_<0x402ABD70A3D70A3DULL>{}) ) , 13.37   );
}

STF_CASE( "Check constant behavior for single values")
{
  using boost::simd::single_;
  using boost::simd::Constant;
  using boost::simd::functional::constant;

  STF_EXPR_IS   ( (Constant<single_<0x4155EB85UL>>()  ) , float   );
  STF_IEEE_EQUAL( (Constant<single_<0x4155EB85UL>>()  ) , 13.37f  );
  STF_IEEE_EQUAL( (constant(single_<0x4155EB85UL>{})  ) , 13.37f  );
}

STF_CASE_TPL( "Check constant behavior for ratio", STF_NATIVE_TYPES STF_IEEE_TYPES)
{
  using boost::simd::ratio;
  using boost::simd::Constant;
  using boost::simd::functional::constant;

  STF_EXPR_IS   ( (Constant<ratio<T,7,21>>()  ) , T         );
  STF_IEEE_EQUAL( (Constant<ratio<T,7,21>>()  ) , T(7./21.) );
  STF_IEEE_EQUAL( (constant(ratio<T,7,21>{})  ) , T(7./21.) );

  STF_EXPR_IS   ( (Constant<ratio<T,42>>()  ) , T     );
  STF_IEEE_EQUAL( (Constant<ratio<T,42>>()  ) , T(42) );
  STF_IEEE_EQUAL( (constant(ratio<T,42>{})  ) , T(42) );
}
