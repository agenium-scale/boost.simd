//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/detail/dispatch/hierarchy_of.hpp>
#include <boost/simd/meta/abi_of.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  {
    using pack_t = boost::simd::pack<T, N>;
    using prop_t = boost::dispatch::property_of_t<pack_t>;
    using ext_t  = boost::simd::abi_of_t<T,N>;

    STF_TYPE_IS ( boost::dispatch::hierarchy_of_t<pack_t>
                , (boost::simd::pack_<prop_t, ext_t >)
                );
  }
  {
    using pack_t = boost::simd::pack<boost::simd::logical<T>, N>;
    using prop_t = boost::dispatch::property_of_t<pack_t>;
    using ext_t  = boost::simd::abi_of_t<boost::simd::logical<T>,N>;

    STF_TYPE_IS ( boost::dispatch::hierarchy_of_t<pack_t>
                , (boost::simd::pack_<prop_t, ext_t >)
                );
  }
}

STF_CASE_TPL( "Check hierarchy_of on pack" , STF_NUMERIC_TYPES )
{
  test<T,  1>(runtime);
  test<T,  2>(runtime);
  test<T,  4>(runtime);
  test<T,  8>(runtime);
  test<T, 16>(runtime);
  test<T, 32>(runtime);
}
