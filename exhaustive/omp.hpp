//==============================================================================
//         Copyright 2016        NumScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_EXHAUSTIVE_OMP_HPP_INCLUDED
#define NT2_SDK_EXHAUSTIVE_OMP_HPP_INCLUDED

namespace boost{
  namespace simd {
#ifdef _OPENMP
#include <omp.h>

    inline int get_num_threads()
    {
      return omp_get_num_threads();
    }

    inline int get_thread_num()
    {
      return omp_get_thread_num();
    }

#else

    inline int get_num_threads()
    {
      return 1;
    }

    inline int get_thread_num()
    {
      return 0;
    }

#endif

  }
}

#endif
