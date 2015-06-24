//==================================================================================================
/*!
  @file

  Main header for the unit test system

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================

#ifndef NSTEST_UNIT_HPP_INCLUDED
#define NSTEST_UNIT_HPP_INCLUDED

#include <nstest/unit/env.hpp>
#include <nstest/unit/case.hpp>
#include <nstest/unit/test.hpp>
#include <nstest/unit/driver.hpp>

#if !defined(NSTEST_USE_CUSTOM_DRIVER)
#include <nstest/unit/main.hpp>
#endif

#include <nstest/unit/detail/assertion_failure.hpp>

namespace nstest
{
  namespace unit
  {
    /*!
      @defgroup group-unit Unit Test related components.
      Unit Test related components
    **/

#if defined(DOXYGEN_ONLY)
/*!
  @ingroup group-unit
  @brief Test application entry-point registration

  If NSTEST_USE_CUSTOM_DRIVER is defined, NSTest won't define an predefined @c main function
  and will let the client application provides it.

  @snippet example/unit/case.cpp custom_driver_macro
**/
#define NSTEST_USE_CUSTOM_DRIVER
#endif
  }
}

#endif
