##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
     if_allbits_else.cpp
     if_allbits_else_zero.cpp
     if_dec.cpp
     if_else.cpp
     if_else_allbits.cpp
     if_else_nan.cpp
     if_else_zero.cpp
     if_inc.cpp
     if_minus.cpp
     if_nan_else.cpp
     if_one_else_zero.cpp
     if_plus.cpp
     if_zero_else.cpp
     if_zero_else_allbits.cpp
     if_zero_else_one.cpp
     ifnot_dec.cpp
     ifnot_inc.cpp
     ifnot_minus.cpp
     ifnot_plus.cpp
     logical_and.cpp
     logical_andnot.cpp
     logical_not.cpp
     logical_notand.cpp
     logical_notor.cpp
     logical_or.cpp
     logical_ornot.cpp
     logical_xor.cpp
     mask2logical.cpp
     negif.cpp
     negifnot.cpp
  )

make_unit( "doc.boolean" ${SOURCES})
