##===================================================================================================
##                               Copyright 2016   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

include(${NS_CMAKE_ROOT}/ns.cmake)
NS_guard(NS_CMAKE_COMPILERS)

##===================================================================================================
## Detect if we need to add C++11 support & extra-warnings
##===================================================================================================
if(DEFINED CXX_STD)
  string(REGEX MATCH "1(1|4|7)" MATCHED ${CXX_STD})
  if(NOT MATCHED)
    NS_warn("CXX_STD did not match any valid C++ standard, falling back to c++11")
    set(CXX_STD "11")
  endif()
else()
  set(CXX_STD "11")
endif()

if(NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++${CXX_STD} -Wall -Wshadow -Wextra")
else()
  if("${CMAKE_CXX_FLAGS}" MATCHES "/W[1-4]")
    string(REGEX REPLACE "/W[1-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
endif()

if(CMAKE_CXX_FLAGS MATCHES "[^ ]")
  NS_say("Compilation flags: ${CMAKE_CXX_FLAGS}")
endif()

if(MSVC)
  ## Remove /EHsc from CMAKE_CXX_FLAGS and re-add per configuration to avoid 'overriding' warnings
  if(CMAKE_CXX_FLAGS MATCHES "/EHsc")
    string(REPLACE " /EHsc" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    foreach(config Debug Release)
      string(TOUPPER ${config} config_U)
      set(CMAKE_CXX_FLAGS_${config_U} "/EHsc ${CMAKE_CXX_FLAGS_${config_U}}")
    endforeach()
  endif()

  ## MSVC12 needs /FS if building in debug in parallel
  if(MSVC_VERSION EQUAL 1800 OR MSVC_VERSION GREATER 1800)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /FS")
  endif()
endif()
