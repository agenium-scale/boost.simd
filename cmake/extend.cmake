## Copyright 2016 - NumScale SAS
## -------------------------------------------------------------------------------------------------

## -------------------------------------------------------------------------------------------------
file(GLOB_RECURSE SRCS FOLLOW_SYMLINKS ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(bsimd STATIC ${SRCS})

## -------------------------------------------------------------------------------------------------
set(MAKE_UNIT_TARGET_LINK_LIBRARIES  bsimd)
set(MAKE_BENCH_TARGET_LINK_LIBRARIES bsimd)
