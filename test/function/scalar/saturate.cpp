//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/saturate.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>

STF_CASE_TPL (" saturate types check",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::saturate;
  using bs::Valmax;
  using bs::Valmin;


  // return type conformity test
  STF_EXPR_IS( saturate<T>(float(1)), float);
  STF_EXPR_IS( saturate<T>(double(1)), double);
  STF_EXPR_IS( saturate<T>(int8_t(1)), int8_t);
  STF_EXPR_IS( saturate<T>(int16_t(1)), int16_t);
  STF_EXPR_IS( saturate<T>(int32_t(1)), int32_t);
  STF_EXPR_IS( saturate<T>(int64_t(1)), int64_t);
  STF_EXPR_IS( saturate<T>(uint8_t(1)), uint8_t);
  STF_EXPR_IS( saturate<T>(uint16_t(1)), uint16_t);
  STF_EXPR_IS( saturate<T>(uint32_t(1)), uint32_t);
  STF_EXPR_IS( saturate<T>(uint64_t(1)), uint64_t);
}

STF_CASE_TPL (" saturate floating with floating",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::saturate;
  using bs::Valmax;
  using bs::Valmin;
  using bs::Inf;
  using bs::Minf;

  STF_EQUAL( saturate<T>(Valmax<float>()), Valmax<float>());
  STF_EQUAL( saturate<T>(Valmax<double>()), double(Valmax<T>()));
  STF_EQUAL( saturate<T>(Valmin<float>()), Valmin<float>());
  STF_EQUAL( saturate<T>(Valmin<double>()), double(Valmin<T>()));
  STF_EQUAL( saturate<T>(Inf<float>()), Inf<float>());
  STF_EQUAL( saturate<T>(Inf<double>()), double(Inf<T>()));
  STF_EQUAL( saturate<T>(Minf<float>()), Minf<float>());
  STF_EQUAL( saturate<T>(Minf<double>()), double(Minf<T>()));

}


