//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/broadcast.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>


STF_CASE_TPL( "Check splat behavior with all types", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using bs::broadcast;
//   using r_t = decltype(broadcast(T(2), brigand::int_<0>()));
//   STF_TYPE_IS(r_t, T);

  STF_EQUAL(broadcast<0>(T(2)),  T(2));
//  STF_ASSERT(broadcast<1>(T(2)));
}


