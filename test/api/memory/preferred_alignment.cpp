//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/memory/preferred_alignment.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Check preferred_alignment on Vectorizable types", STF_NUMERIC_TYPES )
{
  static const std::size_t N = pack<T>::static_size;
  STF_EQUAL( (preferred_alignment<T>::value    ), std::size_t(pack<T,N  >::alignment) );
  STF_EQUAL( (preferred_alignment<T,N/2>::value), std::size_t(pack<T,N/2>::alignment) );
  STF_EQUAL( (preferred_alignment<T,N*2>::value), std::size_t(pack<T,N*2>::alignment) );
}

STF_CASE_TPL( "Check preferred_alignment on Vectorized types", STF_NUMERIC_TYPES )
{
  static const std::size_t N = pack<T>::static_size;
  STF_EQUAL( (preferred_alignment<pack<T>    >::value), std::size_t(pack<T    >::alignment) );
  STF_EQUAL( (preferred_alignment<pack<T>,N/2>::value), std::size_t(pack<T,N/2>::alignment) );
  STF_EQUAL( (preferred_alignment<pack<T>,N*2>::value), std::size_t(pack<T,N*2>::alignment) );
}

struct foo { pack<float> x; };

STF_CASE( "Check preferred_alignment on non-Vectorizable types" )
{
  static const std::size_t N = pack<float>::static_size;
  STF_EQUAL( (preferred_alignment<foo    >::value), alignof(foo) );
  STF_EQUAL( (preferred_alignment<foo,N/2>::value), alignof(foo) );
  STF_EQUAL( (preferred_alignment<foo,N*2>::value), alignof(foo) );
}

template<typename T> struct bar { T x; };

namespace boost { namespace dispatch { namespace ext
{
  template<typename T> struct value_of<bar<T>> { using type = T; };
} } }

STF_CASE( "Check preferred_alignment on adaptable non-Vectorizable types" )
{
  static const std::size_t N = pack<float>::static_size;

  STF_EQUAL( (preferred_alignment<bar<float>    >::value)  , std::size_t(pack<float>::alignment));
  STF_EQUAL( (preferred_alignment<bar<pack<float>>>::value), std::size_t(pack<float>::alignment));
  STF_EQUAL( (preferred_alignment<bar<float>,N/2>::value)  , std::size_t(pack<float,N/2>::alignment));
  STF_EQUAL( (preferred_alignment<bar<float>,N*2>::value)  , std::size_t(pack<float,N*2>::alignment));
}