STF_CASE_TPL (" saturate signed_int16",  (int16_t))
{
  namespace bs = boost::simd;
  using bs::saturate;
  using bs::Valmax;
  using bs::Valmin;

  // specific values tests
  STF_ULP_EQUAL(1,           saturate<T>(1ull        ), 0);
  STF_ULP_EQUAL(2,           saturate<T>(2ull        ), 0);
  STF_ULP_EQUAL(6,           saturate<T>(6ull        ), 0);
  STF_ULP_EQUAL(24,          saturate<T>(24ull       ), 0);
  STF_ULP_EQUAL(120,         saturate<T>(120ull      ), 0);
  STF_ULP_EQUAL(720,         saturate<T>(720ull      ), 0);
  STF_ULP_EQUAL(5040,        saturate<T>(5040ull     ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(40320ull    ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(362880ull   ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(3628800ull  ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(39916800ull ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(479001600ull), 0);
  STF_ULP_EQUAL(1,           saturate<T>(1ll        ), 0);
  STF_ULP_EQUAL(2,           saturate<T>(2ll        ), 0);
  STF_ULP_EQUAL(6,           saturate<T>(6ll        ), 0);
  STF_ULP_EQUAL(24,          saturate<T>(24ll       ), 0);
  STF_ULP_EQUAL(120,         saturate<T>(120ll      ), 0);
  STF_ULP_EQUAL(720,         saturate<T>(720ll      ), 0);
  STF_ULP_EQUAL(5040,        saturate<T>(5040ll     ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(40320ll    ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(362880ll   ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(3628800ll  ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(39916800ll ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(479001600ll), 0);
  STF_ULP_EQUAL(-1,           saturate<T>(-1ll        ), 0);
  STF_ULP_EQUAL(-2,           saturate<T>(-2ll        ), 0);
  STF_ULP_EQUAL(-6,           saturate<T>(-6ll        ), 0);
  STF_ULP_EQUAL(-24,          saturate<T>(-24ll       ), 0);
  STF_ULP_EQUAL(-120,         saturate<T>(-120ll      ), 0);
  STF_ULP_EQUAL(-720,         saturate<T>(-720ll      ), 0);
  STF_ULP_EQUAL(-5040,        saturate<T>(-5040ll     ), 0);
  STF_ULP_EQUAL(Valmin<T>(),  saturate<T>(-40320ll    ), 0);
  STF_ULP_EQUAL(Valmin<T>(),  saturate<T>(-362880ll   ), 0);
  STF_ULP_EQUAL(Valmin<T>(),  saturate<T>(-3628800ll  ), 0);
  STF_ULP_EQUAL(Valmin<T>(),  saturate<T>(-39916800ll ), 0);
  STF_ULP_EQUAL(Valmin<T>(),  saturate<T>(-479001600ll), 0);
}

STF_CASE_TPL (" saturate unsigned_uint16",  (uint16_t))
{
  namespace bs = boost::simd;
  using bs::saturate;
  using bs::Valmax;
  using bs::Valmin;

  // specific values tests
  STF_ULP_EQUAL(1,           saturate<T>(1ull        ), 0);
  STF_ULP_EQUAL(2,           saturate<T>(2ull        ), 0);
  STF_ULP_EQUAL(6,           saturate<T>(6ull        ), 0);
  STF_ULP_EQUAL(24,          saturate<T>(24ull       ), 0);
  STF_ULP_EQUAL(120,         saturate<T>(120ull      ), 0);
  STF_ULP_EQUAL(720,         saturate<T>(720ull      ), 0);
  STF_ULP_EQUAL(5040,        saturate<T>(5040ull     ), 0);
  STF_ULP_EQUAL(40320,       saturate<T>(40320ull    ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(362880ull   ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(3628800ull  ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(39916800ull ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(479001600ull), 0);
  STF_ULP_EQUAL(1,           saturate<T>(1ll        ), 0);
  STF_ULP_EQUAL(2,           saturate<T>(2ll        ), 0);
  STF_ULP_EQUAL(6,           saturate<T>(6ll        ), 0);
  STF_ULP_EQUAL(24,          saturate<T>(24ll       ), 0);
  STF_ULP_EQUAL(120,         saturate<T>(120ll      ), 0);
  STF_ULP_EQUAL(720,         saturate<T>(720ll      ), 0);
  STF_ULP_EQUAL(5040,        saturate<T>(5040ll     ), 0);
  STF_ULP_EQUAL(40320,       saturate<T>(40320ll    ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(362880ll   ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(3628800ll  ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(39916800ll ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(479001600ll), 0);
}

STF_CASE_TPL (" saturate int8",  (int8_t))
{
  namespace bs = boost::simd;
  using bs::saturate;
  using bs::Valmax;
  using bs::Valmin;

  // specific values tests
  STF_ULP_EQUAL(1,           saturate<T>(1ull        ), 0);
  STF_ULP_EQUAL(2,           saturate<T>(2ull        ), 0);
  STF_ULP_EQUAL(6,           saturate<T>(6ull        ), 0);
  STF_ULP_EQUAL(24,          saturate<T>(24ull       ), 0);
  STF_ULP_EQUAL(120,         saturate<T>(120ull      ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(720ull      ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(5040ull     ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(40320ull    ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(362880ull   ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(3628800ull  ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(39916800ull ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(479001600ull), 0);
  STF_ULP_EQUAL(1,           saturate<T>(1ll        ), 0);
  STF_ULP_EQUAL(2,           saturate<T>(2ll        ), 0);
  STF_ULP_EQUAL(6,           saturate<T>(6ll        ), 0);
  STF_ULP_EQUAL(24,          saturate<T>(24ll       ), 0);
  STF_ULP_EQUAL(120,         saturate<T>(120ll      ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(720ll      ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(5040ll     ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(40320ll    ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(362880ll   ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(3628800ll  ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(39916800ll ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(479001600ll), 0);
  STF_ULP_EQUAL(-1,           saturate<T>(-1ll        ), 0);
  STF_ULP_EQUAL(-2,           saturate<T>(-2ll        ), 0);
  STF_ULP_EQUAL(-6,           saturate<T>(-6ll        ), 0);
  STF_ULP_EQUAL(-24,          saturate<T>(-24ll       ), 0);
  STF_ULP_EQUAL(-120,         saturate<T>(-120ll      ), 0);
  STF_ULP_EQUAL(Valmin<T>(),  saturate<T>(-720ll      ), 0);
  STF_ULP_EQUAL(Valmin<T>(),  saturate<T>(-5040ll     ), 0);
  STF_ULP_EQUAL(Valmin<T>(),  saturate<T>(-40320ll    ), 0);
  STF_ULP_EQUAL(Valmin<T>(),  saturate<T>(-362880ll   ), 0);
  STF_ULP_EQUAL(Valmin<T>(),  saturate<T>(-3628800ll  ), 0);
  STF_ULP_EQUAL(Valmin<T>(),  saturate<T>(-39916800ll ), 0);
  STF_ULP_EQUAL(Valmin<T>(),  saturate<T>(-479001600ll), 0);
}

STF_CASE_TPL (" saturate unsigned_uint8",  (uint8_t))
{
  namespace bs = boost::simd;
  using bs::saturate;
  using bs::Valmax;
  using bs::Valmin;

  // specific values tests
  STF_ULP_EQUAL(1,           saturate<T>(1ull        ), 0);
  STF_ULP_EQUAL(2,           saturate<T>(2ull        ), 0);
  STF_ULP_EQUAL(6,           saturate<T>(6ull        ), 0);
  STF_ULP_EQUAL(24,          saturate<T>(24ull       ), 0);
  STF_ULP_EQUAL(120,         saturate<T>(120ull      ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(720ull      ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(5040ull     ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(40320ull    ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(362880ull   ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(3628800ull  ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(39916800ull ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(479001600ull), 0);
  STF_ULP_EQUAL(1,           saturate<T>(1ll        ), 0);
  STF_ULP_EQUAL(2,           saturate<T>(2ll        ), 0);
  STF_ULP_EQUAL(6,           saturate<T>(6ll        ), 0);
  STF_ULP_EQUAL(24,          saturate<T>(24ll       ), 0);
  STF_ULP_EQUAL(120,         saturate<T>(120ll      ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(720ll      ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(5040ll     ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(40320ll    ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(362880ll   ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(3628800ll  ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(39916800ll ), 0);
  STF_ULP_EQUAL(Valmax<T>(), saturate<T>(479001600ll), 0);
  STF_ULP_EQUAL(0, saturate<T>(-1ll        ), 0);
  STF_ULP_EQUAL(0, saturate<T>(-2ll        ), 0);
  STF_ULP_EQUAL(0, saturate<T>(-6ll        ), 0);
  STF_ULP_EQUAL(0, saturate<T>(-24ll       ), 0);
  STF_ULP_EQUAL(0, saturate<T>(-120ll      ), 0);
  STF_ULP_EQUAL(0, saturate<T>(-720ll      ), 0);
  STF_ULP_EQUAL(0, saturate<T>(-5040ll     ), 0);
  STF_ULP_EQUAL(0, saturate<T>(-40320ll    ), 0);
  STF_ULP_EQUAL(0, saturate<T>(-362880ll   ), 0);
  STF_ULP_EQUAL(0, saturate<T>(-3628800ll  ), 0);
  STF_ULP_EQUAL(0, saturate<T>(-39916800ll ), 0);
  STF_ULP_EQUAL(0, saturate<T>(-479001600ll), 0);
}
