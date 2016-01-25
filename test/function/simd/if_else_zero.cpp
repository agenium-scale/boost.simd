//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/function/if_else_zero.hpp>
#include <simd_test.hpp>
#include <boost/simd/pack.hpp>

STF_CASE_TPL("if_else_zero", (float))//STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::if_else_zero;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;

  T a[16] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4 };
  p_t aa(&a[0], &a[N]);
  std::cout << aa << std::endl;
  T z[16] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
  p_t zz(&z[0], &z[N]);
  T c[16];

  for(int i=0; i < 16 ; ++i)
  {
    c[i] = zz[i] ? a[i] : T(0);
  }
  p_t cc(&c[0], &c[16]);
  std::cout << cc << std::endl;
  p_t dd = if_else_zero(cc, aa);
  STF_IEEE_EQUAL(cc, dd);
}

