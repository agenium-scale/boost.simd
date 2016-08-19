//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/ratio.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL( "Check constant behavior for ratio", STF_NUMERIC_TYPES)
{
  using boost::simd::Ratio;

  STF_EXPR_IS   ( (Ratio<T,7,21>()  ) , T         );
  STF_IEEE_EQUAL( (Ratio<T,7,21>()  ) , T(7./21.) );

  STF_EXPR_IS   ( (Ratio<T,7>()  ) , T    );
  STF_IEEE_EQUAL( (Ratio<T,7>()  ) , T(7) );
}
