//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/cast.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/function/enumerate.hpp>

namespace bs = boost::simd;
using bs::pack;

template <typename T, typename Env>
void test_type(Env& $)
{
  static const std::size_t N = T::static_size;
  STF_EXPR_IS(bs::cast<std::int8_t  >(T()), (bs::pack<std::int8_t,   N>));
  STF_EXPR_IS(bs::cast<std::int16_t >(T()), (bs::pack<std::int16_t,  N>));
  STF_EXPR_IS(bs::cast<std::int32_t >(T()), (bs::pack<std::int32_t,  N>));
  STF_EXPR_IS(bs::cast<std::int64_t >(T()), (bs::pack<std::int64_t,  N>));
  STF_EXPR_IS(bs::cast<std::uint8_t >(T()), (bs::pack<std::uint8_t,  N>));
  STF_EXPR_IS(bs::cast<std::uint16_t>(T()), (bs::pack<std::uint16_t, N>));
  STF_EXPR_IS(bs::cast<std::uint32_t>(T()), (bs::pack<std::uint32_t, N>));
  STF_EXPR_IS(bs::cast<std::uint64_t>(T()), (bs::pack<std::uint64_t, N>));
  STF_EXPR_IS(bs::cast<float        >(T()), (bs::pack<float        , N>));
  STF_EXPR_IS(bs::cast<double       >(T()), (bs::pack<double       , N>));
}


STF_CASE_TPL( "Check cast return type", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test_type<bs::pack<T, N>>($);
  test_type<bs::pack<T, N/2>>($);
  test_type<bs::pack<T, N*2>>($);
}


