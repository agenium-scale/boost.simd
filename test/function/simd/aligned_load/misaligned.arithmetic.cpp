//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/simd/aligned_load.hpp>
#include <boost/simd/pack.hpp>
#include <boost/align/aligned_alloc.hpp>
#include <simd_test.hpp>

namespace ba = boost::alignment;
namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test_periodic(Env& runtime)
{
  using p_t = bs::pack<T,N>;

  T* data = static_cast<T*>(ba::aligned_alloc(p_t::alignment, (sizeof(T)) * N * 3));
  std::array<T,N> ref0, refN, refmN;

  for(std::size_t i = 0;i < 3*N        ; ++i) data[i] = T(i+1);
  for(std::size_t i = 0;i < ref0.size() ; ++i)
  {
    ref0[i]  = data[N+i];
    refN[i]  = data[2*N+i];
    refmN[i] = data[i];
  }

  static const std::ptrdiff_t O = N;

  p_t p0  = bs::aligned_load<bs::pack<T,N>, 0>(&data[N]  );
  p_t pN  = bs::aligned_load<bs::pack<T,N>, O>(&data[N]+O);
  p_t pmN = bs::aligned_load<bs::pack<T,N>,-O>(&data[N]-O);

  STF_ALL_EQUAL( p0 , ref0  );
  STF_ALL_EQUAL( pN , refN  );
  STF_ALL_EQUAL( pmN, refmN );
}

STF_CASE_TPL( "Check aligned_load behavior with periodic misalignment", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test_periodic<T, N>(runtime);
  test_periodic<T, N/2>(runtime);
  test_periodic<T, N*2>(runtime);
}

template <typename T, std::size_t N, typename Env>
void test_aperiodic(Env& runtime)
{
  using p_t = bs::pack<T,N>;

  T* data = static_cast<T*>(ba::aligned_alloc(p_t::alignment, (sizeof(T)) * N * 3));
  std::array<T,N> ref1, refm2, ref3;

  for(std::size_t i = 0;i < 3*N         ; ++i) data[i] = T(i+1);
  for(std::size_t i = 0;i < ref1.size() ; ++i)
  {
    ref1[i]  = data[N+i+1];
    refm2[i]  = data[N+i-2];
    ref3[i] = data[N+i+3];
  }

  p_t p1  = bs::aligned_load<bs::pack<T,N>,+1>(&data[N]+1);
  p_t pm2 = bs::aligned_load<bs::pack<T,N>,-2>(&data[N]-2);
  p_t p3  = bs::aligned_load<bs::pack<T,N>,+3>(&data[N]+3);

  STF_ALL_EQUAL( p1 , ref1  );
  STF_ALL_EQUAL( pm2, refm2 );
  STF_ALL_EQUAL( p3 , ref3  );
}

STF_CASE_TPL( "Check aligned_load behavior with aperiodic misalignment", STF_NUMERIC_TYPES )
{
  static const std::size_t N = bs::pack<T>::static_size;

  test_aperiodic<T, N>(runtime);
  test_aperiodic<T, N/2>(runtime);
  test_aperiodic<T, N*2>(runtime);
}
