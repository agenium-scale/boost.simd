################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

SET( SOURCES
    aligned_input_iterator.cpp
    aligned_input_range.cpp
    aligned_output_iterator.cpp
    aligned_output_range.cpp
    direct_output_iterator.cpp
    input_iterator.cpp
    input_range.cpp
    output_iterator.cpp
    output_range.cpp
    realigned_input_range.cpp
    realigned_output_range.cpp
#    shifted_iterator.cpp
  )

make_unit( "api.iterator" ${SOURCES})
