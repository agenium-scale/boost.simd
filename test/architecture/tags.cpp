//==================================================================================================
/*
  Copyright 2009 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/arch/tags.hpp>
#include <nstest.hpp>

NSTEST_CASE( "Check for basic SIMD tag parent" )
{
  NSTEST_TYPE_IS( boost::simd::simd_::parent          , boost::dispatch::cpu_ );
  NSTEST_TYPE_IS( boost::simd::simd_emulation_::parent, boost::simd::simd_    );
}

NSTEST_CASE( "Check for architectural tag parent for X86/AMD" )
{
  NSTEST_TYPE_IS( boost::simd::sse_::parent    , boost::simd::simd_   );
  NSTEST_TYPE_IS( boost::simd::sse2_::parent   , boost::simd::sse_    );
  NSTEST_TYPE_IS( boost::simd::sse3_::parent   , boost::simd::sse2_   );
  NSTEST_TYPE_IS( boost::simd::ssse3_::parent  , boost::simd::sse3_   );

  #ifdef BOOST_HW_SIMD_X86_AMD_AVAILABLE
  NSTEST_TYPE_IS( boost::simd::sse4a_::parent , boost::simd::ssse3_  );
  NSTEST_TYPE_IS( boost::simd::sse4_1_::parent , boost::simd::sse4a_ );
  #else
  NSTEST_TYPE_IS( boost::simd::sse4_1_::parent , boost::simd::ssse3_  );
  #endif

  NSTEST_TYPE_IS( boost::simd::sse4_2_::parent  , boost::simd::sse4_1_ );
  NSTEST_TYPE_IS( boost::simd::avx_::parent     , boost::simd::sse4_2_ );

#ifdef BOOST_HW_SIMD_X86_AMD_AVAILABLE
  NSTEST_TYPE_IS( boost::simd::fma4_::parent  , boost::simd::avx_ );
  NSTEST_TYPE_IS( boost::simd::xop_::parent   , boost::simd::fma4_ );
#endif

#ifdef BOOST_HW_SIMD_X86_AMD_AVAILABLE
  NSTEST_TYPE_IS( boost::simd::fma3_::parent  , boost::simd::xop_ );
#else
  NSTEST_TYPE_IS( boost::simd::fma3_::parent  , boost::simd::avx_ );
#endif

  NSTEST_TYPE_IS( boost::simd::avx2_::parent, boost::simd::fma3_ );
  NSTEST_TYPE_IS( boost::simd::mic_::parent , boost::simd::sse2_ );
}

NSTEST_CASE( "Check for architectural tag parent for PowerPC" )
{
  NSTEST_TYPE_IS( boost::simd::vmx_::parent , boost::simd::simd_  );
  NSTEST_TYPE_IS( boost::simd::vsx_::parent , boost::simd::vmx_   );
  NSTEST_TYPE_IS( boost::simd::qpx_::parent , boost::simd::simd_  );
}

NSTEST_CASE( "Check for architectural tag parent for ARM" )
{
  NSTEST_TYPE_IS( boost::simd::neon64_::parent, boost::simd::simd_  );
  NSTEST_TYPE_IS( boost::simd::neon_::parent  , boost::simd::simd_  );
}
