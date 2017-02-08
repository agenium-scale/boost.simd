//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/split_high.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;
namespace tt = nsm::type_traits;

template<typename T, std::size_t N, typename Env>
void test( Env&, tt::false_type const& )
{}

template<typename T, std::size_t N, typename Env>
void test( Env& runtime, tt::true_type const& )
{
  using type = bd::upgrade_t<bs::logical<T>>;

  std::array<bs::logical<T>,N> data;
  for(std::size_t i=0;i<data.size();++i)  data[i] = !!(i % 3);

  std::array<type,N/2> dref;
  for(std::size_t i=0;i<dref.size();++i)  dref[i] = static_cast<type>(data[i+N/2]);

  bs::pack<bs::logical<T>,N>                 value (&data[0], &data[0]+data.size() );
  bd::upgrade_t<bs::pack<bs::logical<T>,N>>  ref   (&dref[0], &dref[0]+dref.size() );

  STF_EQUAL( bs::split_high(value), ref);
}

STF_CASE_TPL("split_high pack<T,N> into a pack<T*2,N/2>", STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T,N  >(runtime, bd::is_upgradable< bs::pack<T,N/2> >{});
  test<T,N/2>(runtime, bd::is_upgradable< bs::pack<T,N/2> >{});
  test<T,N*2>(runtime, bd::is_upgradable< bs::pack<T,N/2> >{});
}
