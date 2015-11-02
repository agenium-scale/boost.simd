//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef SIMD_TEST_HPP_INCLUDED
#define SIMD_TEST_HPP_INCLUDED

#define STF_CUSTOM_DRIVER_FUNCTION simd_test
#include <stf.hpp>

int main(int argc, const char** argv)
{
  std::cout << "CTEST_FULL_OUTPUT\n";
  return simd_test(argc,argv);
}

#endif
