//==================================================================================================
/*!
  @file

  Defines macros for building a custom test driver

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_UNIT_DRIVER_HPP_INCLUDED
#define NSTEST_UNIT_DRIVER_HPP_INCLUDED

#include <nstest/unit/env.hpp>
#include <nstest/common/values.hpp>

namespace nstest
{
  /*!
    @ingroup group-unit

    @brief Starts the execution of a test suite.

    Starts the execution of every tests registered into a test suite and report the test success
    or failure with respect to an expected count of failed and invalid tests being run.

    Usually, the test suite being run is given by nstest::test_suite() but it can
    differs in some use case, hence the need to pass it as a parameter.

    @par Example:
    @snippet example/unit/case.cpp driver

    @param environment  Test environment
    @param suite        Test suite to execute
    @param expected     Expected number of failing and invalid tests to be run

    @return A boolean value indicating if the whole test is considered a success.
  **/
  inline  bool run( env& environment, test_suite& tests
                  , std::pair<std::ptrdiff_t,std::ptrdiff_t> const& expected
                  )
  {
    for(auto& t : tests )
    {
      auto hbar = std::string(80,'-');
      environment.stream()  << hbar << std::endl
                            << "Scenario: " << ::nstest::white_(t.name) << std::endl
                            << hbar << std::endl;

      auto count = environment.tests();

      t(environment);

      if(count == environment.tests())
      {
        environment.as_invalid();
        environment.invalid() << ::nstest::white_("Empty test case") << std::endl;
      }

      environment.stream() << std::endl;
    }

    return ::nstest::report(environment,expected.first,expected.second);
  }
}

#endif
