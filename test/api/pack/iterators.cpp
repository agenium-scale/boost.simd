//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <numeric>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  std::vector<T> v(N);
  std::iota(v.begin(), v.end(), T(1));

  using pack_t = boost::simd::pack<T, N>;
  pack_t p(v.begin(), v.end());

  // begin/end (write)
  {
    pack_t p2(v.begin(), v.end());
    {
      auto p2_it = p2.begin();
      for (; p2_it != p.end(); ++p2_it) {
        *p2_it += 2;
      }

      auto p_it = p.begin();
      for (; p_it != p.end() && p2_it != p2.end(); ++p_it, ++p2_it) {
        STF_EQUAL(*p_it + 2, *p2_it);
      }
    }
  }
  // begin/end (read-only)
  {
    auto v_it = v.begin();
    auto p_it = p.begin();
    for (; p_it != p.end() && v_it != v.end(); ++p_it, ++v_it) {
      STF_EQUAL(*p_it, *v_it);
    }
  }
  // cbegin/cend
  {
    auto v_it = v.cbegin();
    auto p_it = p.cbegin();
    for (; p_it != p.cend() && v_it != v.cend(); ++p_it, ++v_it) {
      STF_EQUAL(*p_it, *v_it);
    }
  }
  // rbegin/rend
  {
    auto v_it = v.rbegin();
    auto p_it = p.rbegin();
    for (; p_it != p.rend() && v_it != v.rend(); ++p_it, ++v_it) {
      STF_EQUAL(*p_it, *v_it);
    }
  }
  // crbegin/crend
  {
    auto v_it = v.crbegin();
    auto p_it = p.crbegin();
    for (; p_it != p.crend() && v_it != v.crend(); ++p_it, ++v_it) {
      STF_EQUAL(*p_it, *v_it);
    }
  }
}

STF_CASE_TPL( "Check pack's iterators" , STF_NUMERIC_TYPES)
{
  test<T,  1>(runtime);
  test<T,  2>(runtime);
  test<T,  4>(runtime);
  test<T,  8>(runtime);
  test<T, 16>(runtime);
  test<T, 32>(runtime);
}

template <typename T, std::size_t N, typename Env>
void ltest(Env& runtime)
{
  std::vector<boost::simd::logical<T>> v(N);
  std::fill(v.begin(), v.end(), true);

  using pack_t = boost::simd::pack<boost::simd::logical<T>, N>;
  pack_t p(v.begin(), v.end());

  // begin/end (write)
  {
    pack_t p2(v.begin(), v.end());
    {
      auto p2_it = p2.begin();
      for (; p2_it != p.end(); ++p2_it) {
        *p2_it += 2;
      }

      auto p_it = p.begin();
      for (; p_it != p.end() && p2_it != p2.end(); ++p_it, ++p2_it) {
        STF_EQUAL(*p_it + 2, *p2_it);
      }
    }
  }
  // begin/end (read-only)
  {
    auto v_it = v.begin();
    auto p_it = p.begin();
    for (; p_it != p.end() && v_it != v.end(); ++p_it, ++v_it) {
      STF_EQUAL(*p_it, *v_it);
    }
  }
  // cbegin/cend
  {
    auto v_it = v.cbegin();
    auto p_it = p.cbegin();
    for (; p_it != p.cend() && v_it != v.cend(); ++p_it, ++v_it) {
      STF_EQUAL(*p_it, *v_it);
    }
  }
  // rbegin/rend
  {
    auto v_it = v.rbegin();
    auto p_it = p.rbegin();
    for (; p_it != p.rend() && v_it != v.rend(); ++p_it, ++v_it) {
      STF_EQUAL(*p_it, *v_it);
    }
  }
  // crbegin/crend
  {
    auto v_it = v.crbegin();
    auto p_it = p.crbegin();
    for (; p_it != p.crend() && v_it != v.crend(); ++p_it, ++v_it) {
      STF_EQUAL(*p_it, *v_it);
    }
  }
}

STF_CASE_TPL( "Check logical pack's iterators" , STF_NUMERIC_TYPES)
{
  ltest<T,  1>(runtime);
  ltest<T,  2>(runtime);
  ltest<T,  4>(runtime);
  ltest<T,  8>(runtime);
  ltest<T, 16>(runtime);
  ltest<T, 32>(runtime);
}
