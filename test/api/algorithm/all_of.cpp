//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/algorithm/all_of.hpp>
#include <boost/align/aligned_allocator.hpp>
#include <numeric>
#include <vector>
#include <simd_test.hpp>

using namespace boost::simd;
using namespace boost::alignment;

STF_CASE_TPL( "Check simd::all_of(f,l)", STF_NUMERIC_TYPES )
{
  static const int N = pack<T>::static_size;

  {

    std::vector<T,aligned_allocator<T,pack<T>::alignment>> values(2*N);
    std::iota(values.begin(), values.end(),T(1));

    auto ab = values.data();
    auto ae = values.data()+values.size();

    // All aligned
    STF_EQUAL ( true
              , (boost::simd::all_of(ab,ae))
              );

    // prologue + aligned
    STF_EQUAL ( true
              , (boost::simd::all_of(ab+1,ae))
              );

    // aligned + epilogue
    STF_EQUAL ( true
              , (boost::simd::all_of(ab,ae-1))
              );

    // prologue + epilogue
    STF_EQUAL ( true
              , (boost::simd::all_of(ab+1,ae-1))
              );
  }
  {

    std::vector<T,aligned_allocator<T,pack<T>::alignment>> values(2*N);
    std::iota(values.begin(), values.end(),T(1));
    values[N] = T(0); // 0 in aligned

    auto ab = values.data();
    auto ae = values.data()+values.size();

    // All aligned
    STF_EQUAL ( false
              , (boost::simd::all_of(ab,ae))
              );

    // prologue + aligned
    STF_EQUAL ( false
              , (boost::simd::all_of(ab+1,ae))
              );

    // aligned + epilogue
    STF_EQUAL ( false
              , (boost::simd::all_of(ab,ae-1))
              );

    // prologue + epilogue
    STF_EQUAL ( false
              , (boost::simd::all_of(ab+1,ae-1))
              );
  }
  {

    std::vector<T,aligned_allocator<T,pack<T>::alignment>> values(2*N);
    std::iota(values.begin(), values.end(),T(1));
    values[1] = T(0);// 0 in prologue

    auto ab = values.data();
    auto ae = values.data()+values.size();

    // All aligned
    STF_EQUAL ( false
              , (boost::simd::all_of(ab,ae))
              );

    // prologue + aligned
    STF_EQUAL ( false
              , (boost::simd::all_of(ab+1,ae))
              );

    // aligned + epilogue
    STF_EQUAL ( false
              , (boost::simd::all_of(ab,ae-1))
              );

    // prologue + epilogue
    STF_EQUAL ( false
              , (boost::simd::all_of(ab+1,ae-1))
              );
  }
  {

    std::vector<T,aligned_allocator<T,pack<T>::alignment>> values(2*N);
    std::iota(values.begin(), values.end(),T(1));
    values[2*N-2] = T(0);// 0 in epilogue

    auto ab = values.data();
    auto ae = values.data()+values.size();

    // All aligned
    STF_EQUAL ( false
              , (boost::simd::all_of(ab,ae))
              );

    // prologue + aligned
    STF_EQUAL ( false
              , (boost::simd::all_of(ab+1,ae))
              );

    // aligned + epilogue
    STF_EQUAL ( false
              , (boost::simd::all_of(ab,ae-1))
              );

    // prologue + epilogue
    STF_EQUAL ( false
              , (boost::simd::all_of(ab+1,ae-1))
              );
  }
}


