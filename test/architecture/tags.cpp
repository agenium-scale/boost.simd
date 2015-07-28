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

#include <nstest.hpp>

NSTEST_CASE( "Check for architectural tag parent" )
{
  NSTEST_TYPE_IS( boost::simd::simd_::parent, boost::dispatch::cpu_ );
}

NSTEST_CASE( "Check for architectural tag parent for X86" )
{
  NSTEST_TYPE_IS( boost::simd::sse_::parent   , boost::simd::simd_  );
  NSTEST_TYPE_IS( boost::simd::sse2_::parent  , boost::simd::sse_   );
  NSTEST_TYPE_IS( boost::simd::sse3_::parent  , boost::simd::sse2_  );
  NSTEST_TYPE_IS( boost::simd::ssse3_::parent , boost::simd::sse3_  );
}
