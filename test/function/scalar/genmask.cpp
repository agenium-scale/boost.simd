//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/logical.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL ("Check genmask generic behavior",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::genmask;

  STF_TYPE_IS(decltype(bs::genmask(T())),T);
  STF_IEEE_EQUAL(genmask(T(42)), bs::Allbits<T>());
  STF_EQUAL(genmask(T(0)) , T(0));
}

STF_CASE_TPL ("Check genmask logical behavior",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::genmask;

  STF_TYPE_IS(decltype(bs::genmask(bs::logical<T>())),T);
  STF_IEEE_EQUAL(genmask(bs::logical<T>(true)), bs::Allbits<T>());
  STF_EQUAL(genmask(bs::logical<T>(false)) , T(0));
}

STF_CASE("Check genmask bool behavior")
{
  namespace bs = boost::simd;
  using bs::genmask;

  STF_TYPE_IS(decltype(bs::genmask(true)),bool);
  STF_EQUAL(genmask(true) , true  );
  STF_EQUAL(genmask(false), false );
}

STF_CASE_TPL ("Check genmask behavior when re-targeted",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::genmask;

  STF_TYPE_IS(decltype(bs::genmask<char>(T())),char);

  STF_EQUAL(genmask<char>(T(42)), bs::Allbits<char>());
  STF_EQUAL(genmask<char>(T(0)) , char(0));
}


STF_CASE_TPL ("Check genmask logical behavior when re-targeted",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::genmask;

  STF_TYPE_IS(decltype(bs::genmask<char>(bs::logical<T>())),char);

  STF_IEEE_EQUAL(genmask<char>(bs::logical<T>(true)), bs::Allbits<char>());
  STF_EQUAL(genmask<char>(bs::logical<T>(false)) , char(0));
}

#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>

STF_CASE_TPL ("Check genmask behavior on IEEE754 special values",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::genmask;

  STF_IEEE_EQUAL(genmask(bs::Inf<T>())  , bs::Allbits<T>());
  STF_IEEE_EQUAL(genmask(bs::Minf<T>()) , bs::Allbits<T>());
  STF_IEEE_EQUAL(genmask(bs::Nan<T>())  , bs::Allbits<T>());
}
#endif
