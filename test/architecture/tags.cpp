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
  std::cout << "AVX    support: " << std::boolalpha << boost::simd::avx.is_supported()    << "\n";
  std::cout << "AVX2   support: " << std::boolalpha << boost::simd::avx2.is_supported()   << "\n";
  std::cout << "FMA3   support: " << std::boolalpha << boost::simd::fma3.is_supported()   << "\n";
  std::cout << "FMA4   support: " << std::boolalpha << boost::simd::fma4.is_supported()   << "\n";
  std::cout << "XOP    support: " << std::boolalpha << boost::simd::xop.is_supported()    << "\n";
  std::cout << "---------------------\n";
  std::cout << "PPC Extensions\n";
  std::cout << "---------------------\n";
  std::cout << "VMX    support: " << std::boolalpha << boost::simd::vmx.is_supported()    << "\n";

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

  #ifdef BOOST_HW_SIMD_X86_AMD_AVAILABLE
  STF_TYPE_IS( boost::simd::sse4a_::parent , boost::simd::ssse3_  );
  STF_TYPE_IS( boost::simd::sse4_1_::parent , boost::simd::sse4a_ );
  #else
  STF_TYPE_IS( boost::simd::sse4_1_::parent , boost::simd::ssse3_  );
  #endif

  STF_TYPE_IS( boost::simd::sse4_2_::parent  , boost::simd::sse4_1_ );
  STF_TYPE_IS( boost::simd::avx_::parent     , boost::simd::sse4_2_ );

#ifdef BOOST_HW_SIMD_X86_AMD_AVAILABLE
  STF_TYPE_IS( boost::simd::fma4_::parent  , boost::simd::avx_ );
  STF_TYPE_IS( boost::simd::xop_::parent   , boost::simd::fma4_ );
#endif

#ifdef BOOST_HW_SIMD_X86_AMD_AVAILABLE
  STF_TYPE_IS( boost::simd::fma3_::parent  , boost::simd::xop_ );
#else
  STF_TYPE_IS( boost::simd::fma3_::parent  , boost::simd::avx_ );
#endif

  STF_TYPE_IS( boost::simd::avx2_::parent, boost::simd::fma3_ );
}

STF_CASE( "Check for architectural tag parent for PowerPC" )
{
  STF_TYPE_IS( boost::simd::vmx_::parent , boost::simd::simd_  );
}
