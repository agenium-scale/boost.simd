//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/predef/architecture.h>
#include <boost/simd/arch/tags.hpp>
#include <simd_test.hpp>

STF_CASE( "Check for basic SIMD tag parent" )
{
  STF_TYPE_IS( boost::simd::simd_::parent          , boost::dispatch::cpu_ );
  STF_TYPE_IS( boost::simd::simd_emulation_::parent, boost::simd::simd_    );
  STF_TYPE_IS( boost::simd::simd_native_::parent   , boost::simd::simd_    );
}

#ifdef BOOST_ARCH_X86_AVAILABLE
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
#endif

#ifdef BOOST_ARCH_PPC_AVAILABLE
STF_CASE( "Check for architectural tag parent for PowerPC" )
{
  STF_TYPE_IS( boost::simd::vmx_::parent , boost::simd::simd_  );
}
#endif
