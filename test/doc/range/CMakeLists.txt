##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
    aligned_range.cpp
    aligned_range_t.cpp
    all_of.cpp
    any_of.cpp
    copy.cpp
    copy_n.cpp
    count.cpp
    count_if.cpp
    equalrange.cpp
    fill.cpp
    find.cpp
    find_if.cpp
    find_if_not.cpp
    generate.cpp
    generate_n.cpp
    iota.cpp
    lexicographical_comparerange.cpp
    max_element.cpp
    max_val.cpp
    min_element.cpp
    min_val.cpp
    none_of.cpp
    not_all_of.cpp
    range_t.cpp
    range.cpp
    reduce.simple.cpp
    reduce.phases.cpp
    reduce.phase.cpp
    replace.cpp
    replace_if.cpp
    segmented_aligned_range.cpp
    segmented_aligned_range_t.cpp
    segmented_range.cpp
    segmented_range_t.cpp
    transform.unary.cpp
    transform.binary.cpp
    transform_reduce.cpp
    transform_reduce2.cpp
    transform_reduce2b.cpp
  )

make_unit( "doc.range" ${SOURCES})
