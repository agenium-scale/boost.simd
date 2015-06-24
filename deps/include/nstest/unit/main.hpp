//==================================================================================================
/*!
  @file

  Defines the automatic entry-point for all test cases

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_UNIT_MAIN_HPP_INCLUDED
#define NSTEST_UNIT_MAIN_HPP_INCLUDED

#if !defined(NSTEST_CUSTOM_DRIVER_FUNCTION)
#define NSTEST_CUSTOM_DRIVER_FUNCTION main
#endif

#if defined(DOXYGEN_ONLY)
/*!
  @ingroup group-unit
  @brief Test application entry-point customization

  In some scenario, one may need to run tests from a function not called main.
  Redefining NSTEST_CUSTOM_DRIVER_FUNCTION to any valid symbol name will generate a
  custom function callable from an already existing @c main function
**/
#define NSTEST_CUSTOM_DRIVER_FUNCTION
#endif

int NSTEST_CUSTOM_DRIVER_FUNCTION(int argc, const char** argv)
{
  ::nstest::env $env(argc,argv,std::cout);
  return ::nstest::run( $env, ::nstest::suite(), {0,0} );
}

#endif
