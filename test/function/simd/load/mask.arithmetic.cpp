//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/load.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t  = bs::pack<T,N>;
  using pm_t = bs::pack<bs::logical<T>,N>;

  std::array<T,N> data;
  std::array<T,N> ref, refv;
  std::array<bs::logical<T>,N> msk;
  for(std::size_t i = 0;i < data.size(); ++i) data[i] = T(i);
  for(std::size_t i = 0;i < msk.size() ; ++i) msk[i]  = i%3 ? true : false;
  for(std::size_t i = 0;i < ref.size() ; ++i) ref[i]  = msk[i] ? data[i] : T(0);
  for(std::size_t i = 0;i < refv.size() ; ++i) refv[i]  = msk[i] ? data[i] : T(7);

  auto pm = bs::load<pm_t>(&msk[0]);

  STF_ALL_EQUAL( bs::load<p_t>( bs::mask(&data[0], pm    ) ), ref   );
  STF_ALL_EQUAL( bs::load<p_t>( bs::mask(&data[0], pm, 7 ) ), refv  );

  STF_ALL_EQUAL( bs::load<p_t>( bs::mask(&data[0], true    ) ), bs::load<p_t>(&data[0]) );
  STF_ALL_EQUAL( bs::load<p_t>( bs::mask(&data[0], true, 7 ) ), bs::load<p_t>(&data[0]) );

  STF_ALL_EQUAL( bs::load<p_t>( bs::mask(&data[0], false   ) ), bs::Zero<p_t>() );
  STF_ALL_EQUAL( bs::load<p_t>( bs::mask(&data[0], false, 7) ), p_t(7)          );

  // This should not segfault as masking prevent memory access
  STF_ALL_EQUAL( bs::load<p_t>( bs::mask((T*)(0), false   ) ), bs::Zero<p_t>() );
  STF_ALL_EQUAL( bs::load<p_t>( bs::mask((T*)(0), false, 7) ), p_t(7)          );
}

STF_CASE_TPL( "Check masked load behavior", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
