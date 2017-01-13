//==================================================================================================
/**
  Copyright 201 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/detail/nsm.hpp>
#include <boost/simd/function/scalar/shuffle.hpp>
#include <scalar_test.hpp>

using namespace boost::simd;

STF_CASE_TPL("Check unary shuffle behavior with direct permutation", STF_NUMERIC_TYPES)
{
  STF_EQUAL( shuffle<-1>(T(4)), T(0) );
  STF_EQUAL( shuffle<0>(T(4)) , T(4) );
}

STF_CASE_TPL("Check binary shuffle behavior with direct permutation", STF_NUMERIC_TYPES)
{
  STF_EQUAL( shuffle<-1>(T(4),T(7)) , T(0) );
  STF_EQUAL( shuffle< 0>(T(4),T(7)) , T(4) );
  STF_EQUAL( shuffle< 1>(T(4),T(7)) , T(7) );
}

template<int N> struct grab_
{
  template<typename I, typename C>
  struct apply : nsm::type_traits::integral_constant<int, N>
  {};
};

STF_CASE_TPL("Check unary shuffle behavior with direct meta-permutation", STF_NUMERIC_TYPES)
{
  STF_EQUAL( shuffle<grab_<0>>(T(4)) , T(4) );
}

STF_CASE_TPL("Check binary shuffle behavior with direct meta-permutation", STF_NUMERIC_TYPES)
{
  STF_EQUAL( shuffle<grab_<0>>(T(4),T(7)) , T(4) );
  STF_EQUAL( shuffle<grab_<1>>(T(4),T(7)) , T(7) );
}

#if !defined(BOOST_NO_CONSTEXPR)
// -------------------------------------------------------------------------------------------------
// Not much variation when cardinal is equal to 1, so we just make two "permutations"

constexpr int grab0(int /*i*/, int /*c*/) { return 0; }
constexpr int grab1(int /*i*/, int /*c*/) { return 1; }

STF_CASE_TPL("Check unary shuffle behavior with constexpr-permutation", STF_NUMERIC_TYPES)
{
  STF_EQUAL( shuffle<pattern<grab0>>(T(4),T(7)) , T(4) );
  STF_EQUAL( shuffle<pattern<grab1>>(T(4),T(7)) , T(7) );
}
#endif
