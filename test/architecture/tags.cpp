//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/predef/architecture.h>
#include <boost/simd/arch/tags.hpp>
#include <simd_test.hpp>

STF_CASE( "Check for SIMD tag support facility" )
{
  std::cout << "---------------------\n";
  std::cout << "X86 Extensions\n";
  std::cout << "---------------------\n";
  std::cout << "SSE1   support: " << std::boolalpha << boost::simd::sse1.is_supported()   << "\n";
  std::cout << "SSE2   support: " << std::boolalpha << boost::simd::sse2.is_supported()   << "\n";
  std::cout << "SSE3   support: " << std::boolalpha << boost::simd::sse3.is_supported()   << "\n";
  std::cout << "SSSE3  support: " << std::boolalpha << boost::simd::ssse3.is_supported()  << "\n";
  std::cout << "SSE4a  support: " << std::boolalpha << boost::simd::sse4a.is_supported()  << "\n";
  std::cout << "SSE4.1 support: " << std::boolalpha << boost::simd::sse4_1.is_supported() << "\n";
  std::cout << "SSE4.2 support: " << std::boolalpha << boost::simd::sse4_2.is_supported() << "\n";
  std::cout << "---------------------\n";

  STF_PASS("Support detection from architecture object.");
}

STF_CASE( "Check for basic SIMD tag parent" )
{
  STF_TYPE_IS( boost::simd::simd_::parent          , boost::dispatch::cpu_ );
  STF_TYPE_IS( boost::simd::simd_emulation_::parent, boost::simd::simd_    );
  STF_TYPE_IS( boost::simd::simd_native_::parent   , boost::simd::simd_    );
}

STF_CASE( "Check for architectural tag parent for X86/AMD" )
{
  STF_TYPE_IS( boost::simd::sse1_::parent   , boost::simd::simd_native_ );
  STF_TYPE_IS( boost::simd::sse2_::parent   , boost::simd::sse1_        );
  STF_TYPE_IS( boost::simd::sse3_::parent   , boost::simd::sse2_        );
  STF_TYPE_IS( boost::simd::ssse3_::parent  , boost::simd::sse3_        );
  STF_TYPE_IS( boost::simd::sse4_1_::parent , boost::simd::ssse3_  );
  STF_TYPE_IS( boost::simd::sse4_2_::parent , boost::simd::sse4_1_ );
}
