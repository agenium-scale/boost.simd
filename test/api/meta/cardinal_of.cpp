//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/detail/nsm.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Check cardinal_of for scalar types", STF_ALL_TYPES )
{
  STF_EQUAL( cardinal_of<T>::value        , 1ULL );
  STF_EQUAL( cardinal_of<T&&>::value      , 1ULL );
  STF_EQUAL( cardinal_of<T&>::value       , 1ULL );
  STF_EQUAL( cardinal_of<T const>::value  , 1ULL );
  STF_EQUAL( cardinal_of<T const&>::value , 1ULL );

  STF_EQUAL( cardinal_of<volatile T>::value        , 1ULL );
  STF_EQUAL( cardinal_of<volatile T&&>::value      , 1ULL );
  STF_EQUAL( cardinal_of<volatile T&>::value       , 1ULL );
  STF_EQUAL( cardinal_of<volatile T const>::value  , 1ULL );
  STF_EQUAL( cardinal_of<volatile T const&>::value , 1ULL );

  STF_EQUAL( cardinal_of_t<T>::value        , 1ULL );
  STF_EQUAL( cardinal_of_t<T&&>::value      , 1ULL );
  STF_EQUAL( cardinal_of_t<T&>::value       , 1ULL );
  STF_EQUAL( cardinal_of_t<T const>::value  , 1ULL );
  STF_EQUAL( cardinal_of_t<T const&>::value , 1ULL );

  STF_EQUAL( cardinal_of_t<volatile T>::value        , 1ULL );
  STF_EQUAL( cardinal_of_t<volatile T&&>::value      , 1ULL );
  STF_EQUAL( cardinal_of_t<volatile T&>::value       , 1ULL );
  STF_EQUAL( cardinal_of_t<volatile T const>::value  , 1ULL );
  STF_EQUAL( cardinal_of_t<volatile T const&>::value , 1ULL );

  STF_EXPR_IS( cardinal(T{}), cardinal_of_t<T> );
  STF_EQUAL( cardinal(T{}), 1ULL );
}

template<std::size_t N> using card_ = nsm::type_traits::integral_constant<std::size_t,N>;

STF_CASE_TPL( "Check cardinal_of for pack types"
            , (card_<1>)(card_<2>)(card_<4>)
              (card_<8>)(card_<16>)(card_<32>)
            )
{
  using pack_t = pack<float,T::value>;

  STF_EQUAL( cardinal_of<pack_t>::value        , T::value );
  STF_EQUAL( cardinal_of<pack_t&&>::value      , T::value );
  STF_EQUAL( cardinal_of<pack_t&>::value       , T::value );
  STF_EQUAL( cardinal_of<pack_t const>::value  , T::value );
  STF_EQUAL( cardinal_of<pack_t const&>::value , T::value );

  STF_EQUAL( cardinal_of<volatile pack_t>::value        , T::value );
  STF_EQUAL( cardinal_of<volatile pack_t&&>::value      , T::value );
  STF_EQUAL( cardinal_of<volatile pack_t&>::value       , T::value );
  STF_EQUAL( cardinal_of<volatile pack_t const>::value  , T::value );
  STF_EQUAL( cardinal_of<volatile pack_t const&>::value , T::value );

  STF_EQUAL( cardinal_of_t<pack_t>::value        , T::value );
  STF_EQUAL( cardinal_of_t<pack_t&&>::value      , T::value );
  STF_EQUAL( cardinal_of_t<pack_t&>::value       , T::value );
  STF_EQUAL( cardinal_of_t<pack_t const>::value  , T::value );
  STF_EQUAL( cardinal_of_t<pack_t const&>::value , T::value );

  STF_EQUAL( cardinal_of_t<volatile pack_t>::value        , T::value );
  STF_EQUAL( cardinal_of_t<volatile pack_t&&>::value      , T::value );
  STF_EQUAL( cardinal_of_t<volatile pack_t&>::value       , T::value );
  STF_EQUAL( cardinal_of_t<volatile pack_t const>::value  , T::value );
  STF_EQUAL( cardinal_of_t<volatile pack_t const&>::value , T::value );

  STF_EXPR_IS( cardinal(pack_t{}), cardinal_of_t<pack_t> );
  STF_EQUAL( cardinal(pack_t{}), T::value );
}

