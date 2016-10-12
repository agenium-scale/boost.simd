//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/ulpdist.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" ulpdist real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ulpdist;


  STF_EXPR_IS( ulpdist(T(), T()), T);

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(ulpdist(bs::Inf<T>(), bs::Inf<T>()), bs::Zero<T>());
  STF_EQUAL(ulpdist(bs::Minf<T>(), bs::Minf<T>()), bs::Zero<T>());
  STF_EQUAL(ulpdist(bs::Nan<T>(), bs::Nan<T>()), bs::Zero<T>());
#endif

  STF_EQUAL(ulpdist(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(ulpdist(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(ulpdist(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());

  STF_EQUAL( ulpdist(bs::One<T>(), bs::One<T>()+bs::Eps<T>())
                , T(0.5)
                );

  STF_EQUAL( ulpdist(bs::One<T>(), bs::One<T>()-bs::Eps<T>())
                , T(0.5)
                );

  STF_EQUAL( ulpdist(bs::One<T>(), bs::One<T>()-bs::Eps<T>()/2)
                , T(0.25)
                );
}

STF_CASE_TPL (" ulpdist signed_integral",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ulpdist;


  STF_EXPR_IS( ulpdist(T(), T()), T);

  STF_EQUAL(ulpdist(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(ulpdist(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(ulpdist(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());

  STF_EQUAL( ulpdist(bs::Zero<T>(), bs::Valmin<T>())
                , bs::Valmax<T>()
                );

  STF_EQUAL( ulpdist(bs::Valmin<T>(), bs::Zero<T>())
                , bs::Valmax<T>()
                );

  STF_EQUAL( ulpdist(bs::Zero<T>(), bs::Valmax<T>())
                , bs::Valmax<T>()
                );

  STF_EQUAL( ulpdist(bs::Valmax<T>(), bs::Zero<T>())
                , bs::Valmax<T>()
                );

  STF_EQUAL( ulpdist(bs::Valmin<T>(), bs::Valmax<T>())
                , bs::Valmax<T>()
                );
}

STF_CASE_TPL (" ulpdist unsigned_integral",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ulpdist;


  STF_EXPR_IS( ulpdist(T(), T()), T);

  STF_EQUAL(ulpdist(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(ulpdist(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(ulpdist(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());

  STF_EQUAL( ulpdist(bs::Zero<T>(), bs::Valmin<T>())
                , bs::Zero<T>()
                );

  STF_EQUAL( ulpdist(bs::Valmin<T>(), bs::Zero<T>())
                , bs::Zero<T>()
                );

  STF_EQUAL( ulpdist(bs::Zero<T>(), bs::Valmax<T>())
                , bs::Valmax<T>()
                );

  STF_EQUAL( ulpdist(bs::Valmax<T>(), bs::Zero<T>())
                , bs::Valmax<T>()
                );

  STF_EQUAL( ulpdist(bs::Valmin<T>(), bs::Valmax<T>())
                , bs::Valmax<T>()
                );
}


