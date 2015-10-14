##===================================================================================================
##                 Copyright 2009 - 2015   LRI    UMR 8623 CNRS/Univ Paris Sud XI
##                 Copyright 2012 - 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

##===================================================================================================
## Detect if we need to add C++11 support & extra-warnings
##===================================================================================================
if(NOT BOOST_DISPATCH_COMPILER_OPTIONS_INCLUDED)
  set(BOOST_DISPATCH_COMPILER_OPTIONS_INCLUDED 1)

  if(CXX_STD)
    string(REGEX MATCH "1(1|4|7)" MATCHED ${CXX_STD})
    if(NOT MATCHED)
      message(WARNING "CXX_STD did not match any valid C++ standard, falling back to c++11")
      set(CXX_STD "11")
    endif()
  else()
    set(CXX_STD "11")
  endif()

  if(NOT ${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++${CXX_STD} -Wall -Wshadow -Wextra")
  endif()

  if(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    if("${CMAKE_CXX_FLAGS}" MATCHES "/W[1-4]")
      string(REGEX REPLACE "/W[1-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /DNOMINMAX")
  endif()

  if(CMAKE_CXX_FLAGS MATCHES "[^ ]")
    message(STATUS "[boost.simd] Compilation flags: ${CMAKE_CXX_FLAGS}")
  endif()

  ## Remove /EHsc from CMAKE_CXX_FLAGS and re-add per configuration to avoid 'overriding' warnings
  if(CMAKE_CXX_FLAGS MATCHES "/EHsc")
    string(REPLACE " /EHsc" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    foreach(config Debug Release)
      string(TOUPPER ${config} config_U)
      set(CMAKE_CXX_FLAGS_${config_U} "/EHsc ${CMAKE_CXX_FLAGS_${config_U}}")
    endforeach()
  endif()

  ## MSVC12 needs /FS if building in debug in parallel
  if(MSVC AND (MSVC_VERSION EQUAL 1800 OR MSVC_VERSION GREATER 1800))
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /FS")
  endif()

endif()
