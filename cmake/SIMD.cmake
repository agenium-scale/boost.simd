## Copyright (c) 2019 Agenium Scale
## 
## Permission is hereby granted, free of charge, to any person obtaining a copy
## of this software and associated documentation files (the "Software"), to deal
## in the Software without restriction, including without limitation the rights
## to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
## copies of the Software, and to permit persons to whom the Software is
## furnished to do so, subject to the following conditions:
## 
## The above copyright notice and this permission notice shall be included in all
## copies or substantial portions of the Software.
## 
## THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
## IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
## FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
## AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
## LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
## OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
## SOFTWARE.
## 
## ------------------------------------------------------------------------------------------------

## Retrieve SIMD CXXFLAGS and command-line options for hatch.py
function(SIMD OUT simd)
    ## The list of options passed to this function
    set(simds
        CPU
        SSE SSE2 SSE3 SSSE SSE41 SSE42
        AVX AVX2 AVX512_KNL AVX512_SKYLAKE
        NEON64 NEON128
        AARCH64
        SVE
    )
    set(simd_optionals
        FMA FP16
    )
    ## Check if simd is valid
    list(FIND simds ${simd} i)
    if (i EQUAL -1)
        message(FATAL_ERROR "Unknown SIMD: '${simd}' must be one of: ${simds}")
    endif()
    ## Parse simd_optional parameter
    cmake_parse_arguments(has "${simd_optionals}" "" "" ${ARGN})
    ## Detect compiler
    if ("${CMAKE_SIZEOF_VOID_P}" STREQUAL "4")
        set(bits 32)
    else()
        set(bits 64)
    endif()
    if (MSVC)
        set(cxx "MSVC${bits}")
    else()
        set(cxx "CXX")
    endif()
    ## Detect architecture
    if (${CMAKE_SYSTEM_PROCESSOR} MATCHES "arm")
        set(arch "ARM")
    else()
        set(arch "X86")
    endif()
    ## Now, append each flags
    ## CPU
    set(CPU_hatch "cpu")
    set(CPU_deps)
    ## SSE2
    set(SSE2_hatch "sse2")
    set(SSE2_flags "-msse2")
    set(SSE2_deps "${CPU_deps} CPU")
    if (cxx EQUAL "MSVC" AND bits EQUAL 32)
        set(SSE2_flags "/arch:SSE2")
    endif()
    ## SSE4_2
    set(SSE42_hatch "sse4.2")
    set(SSE42_flags "-msse4.2")
    set(SSE42_deps "${SSE2_deps} SSE2")
    ## AVX
    set(AVX_hatch "avx")
    set(AVX_flags "-mavx")
    if (cxx EQUAL "MSVC")
        set(AVX_flags "/arch:AVX")
    endif()
    set(AVX_deps "${SSE42_deps} SSE42")
    ## AVX2
    set(AVX2_hatch "avx2")
    set(AVX2_flags "-mavx2")
    if (cxx EQUAL "MSVC")
        set(AVX2_flags "/arch:AVX2")
    endif()
    set(AVX2_deps "${AVX_deps} AVX")
    ## AVX512_KNL
    set(AVX512_KNL_hatch "avx512_knl")
    set(AVX512_KNL_flags "-mavx512f -mavx512pf -mavx512er -mavx512cd")
    if (cxx EQUAL "MSVC")
        set(AVX2_flags "/arch:AVX512")
    endif()
    set(AVX512_KNL_deps "${AVX2_deps} AVX2")
    ## AVX512_SKYLAKE
    set(AVX512_SKYLAKE_hatch "avx512_skylake")
    set(AVX512_SKYLAKE_flags "-mavx512f -mavx512dq -mavx512cd -mavx512bw -mavx512vl")
    if (cxx EQUAL "MSVC")
        set(AVX2_flags "/arch:AVX512")
    endif()
    set(AVX512_SKYLAKE_deps "${AVX2_deps} AVX2")
    ## NEON128
    set(NEON128_hatch "neon128")
    set(NEON128_flags "-mfpu=neon")
    set(NEON128_deps  "${CPU_deps} CPU")
    ## AARCH64
    set(AARCH64_hatch "aarch64")
    set(AARCH64_flags "")
    set(AARCH64_deps  "${NEON128_deps} NEON128")
    ## SVE
    set(SVE_hatch "sve")
    set(SVE_flags "-march=armv8+sve")
    set(SVE_deps  "${AARCH64_deps} AARCH64")
    ## OPTIONAL FLAGS
    set(optional_hatch)
    set(optional_flags)
    set(optional_deps)
    if (has_FMA)
        set(optional_hatch "${optional_hatch},fma4")
        set(optional_flags "${optional_flags} -mfma -DFMA")
        set(optional_deps  "${optional_deps} FMA")
        set(${OUT}_FMA TRUE PARENT_SCOPE)
    endif()
    if (has_FP16)
        if (arch EQUAL "ARM" AND bits EQUAL 64)
            set(optional_flags "${optional_flags} -march=native+fp16")
        endif()
        ## TODO
        set(${OUT}_FP16 TRUE PARENT_SCOPE)
    endif()
    ## Set return values:
    ## --------------------------------------------------------------------------------------------
    ## The compilation flag
    set(${OUT}_FLAGS "${${simd}_flags} -D${simd} ${optional_flags}" PARENT_SCOPE)
    ## The hatch.py command line options
    set(${OUT}_HATCH "${${simd}_hatch}${optional_hatch}" PARENT_SCOPE)
    ## The list of all SIMD that depends on current SIMD target
    set(${OUT}_DEPS  "${${simd}_deps}${optional_deps}" PARENT_SCOPE)
    ## Also set all dependencies on the OUT variable
    string(REPLACE " " ";" list_deps "${${simd}_deps}${optional_deps}")
    foreach(dep ${list_deps})
        set(${OUT}_${dep} TRUE PARENT_SCOPE)
    endforeach()
    ## The SIMD target
    set(${OUT}_${simd} TRUE PARENT_SCOPE)
endfunction()
