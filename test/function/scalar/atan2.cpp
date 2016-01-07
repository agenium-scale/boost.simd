//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/atan2.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/threepio_4.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/options.hpp>

STF_CASE_TPL (" atan2",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::atan2;

  using r_t = decltype(atan2(T(), T()));

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(atan2(bs::Inf<T>(),bs::One<T>()), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<T>(),bs::Mone<T>()), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::One<T>()), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::Mone<T>()), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::Minf<T>()), bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Minf<T>()), -bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::Inf<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Inf<T>()), -bs::Zero<r_t>(), 0.5);
  STF_EXPECT(bs::is_negative(atan2(bs::Mone<T>(), bs::Inf<T>())));
  STF_EXPECT(bs::is_positive(atan2(bs::One<T>(), bs::Inf<T>())));
  STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::Minf<T>()), -T(3)*bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<T>(),bs::Minf<T>()), T(3)*bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::Inf<T>()), -bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<T>(),bs::Inf<T>()), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<T>(), bs::Inf<T>()), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<T>(),bs::One<T>()), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<T>(), bs::Minf<T>()), -bs::Threepio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::One<T>()), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Nan<T>(), bs::Zero<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Zero<T>(), bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(),bs::Inf<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(),bs::Minf<T>()), bs::Pi<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(atan2(bs::Half<T>(), bs::Half<T>()), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mhalf<T>(), bs::Mhalf<T>()), -bs::Threepio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Mone<T>()), -bs::Threepio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::One<T>()), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mzero<T>(), bs::Mzero<T>()), -bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mzero<T>(), bs::Mone<T>()), -bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Zero<T>(), bs::Mzero<T>()), bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Zero<T>(), bs::Mone<T>()), bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Mzero<T>()), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Zero<T>()), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::Mzero<T>()), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::Zero<T>()), bs::Pio_2<r_t>(), 0.5);

}

STF_CASE_TPL (" atan2 fast",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::atan2;

  using r_t = decltype(atan2(T(), T()));
  using bs::fast_;
  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::atan2(bs::Inf<T>(),bs::One<T>(), bs::fast_), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<T>(),bs::Mone<T>(), bs::fast_), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::One<T>(), bs::fast_), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::Mone<T>(), bs::fast_), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::Minf<T>(), fast_), bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Minf<T>(), fast_), -bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::Inf<T>(), fast_), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Inf<T>(), fast_), -bs::Zero<r_t>(), 0.5);
  STF_EXPECT(bs::is_negative(atan2(bs::Mone<T>(), bs::Inf<T>(), fast_)));
  STF_EXPECT(bs::is_positive(atan2(bs::One<T>(), bs::Inf<T>(), fast_)));

  STF_ULP_EQUAL(atan2(bs::Inf<T>(),bs::One<T>(), fast_), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::One<T>(), fast_), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Nan<T>(), bs::Nan<T>(), fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Nan<T>(), bs::Zero<T>(), fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Zero<T>(), bs::Nan<T>(), fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(),bs::Inf<T>(), fast_), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(),bs::Minf<T>(), fast_), bs::Pi<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(atan2(bs::Half<T>(), bs::Half<T>(), fast_), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mhalf<T>(), bs::Mhalf<T>(), fast_), -bs::Threepio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Mone<T>(), fast_), -bs::Threepio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::One<T>(), fast_), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mzero<T>(), bs::Mone<T>(), fast_), -bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Zero<T>(), bs::Mone<T>(), fast_), bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Mzero<T>(), fast_), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Zero<T>(), fast_), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::Mzero<T>(), fast_), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::Zero<T>(), fast_), bs::Pio_2<r_t>(), 0.5);
  //result non conform to the standard
 STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::Minf<T>(), fast_), bs::Nan<r_t>(), 0.5);
 STF_ULP_EQUAL(atan2(bs::Inf<T>(),bs::Minf<T>(), fast_), bs::Nan<r_t>(), 0.5);
 STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::Inf<T>(), fast_), bs::Nan<r_t>(), 0.5);
 STF_ULP_EQUAL(atan2(bs::Inf<T>(),bs::Inf<T>(), fast_), bs::Nan<r_t>(), 0.5);
 STF_ULP_EQUAL(atan2(bs::Minf<T>(), bs::Minf<T>(), fast_), bs::Nan<r_t>(), 0.5);
 STF_ULP_EQUAL(atan2(bs::Zero<T>(), bs::Zero<T>(), fast_), bs::Nan<r_t>(), 0.5);
 STF_ULP_EQUAL(atan2(bs::Mzero<T>(), bs::Mzero<T>(), fast_), bs::Nan<r_t>(), 0.5);
 STF_ULP_EQUAL(atan2(bs::Zero<T>(), bs::Mzero<T>(), fast_), bs::Nan<r_t>(), 0.5);


}

STF_CASE_TPL (" atan2 std",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::atan2;

  using r_t = decltype(atan2(T(), T()));

  // return type conformity test
 STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(atan2(bs::Inf<T>(),bs::One<T>(), bs::std_), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<T>(),bs::Mone<T>(), bs::std_), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::One<T>(), bs::std_), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::Mone<T>(), bs::std_), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::Minf<T>(), bs::std_), bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Minf<T>(), bs::std_), -bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::Inf<T>(), bs::std_), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Inf<T>(), bs::std_), -bs::Zero<r_t>(), 0.5);
  STF_EXPECT(bs::is_negative(atan2(bs::Mone<T>(), bs::Inf<T>(), bs::std_)));
  STF_EXPECT(bs::is_positive(atan2(bs::One<T>(), bs::Inf<T>(), bs::std_)));
  STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::Minf<T>(), bs::std_), -T(3)*bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<T>(),bs::Minf<T>(), bs::std_), T(3)*bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::Inf<T>(), bs::std_), -bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<T>(),bs::Inf<T>(), bs::std_), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<T>(), bs::Inf<T>(), bs::std_), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Inf<T>(),bs::One<T>(), bs::std_), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<T>(), bs::Minf<T>(), bs::std_), -bs::Threepio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Minf<T>(),bs::One<T>(), bs::std_), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Nan<T>(), bs::Nan<T>(), bs::std_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Nan<T>(), bs::Zero<T>(), bs::std_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Zero<T>(), bs::Nan<T>(), bs::std_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(),bs::Inf<T>(), bs::std_), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(),bs::Minf<T>(), bs::std_), bs::Pi<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(atan2(bs::Half<T>(), bs::Half<T>(), bs::std_), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mhalf<T>(), bs::Mhalf<T>(), bs::std_), -bs::Threepio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Mone<T>(), bs::std_), -bs::Threepio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::One<T>(), bs::std_), bs::Pio_4<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Zero<T>(), bs::Zero<T>(), bs::std_), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mzero<T>(), bs::Mzero<T>(), bs::std_), -bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mzero<T>(), bs::Mone<T>(), bs::std_), -bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Zero<T>(), bs::Mzero<T>(), bs::std_), bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Zero<T>(), bs::Mone<T>(), bs::std_), bs::Pi<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Mzero<T>(), bs::std_), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::Mone<T>(), bs::Zero<T>(), bs::std_), -bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::Mzero<T>(), bs::std_), bs::Pio_2<r_t>(), 0.5);
  STF_ULP_EQUAL(atan2(bs::One<T>(), bs::Zero<T>(), bs::std_), bs::Pio_2<r_t>(), 0.5);

}
