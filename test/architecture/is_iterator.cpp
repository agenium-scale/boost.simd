//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

#include <vector>
#include <boost/simd/meta/is_iterator.hpp>
#include <simd_test.hpp>

STF_CASE( "Check is_iterator support" )
{
  using boost::simd::is_iterator;
  STF_EQUAL(is_iterator<int*>::value, true);
  STF_EQUAL(is_iterator<int const*>::value, true);
  STF_EQUAL(is_iterator<std::vector<int>::const_iterator>::value, true);
  STF_EQUAL(is_iterator<std::vector<int>::iterator>::value, true);
  STF_EQUAL(is_iterator<int>::value, false);
  STF_EQUAL(is_iterator<std::vector<int>>::value, false);
}

