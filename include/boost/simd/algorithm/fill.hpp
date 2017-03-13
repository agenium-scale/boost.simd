//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_FILL_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_FILL_HPP_INCLUDED

#include <boost/simd/range/segmented_output_range.hpp>
#include <boost/simd/function/all.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/detail/identity.hpp>
#include <algorithm>

namespace boost { namespace simd
{
  /*!
    @ingroup group-std

    fill range [first,last) with value

    @param first  Beginning of the range of elements to test
    @param last   End of the range of elements to fill
    @param value  value to reproduce in range

    @par Requirement

      - @c first and @c last must be pointers to Vectorizable type.


    @par Example;:

      @snippet fill.cpp fill

    @par Possible output:

      @snippet fill.txt fill

  **/
  template<typename T, typename U>
  void fill(T * first, T * last, U value)
  {

    auto pr = segmented_output_range(first,last);

    // prologue
    auto r0 = std::get<0>(pr);
    std::fill(r0.begin(),  r0.end(), value);

    // main SIMD part
    auto r1 = std::get<1>(pr);
    std::fill(r1.begin(),  r1.end(), pack<T>(value));

    // epilogue
    auto r2 = std::get<2>(pr);
    std::fill(r2.begin(),  r2.end(), value);
  }

} }

#endif
