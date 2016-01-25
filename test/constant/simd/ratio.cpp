//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/pack.hpp>
#include <algorithm>

#include <simd_test.hpp>

STF_CASE_TPL( "Check ratio constant behavior for packs", STF_NUMERIC_TYPES )
{
  namespace bs =  boost::simd;
  using pack_t  = bs::pack<T>;
  using hpack_t = bs::pack<T,pack_t::static_size/2>;
  using dpack_t = bs::pack<T,pack_t::static_size*2>;

  {
    auto are_correct = [](T e) { return e == bs::Ratio<T,7,21>(); };

    auto pack  = bs::Ratio<pack_t ,7,21>();
    auto hpack = bs::Ratio<hpack_t,7,21>();
    auto dpack = bs::Ratio<dpack_t,7,21>();

    STF_EXPECT(( std::all_of(pack.begin() , pack.end(), are_correct ) ));
    STF_EXPECT(( std::all_of(hpack.begin(),hpack.end(), are_correct ) ));
    STF_EXPECT(( std::all_of(dpack.begin(),dpack.end(), are_correct ) ));
  }
  {
    auto are_correct = [](T e) { return e == bs::Ratio<T,7>(); };

    auto pack  = bs::Ratio<pack_t,7>();
    auto hpack = bs::Ratio<hpack_t,7>();
    auto dpack = bs::Ratio<dpack_t,7>();

    STF_EXPECT(( std::all_of(pack.begin() , pack.end(), are_correct ) ));
    STF_EXPECT(( std::all_of(hpack.begin(),hpack.end(), are_correct ) ));
    STF_EXPECT(( std::all_of(dpack.begin(),dpack.end(), are_correct ) ));
  }
}

STF_CASE_TPL( "Check unit ratio constant behavior for packs", STF_NUMERIC_TYPES )
{
  namespace bs =  boost::simd;
  using pack_t  = bs::pack<T>;
  using hpack_t = bs::pack<T,pack_t::static_size/2>;
  using dpack_t = bs::pack<T,pack_t::static_size*2>;

  auto are_correct = [](T e) { return e == bs::Ratio<T,7>(); };

  auto pack  = bs::Ratio<pack_t ,7>();
  auto hpack = bs::Ratio<hpack_t,7>();
  auto dpack = bs::Ratio<dpack_t,7>();

  STF_EXPECT(( std::all_of(pack.begin() , pack.end(), are_correct ) ));
  STF_EXPECT(( std::all_of(hpack.begin(),hpack.end(), are_correct ) ));
  STF_EXPECT(( std::all_of(dpack.begin(),dpack.end(), are_correct ) ));
}
