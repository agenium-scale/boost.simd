//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/goldbar.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check goldbar behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::goldbar;
  using boost::simd::Goldbar;

  STF_TYPE_IS(decltype(Goldbar<T>()), T);
  STF_EQUAL(Goldbar<T>(), T(0));
  STF_EQUAL(goldbar( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check goldbar behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::goldbar;
  using boost::simd::Goldbar;

  STF_TYPE_IS(decltype(Goldbar<T>()), T);
  STF_ULP_EQUAL(Goldbar<T>()+T(1), Goldbar<T>()*Goldbar<T>(), 1);
  STF_LESS(  Goldbar<T>(), T(1));
  auto z = goldbar( as(T{}));
  STF_ULP_EQUAL((z+T(1)),z*z, 1);
}
