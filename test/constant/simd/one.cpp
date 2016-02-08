//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/one.hpp>
#include <boost/simd/pack.hpp>
#include <algorithm>

#include <simd_test.hpp>

STF_CASE_TPL( "Check one behavior"
            , (double)(float)
              (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t )(std::int16_t )(std::int32_t )(std::int64_t )
            )
{
  using pack_t  = boost::simd::pack<T>;
  using hpack_t = boost::simd::pack<T,pack_t::static_size/2>;
  using dpack_t = boost::simd::pack<T,pack_t::static_size*2>;;

  auto are_correct = [](T e) { return e == T{1}; };

  auto pack  = boost::simd::One<pack_t>();
  auto hpack = boost::simd::One<pack_t>();
  auto dpack = boost::simd::One<pack_t>();

  STF_EXPECT(( std::all_of(pack.begin() , pack.end(), are_correct ) ));
  STF_EXPECT(( std::all_of(hpack.begin(),hpack.end(), are_correct ) ));
  STF_EXPECT(( std::all_of(dpack.begin(),dpack.end(), are_correct ) ));
}
