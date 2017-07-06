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

  constexpr bool status = std::is_same<BOOST_SIMD_DEFAULT_SITE,boost::dispatch::cpu_>::value;

  STF_EXPECT( is_aligned(ptr)   );
  STF_EQUAL ( is_aligned(ptr+1), status );

  deallocate(ptr);
}

STF_CASE_TPL( "Check is_aligned on default architecture", STF_NUMERIC_TYPES )
{
  T* ptr16 = allocate<T>( 7, sse1 );

  STF_EXPECT( is_aligned(ptr16, sse1 ));
  STF_EXPECT( is_aligned(ptr16, sse2 ));
  STF_EXPECT( is_aligned(ptr16, sse3 ));
  STF_EXPECT( is_aligned(ptr16, ssse3));

  deallocate(ptr16);
}
