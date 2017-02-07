//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/simd/load.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

template <typename T, typename U, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t  = bs::pack<T,N>;
  using pi_t = bs::pack<U,N>;

  std::array<T,2*N> data;
  std::array<T,N> ref;
  std::array<U,N> idx;
  for(std::size_t i = 0;i < data.size(); ++i) data[i] = T(i);
  for(std::size_t i = 0;i < idx.size() ; ++i) idx[i]  = U(std::rand() % data.size());
  for(std::size_t i = 0;i < ref.size() ; ++i) ref[i]  = data[ static_cast<std::size_t>(idx[i]) ];

  pi_t pi = bs::load<pi_t>(&idx[0]);
  p_t  p  = bs::load<p_t>(&data[0], pi);

  STF_ALL_EQUAL( p, ref );
}

STF_CASE_TPL( "Check gather behavior with 32-bits indexes", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, std::int32_t, N>(runtime);
  test<T, std::int32_t, N/2>(runtime);
  test<T, std::int32_t, N*2>(runtime);
}

STF_CASE_TPL( "Check gather behavior with 64-bits indexes", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, std::int64_t, N>(runtime);
  test<T, std::int64_t, N/2>(runtime);
  test<T, std::int64_t, N*2>(runtime);
}
