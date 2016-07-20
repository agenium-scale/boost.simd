##==================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##==================================================================================================

NS_include(compilers)
NS_guard(BOOST_SIMD_SETUP)

##================================================================================================== ## Precision and optimization settings
##==================================================================================================
if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fp:precise")
  set(SIMD_FLAGS_TEST "${SIMD_FLAGS_TEST} /MDd /Oxt")
  set(SIMD_FLAGS_BENCH "/DNDEBUG /MD /D_SECURE_SCL=0 /GL /Oxt /wd4530 /EHsc")

elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
  if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fp-model precise")
    set(SIMD_FLAGS_TEST "${SIMD_FLAGS_TEST} -O2")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fp:precise")
    set(SIMD_FLAGS_TEST "${SIMD_FLAGS_TEST} /O2")
  endif()

elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
  set(SIMD_FLAGS_TEST "${SIMD_FLAGS_TEST} -O2")
  set(SIMD_FLAGS_BENCH "-DNDEBUG -O3 -fomit-frame-pointer")
endif()

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
  # Gcc is clasing while using `stf::type_id` with SIMD vectors of double cause they have the
  # same signature. This option is required to fix this error.
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fabi-version=6")
endif()

##==================================================================================================
## MSVC Linker settings
##==================================================================================================
if(MSVC)
  set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /LTCG")
  set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /LTCG")
endif()

##==================================================================================================
## MSVC STL warnings & noexcept
##==================================================================================================
if(MSVC)
  set(SIMD_FLAGS_TEST "${SIMD_FLAGS_TEST} /D_SCL_SECURE_NO_WARNINGS /EHsc")
endif()

##==================================================================================================
## Final setup and display
##==================================================================================================
set(CMAKE_CXX_FLAGS_RELEASE "${SIMD_FLAGS_BENCH}")
set(CMAKE_CXX_FLAGS_DEBUG   "${SIMD_FLAGS_TEST}")

NS_say("Global flags: ${CMAKE_CXX_FLAGS}")
NS_say("Testing flags: ${CMAKE_CXX_FLAGS_DEBUG}")
NS_say("Benchmark flags: ${CMAKE_CXX_FLAGS_RELEASE}")
