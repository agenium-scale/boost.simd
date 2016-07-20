//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/aligned_load.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/align/aligned_alloc.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace ba = boost::alignment;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_t  = bs::pack<T,N>;
  using pm_t = bs::pack<bs::logical<T>,N>;

  T* data = static_cast<T*>(ba::aligned_alloc(p_t::alignment, (sizeof(T)) * N));

  std::array<T,N> ref, refv;
  std::array<bs::logical<T>,N> msk;

  for(std::size_t i = 0;i < N; ++i) data[i] = T(i);
  for(std::size_t i = 0;i < msk.size() ; ++i) msk[i]  = i%3 ? true : false;
  for(std::size_t i = 0;i < ref.size() ; ++i) ref[i]  = msk[i] ? data[i] : T(0);
  for(std::size_t i = 0;i < refv.size() ; ++i) refv[i]  = msk[i] ? data[i] : T(7);

  auto pm = bs::aligned_load<pm_t>(&msk[0]);

  STF_ALL_EQUAL( bs::aligned_load<p_t>( bs::mask(&data[0]   , pm ) ), ref   );
  STF_ALL_EQUAL( bs::aligned_load<p_t>( bs::mask(&data[0], 7, pm ) ), refv  );

  STF_ALL_EQUAL( bs::aligned_load<p_t>( bs::mask(&data[0]   , true ) ), bs::aligned_load<p_t>(&data[0]) );
  STF_ALL_EQUAL( bs::aligned_load<p_t>( bs::mask(&data[0], 7, true ) ), bs::aligned_load<p_t>(&data[0]) );

  STF_ALL_EQUAL( bs::aligned_load<p_t>( bs::mask(&data[0]   , false) ), bs::Zero<p_t>() );
  STF_ALL_EQUAL( bs::aligned_load<p_t>( bs::mask(&data[0], 7, false) ), p_t(7)          );

  // This should not segfault as masking prevent memory access
  STF_ALL_EQUAL( bs::aligned_load<p_t>( bs::mask((T*)(0) , 7, false) ), p_t(7)          );
  STF_ALL_EQUAL( bs::aligned_load<p_t>( bs::mask((T*)(0)    , false) ), bs::Zero<p_t>() );
}

STF_CASE_TPL( "Check masked aligned_load behavior", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

