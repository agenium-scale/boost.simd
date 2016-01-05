##==================================================================================================
##                 Copyright 2012 - 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

##==================================================================================================
## C++ Standard selector
##==================================================================================================
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

##==================================================================================================
## Handle warning level in MSVC
##==================================================================================================
if(MSVC)
  if("${CMAKE_C_FLAGS}" MATCHES "/W[1-4]")
    string(REGEX REPLACE "/W[1-4]" "/W4" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
  else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
  endif()

  if("${CMAKE_CXX_FLAGS}" MATCHES "/W[1-4]")
    string(REGEX REPLACE "/W[1-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
endif()

##==================================================================================================
## MSVC12 needs /FS if building in debug in parallel
##==================================================================================================
if(MSVC AND (MSVC_VERSION EQUAL 1800 OR MSVC_VERSION GREATER 1800))
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /FS")
endif()

set(SIMD_FLAGS_TEST "${SIMD_FLAGS_TEST} -DBOOST_ENABLE_ASSERT_HANDLER -DBRIGAND_LEAN_AND_MEAN")
set(SIMD_FLAGS_BENCH "${CMAKE_CXX_FLAGS_RELEASE} -DBRIGAND_LEAN_AND_MEAN")

##==================================================================================================
## Precision and optimization settings
##==================================================================================================
if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fp:precise")
  set(SIMD_FLAGS_TEST "${SIMD_FLAGS_TEST} /MDd /Oxt")
  set(SIMD_FLAGS_BENCH "/DNDEBUG /MD /D_SECURE_SCL=0 /GL /Oxt /wd4530")

elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
  if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fp-model precise")
    set(SIMD_FLAGS_TEST "${SIMD_FLAGS_TEST} -O2")
    set(SIMD_FLAGS_BENCH "${SIMD_FLAGS_BENCH} -fno-exceptions")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fp:precise")
    set(SIMD_FLAGS_TEST "${SIMD_FLAGS_TEST} /O2")
    string(REPLACE "/EHsc" "" SIMD_FLAGS_BENCH "${SIMD_FLAGS_BENCH}")
  endif()

elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
  set(SIMD_FLAGS_TEST "${SIMD_FLAGS_TEST} -O2")
  set(SIMD_FLAGS_BENCH "-DNDEBUG -O3 -fomit-frame-pointer -fno-exceptions")
endif()

##==================================================================================================
## MSVC Linker settings
##==================================================================================================
if(MSVC)
  set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /LTCG")
  set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /LTCG")
endif()

##==================================================================================================
## MSVC STL warnings
##==================================================================================================
if(MSVC)
  set(SIMD_FLAGS_TEST "${SIMD_FLAGS_TEST} /D_SCL_SECURE_NO_WARNINGS")
endif()

##==================================================================================================
## Final setup and display
##==================================================================================================
set(CMAKE_CXX_FLAGS_RELEASE "${SIMD_FLAGS_BENCH}")
set(CMAKE_CXX_FLAGS_DEBUG   "${SIMD_FLAGS_TEST}")

message(STATUS "[boost.simd] Global flags: ${CMAKE_CXX_FLAGS}")
message(STATUS "[boost.simd] Test flags: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "[boost.simd] Benchmark flags: ${CMAKE_CXX_FLAGS_RELEASE}")
