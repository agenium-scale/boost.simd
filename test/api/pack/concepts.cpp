//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  {
    using pack_t = boost::simd::pack<T, N>;
    pack_t p;

    STF_EXPECT_NOT(p.empty());

    STF_EQUAL(p.size(), N);
    STF_EQUAL(p.max_size(), N);
    STF_EQUAL(typename pack_t::size_type{pack_t::static_size}, N);

    STF_TYPE_IS(typename pack_t::value_type, T);
  }

  {
    using pack_t = boost::simd::pack<boost::simd::logical<T>, N>;
    pack_t p;

    STF_EXPECT_NOT(p.empty());

    STF_EQUAL(p.size(), N);
    STF_EQUAL(p.max_size(), N);
    STF_EQUAL(typename pack_t::size_type{pack_t::static_size}, N);

    STF_TYPE_IS(typename pack_t::value_type, boost::simd::logical<T>);
  }
}

STF_CASE_TPL( "Check pack's concepts" , STF_NUMERIC_TYPES)
{
  test<T,  1>(runtime);
  test<T,  2>(runtime);
  test<T,  4>(runtime);
  test<T,  8>(runtime);
  test<T, 16>(runtime);
  test<T, 32>(runtime);
}
