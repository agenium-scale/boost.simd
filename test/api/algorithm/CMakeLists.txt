##==================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

SET( SOURCES
    all_of.cpp
    any_of.cpp
    copy.cpp
    copy_n.cpp
    count.cpp
    count_if.cpp
    equal.cpp
    fill.cpp
    find.cpp
    find_if.cpp
    find_if_not.cpp
    generate.cpp
    generate_n.cpp
    iota.cpp
    lexicographical_compare.cpp
    max_element.cpp
    max_val.cpp
    min_element.cpp
    min_val.cpp
    none_of.cpp
    not_all_of.cpp
    reduce.cpp
    replace.cpp
    replace_if.cpp
    transform.cpp
    transform_reduce.cpp
    transform_reduce2.cpp
   )

make_unit( "api.algorithm" ${SOURCES})
