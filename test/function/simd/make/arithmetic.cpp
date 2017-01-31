//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/simd/make.hpp>
#include <boost/simd/pack.hpp>
#include <algorithm>
#include <simd_test.hpp>

#if !(defined(BOOST_INTEL_CXX_VERSION) && BOOST_INTEL_CXX_VERSION < 1600)
// Unless variadic template support sucks big time, these must be tested

STF_CASE_TPL( "Check make(a0,a1)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;

  std::array<T,2> ref = {{ T(1), T(2) }};
  auto p = bs::make<bs::pack<T,2>>(1,2);

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(a0,...,a3)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;

  std::array<T,4> ref = {{ T(1), T(2), T(3), T(4) }};
  auto p = bs::make<bs::pack<T,4>>(1,2,3,4);

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(a0,...,a7)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  std::array<T,8> ref = {{ T(1), T(2), T(3), T(4), T(5), T(6), T(7), T(8) }};
  auto p = bs::make<bs::pack<T,8>>(1,2,3,4,5,6,7,8);

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(a0,...,a15)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  std::array<T,16> ref  = {{  T(1), T(2) , T(3) , T(4) , T(5) , T(6) , T(7) , T(8)
                          ,   T(9), T(10), T(11), T(12), T(13), T(14), T(15), T(16)
                          }};
  auto p = bs::make<bs::pack<T,16>>(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(a0,...,a31)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  std::array<T,32> ref  = {{  T(1) , T(2) , T(3) , T(4) , T(5) , T(6) , T(7) , T(8)
                          ,   T(9) , T(10), T(11), T(12), T(13), T(14), T(15), T(16)
                          ,   T(17), T(18), T(19), T(20), T(21), T(22), T(23), T(24)
                          ,   T(25), T(26), T(27), T(28), T(29), T(30), T(31), T(32)
                          }};
  auto p = bs::make<bs::pack<T,32>> ( 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16
                                    ,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32
                                    );

  STF_ALL_EQUAL(p, ref);
}

#endif // BOOST_INTEL_CXX_VERSION

// These must work anyway

STF_CASE_TPL( "Check make(a0,a1)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;

  std::array<T,2> ref = {{ T(1), T(2) }};
  auto p = bs::make(bs::as_<bs::pack<T,2>>{},1,2);

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(as_<tag>{},a0,...,a3)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;

  std::array<T,4> ref = {{ T(1), T(2), T(3), T(4) }};
  auto p = bs::make(bs::as_<bs::pack<T,4>>{},1,2,3,4);

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(as_<tag>{}a0,...,a7)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  std::array<T,8> ref = {{ T(1), T(2), T(3), T(4), T(5), T(6), T(7), T(8) }};
  auto p = bs::make(bs::as_<bs::pack<T,8>>{},1,2,3,4,5,6,7,8);

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(as_<tag>{},a0,...,a15)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  std::array<T,16> ref  = {{  T(1), T(2) , T(3) , T(4) , T(5) , T(6) , T(7) , T(8)
                          ,   T(9), T(10), T(11), T(12), T(13), T(14), T(15), T(16)
                          }};
  auto p = bs::make(bs::as_<bs::pack<T,16>>{},1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);

  STF_ALL_EQUAL(p, ref);
}

STF_CASE_TPL( "Check make(as_<tag>{},a0,...,a31)", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  std::array<T,32> ref  = {{  T(1) , T(2) , T(3) , T(4) , T(5) , T(6) , T(7) , T(8)
                          ,   T(9) , T(10), T(11), T(12), T(13), T(14), T(15), T(16)
                          ,   T(17), T(18), T(19), T(20), T(21), T(22), T(23), T(24)
                          ,   T(25), T(26), T(27), T(28), T(29), T(30), T(31), T(32)
                          }};
  auto p = bs::make(bs::as_<bs::pack<T,32>>{}
                   , 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16
                   ,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32
                   );

  STF_ALL_EQUAL(p, ref);
}
