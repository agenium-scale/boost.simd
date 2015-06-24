//==================================================================================================
//                  Copyright 2012 - 2015 NumScale SAS
//
//                    Distributed under the Boost Software License, Version 1.0.
//                           See accompanying file LICENSE.txt or copy at
//                               http://www.boost.org/LICENSE_1_0.txt
//==================================================================================================
#ifndef NSTEST_UNIT_DETAIL_RESULT_HPP_INCLUDED
#define NSTEST_UNIT_DETAIL_RESULT_HPP_INCLUDED

#include <string>

namespace nstest { namespace detail
{
  // Represent a test result and its displayable representation
  struct result
  {
    bool        status;
    std::string lhs;
    std::string op;
    std::string rhs;

    explicit operator bool() { return status; }
  };
} }

/*!
  @ingroup group-details
  Dump data from a comparison onto the output stream

  @param R Result structure to dump
**/
#define NSTEST_DUMP(R)                                                                              \
$.stream()  << "failing because:\n"                                                                 \
            << ::nstest::white_(R.lhs) << R.op << ::nstest::white_(R.rhs) << "\n"                   \
            << "is incorrect.\n";                                                                   \
/**/

#endif
