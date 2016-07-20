##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

NS_include(make_unit)
NS_include(make_coverage)

set(CMAKE_BUILD_TYPE "Debug")

## Add all test folders
add_subdirectory(api)
add_subdirectory(architecture)
add_subdirectory(constant)
add_subdirectory(function)
add_subdirectory(regression)
