//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/true.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check true behavior with logical target", STF_NUMERIC_TYPES )
{
  using boost::simd::as;
  using boost::simd::logical;
  using boost::simd::pack;
  using boost::simd::True;

  STF_TYPE_IS(decltype(True<pack<logical<T>>>()), pack<logical<T>> );

  pack<logical<T>> ref;
  for(auto e : ref) e = true;

  STF_ALL_EQUAL( True<pack<logical<T>>>(), ref);
}

STF_CASE_TPL( "Check true behavior with arithmetic target", STF_NUMERIC_TYPES )
{
  using boost::simd::as;
  using boost::simd::logical;
  using boost::simd::pack;
  using boost::simd::True;

  STF_TYPE_IS(decltype(True<pack<T>>()), pack<logical<T>> );

  pack<logical<T>> ref;
  for(auto e : ref) e = true;

  STF_ALL_EQUAL( True<pack<T>>(), ref);
}
