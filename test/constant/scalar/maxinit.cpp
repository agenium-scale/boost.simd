//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/maxinit.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check maxinit behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::maxinit;
  using boost::simd::Maxinit;
  using boost::simd::Valmin;

  STF_TYPE_IS(decltype(Maxinit<T>()), T);
  STF_EQUAL(Maxinit<T>(), Valmin<T>());
  STF_EQUAL(maxinit( as(T{}) ),Valmin<T>());
}



STF_CASE_TPL( "Check maxinit behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::maxinit;
  using boost::simd::Maxinit;
  using boost::simd::Minf;

  STF_TYPE_IS(decltype(Maxinit<T>()), T);
  STF_EQUAL(Maxinit<T>(), Minf<T>());
  STF_EQUAL(maxinit( as(T{}) ),Minf<T>());
}


