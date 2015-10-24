##===================================================================================================
##                 Copyright 2012 - 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================
include(setup)
include(make_unit)
include(make_coverage)

set(CMAKE_BUILD_TYPE "Debug")

## Add all test folders
add_subdirectory(api)
add_subdirectory(architecture)
