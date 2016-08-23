//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_CPUID_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_CPUID_HPP_INCLUDED

#include <boost/predef/architecture.h>
#include <boost/predef/compiler.h>

#if BOOST_ARCH_X86

#if BOOST_COMP_GNUC || BOOST_COMP_CLANG
#include <cpuid.h>
#else
#include <intrin.h>
#endif

namespace boost { namespace simd { namespace detail
{
#if BOOST_COMP_GNUC || BOOST_COMP_CLANG
  using register_type = unsigned int;
#else
  using register_type = int;
#endif

  enum registerID { eax=0, ebx=1, ecx=2, edx=3 };

  void cpuid(register_type pRegisters[4], int function) {
#if BOOST_COMP_GNUC || BOOST_COMP_CLANG
    __cpuid (function, pRegisters[eax], pRegisters[ebx], pRegisters[ecx], pRegisters[edx]);
#else
  __cpuid(pRegisters, function);
#endif
  }

  void cpuidex(register_type pRegisters[4], int function, int subfunction) {
#if BOOST_COMP_GNUC || BOOST_COMP_CLANG
    __cpuid_count ( function, subfunction
                  , pRegisters[eax], pRegisters[ebx], pRegisters[ecx], pRegisters[edx]
                  );
#else
  __cpuidex(pRegisters, function, subfunction);
#endif
  }

  bool detect_feature(int bit, int function, int register_id)
  {
    register_type regs_x86[4] = {0x00000000, 0x00000000, 0x00000000, 0x00000000};
    cpuidex(regs_x86, function, 0);
    return (regs_x86[register_id] & (1 << bit)) != 0;
  }

  bool detect_features(int bits, int function, int register_id)
  {
    register_type regs_x86[4] = {0x00000000, 0x00000000, 0x00000000, 0x00000000};
    cpuidex(regs_x86, function, 0);
    return (regs_x86[register_id] & bits) != 0;
  }
} } }
#endif

#endif
