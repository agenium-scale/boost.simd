//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/real.hpp>
#include <scalar_test.hpp>

STF_CASE( "Check real constant behavior for IEEE types")
{
  using boost::simd::Real;

  STF_EXPR_IS   ( (Real<double,0x402ABD70A3D70A3DULL,0x4155EB85UL>() ) , double  );
  STF_EXPR_IS   ( (Real<float,0x402ABD70A3D70A3DULL,0x4155EB85UL>() ) , float  );
  STF_IEEE_EQUAL( (Real<double,0x402ABD70A3D70A3DULL,0x4155EB85UL>() ) , 13.37   );
  STF_IEEE_EQUAL( (Real<float,0x402ABD70A3D70A3DULL,0x4155EB85UL>() ) , 13.37f   );
}
