//==================================================================================================
//                  Copyright 2012 - 2015 NumScale SAS
//
//                    Distributed under the Boost Software License, Version 1.0.
//                           See accompanying file LICENSE.txt or copy at
//                               http://www.boost.org/LICENSE_1_0.txt
//==================================================================================================
#ifndef NSTEST_UNIT_DETAIL_REGISTRATION_HPP_INCLUDED
#define NSTEST_UNIT_DETAIL_REGISTRATION_HPP_INCLUDED

#include <nstest/unit/test.hpp>

namespace nstest { namespace detail
{
  struct registrar
  {
    registrar( test const& test_case ) { suite().push_back( test_case ); }
  };
} }

#endif
