//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/meta/is_pointing_to.hpp>
#include <simd_test.hpp>
#include <list>

using namespace boost::simd;

STF_CASE_TPL("Check is_pointing_to with pointers", STF_NUMERIC_TYPES)
{
  STF_EXPECT    (( is_pointing_to<T*      , T>::value     ));
  STF_EXPECT_NOT(( is_pointing_to<T*      , bool>::value  ));
  STF_EXPECT    (( is_pointing_to<T const*, T>::value     ));
  STF_EXPECT_NOT(( is_pointing_to<T const*, bool>::value  ));
}

STF_CASE_TPL("Check is_pointing_to with iterator", STF_NUMERIC_TYPES)
{
  STF_EXPECT(( is_pointing_to < typename std::list<T>::iterator
                              , T
                              >::value
            ));

  STF_EXPECT_NOT(( is_pointing_to < typename std::list<T>::iterator
                                  , bool
                                  >::value
                ));

  STF_EXPECT(( is_pointing_to < typename std::list<T>::const_iterator
                              , T
                              >::value
            ));

  STF_EXPECT_NOT(( is_pointing_to < typename std::list<T>::const_iterator
                                  , bool
                                  >::value
                ));
}
