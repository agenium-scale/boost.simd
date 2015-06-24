//==================================================================================================
/*!
  @file

  Defines the nstest::env data structure and related functions

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_UNIT_ENV_HPP_INCLUDED
#define NSTEST_UNIT_ENV_HPP_INCLUDED

#include <nstest/common/color.hpp>
#include <nstest/common/args.hpp>
#include <iostream>
#include <cstddef>
#include <string>

namespace nstest
{
  /*!
    @brief Test case environment
    @ingroup group-unit

    This data structure holds information required to run and report tests status across test cases.
  **/
  struct env
  {
    public:

    env(int argc, const char** argv, std::ostream& s = std::cout)
      : test_count{0}, success_count{0}, invalid_count{0}, os(s)
    {
      args.update(argc,argv);
    }

    /// Report a test to be successful
    void as_success() { test_count++; success_count++; }

    /*!
      Report a test to be invalid

      A test case is to be reported invalid if it performs no test
    **/
    void as_invalid() { test_count++; invalid_count++; }

    /// Report a test to fail
    void as_failure() { test_count++; }

    /// Notify the test driver of the success of all test cases
    bool passed() const { return tests() != successes(); }

    /// Return the count of tests
    std::ptrdiff_t tests() const { return test_count; }

    /// Return the count of successes
    std::ptrdiff_t successes() const { return success_count; }

    /// Return the count of invalid tests
    std::ptrdiff_t invalids() const { return invalid_count; }

    /// Return the count of failures
    std::ptrdiff_t failures() const { return tests() - successes() - invalids(); }

    /// Return the output stream of the current driver
    std::ostream& stream() const { return os; }

    /// Insert a "[PASS]" message into the stream
    std::ostream& pass()    const { return os << green_("[PASS]") << " - "; }

    /// Insert a "[FAIL]" message into the stream
    std::ostream& fail()    const { return os << red_("[FAIL]") << " - "; }

    /// Insert a "[IVLD]" message into the stream
    std::ostream& invalid() const { return os << yellow_("[IVLD]") << " - "; }

    // Can't be generated due ton reference to ostream member
    env(env const&)             = delete;
    env& operator=(env const&)  = delete;

    private:
    std::ptrdiff_t  test_count;
    std::ptrdiff_t  success_count;
    std::ptrdiff_t  invalid_count;
    std::ostream&   os;
  };

  /*!
    @ingroup group-unit

    Display the results aggregated across all tests cases and return a value indicating if the
    whole test is successful or not.
  **/
  inline bool report(env const& e, std::ptrdiff_t fails, std::ptrdiff_t invalids)
  {
    auto test_txt = e.tests()     > 1 ? "tests"     : "test";
    auto pass_txt = e.successes() > 1 ? "successes" : "success";
    auto fail_txt = e.failures()  > 1 ? "failures"  : "failure";
    auto inv_txt  = e.invalids()  > 1 ? "invalids"  : "invalid";

    e.stream()  << default_ << std::string(80,'-') << "\n"
      << white_("Results: ")
      << white_(e.tests())  << " "    << white_(test_txt) << " - "
      << white_(e.successes()) << " " << green_(pass_txt) << " - "
      << white_(e.failures()) << "/"  << fails     << " " << red_(fail_txt) << " - "
      << white_(e.invalids()) << "/"  << invalids  << " " << yellow_(inv_txt)
      << std::endl;

    if(!fails && !invalids)
      return e.passed();
    else
      return e.failures() != fails || e.invalids() != invalids;
  }
}

#endif
