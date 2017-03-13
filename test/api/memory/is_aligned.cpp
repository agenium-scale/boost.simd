//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/memory/is_aligned.hpp>
#include <boost/simd/memory/deallocate.hpp>
#include <boost/simd/memory/allocate.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Check is_aligned on default architecture", STF_NUMERIC_TYPES )
{
  T* ptr = allocate<T>( 7 );

  STF_EXPECT    ( is_aligned(ptr)   );
  STF_EXPECT_NOT( is_aligned(ptr+1) );

  deallocate(ptr);
}

STF_CASE_TPL( "Check is_aligned on default architecture", STF_NUMERIC_TYPES )
{
  T* ptr16 = allocate<T>( 7, sse1 );
  T* ptr32 = allocate<T>( 7, avx );

  STF_EXPECT( is_aligned(ptr16, sse1 ));
  STF_EXPECT( is_aligned(ptr16, sse2 ));
  STF_EXPECT( is_aligned(ptr16, sse3 ));
  STF_EXPECT( is_aligned(ptr16, ssse3));
  STF_EXPECT( is_aligned(ptr32, sse1 ));
  STF_EXPECT( is_aligned(ptr32, sse2 ));
  STF_EXPECT( is_aligned(ptr32, sse3 ));
  STF_EXPECT( is_aligned(ptr32, ssse3));
  STF_EXPECT( is_aligned(ptr32, avx  ));
  STF_EXPECT( is_aligned(ptr32, avx2 ));

  deallocate(ptr16);
  deallocate(ptr32);
}
