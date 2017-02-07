//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/group.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
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
  using p_t = bs::pack<T, N>;
  using g_t = bd::downgrade_t<p_t>;
  using type = typename g_t::value_type;

  T a1[N], a2[N];
  type c[2*N];
  for(size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i*2) : T(3+i);
    a2[i] = (i%2) ? T(7+i) : T(i);
    c[i]   = std::is_integral<T>::value ? bs::saturate<type>(a1[i]) : a1[i];
    c[i+N] = std::is_integral<T>::value ? bs::saturate<type>(a2[i]) : a2[i];
  }

  // Spice up with value that will be narrowed
  a1[0] = bs::Valmax<T>();
  a2[0] = bs::Valmin<T>();
  c[0]  = std::is_integral<T>::value ? bs::saturate<type>(a1[0]) : a1[0];
  c[N]  = std::is_integral<T>::value ? bs::saturate<type>(a2[0]) : a2[0];

  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  g_t cc (&c[0], &c[0]+2*N);

  STF_EQUAL(bs::saturated_(bs::group)(aa1,aa2), cc);
}

STF_CASE_TPL("Check group on pack", STF_NUMERIC_TYPES)
{;
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N  >(runtime, bd::is_downgradable< bs::pack<T,N  > >{});
  test<T, N/2>(runtime, bd::is_downgradable< bs::pack<T,N/2> >{});
  test<T, N*2>(runtime, bd::is_downgradable< bs::pack<T,N*2> >{});
}
