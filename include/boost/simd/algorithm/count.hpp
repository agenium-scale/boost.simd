//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_COUNT_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_COUNT_HPP_INCLUDED

#include <boost/simd/range/segmented_input_range.hpp>
#include <boost/simd/function/nbtrue.hpp>
#include <boost/simd/pack.hpp>
#include <algorithm>

namespace boost { namespace simd
{
  /*!
    @ingroup group-std

    Returns the number of elements in the range [first,last) that compare equal to val.

    @param first  Beginning of the range of elements to count
    @param last   End of the range of elements to count
    @param val    Value to search for in the range.

    @par Requirement

      - @c first, @c last and @c out must be pointers to Vectorizable type.

      - @c val must be a scalar value convertible to the pointee type of first.

    @par Example:

      @snippet count.cpp count

    @par Possible output:

      @snippet count.txt count

  **/


  template<typename T, typename U>
  typename std::iterator_traits<const T*>::difference_type
  count(T const* first, T const* last, U const & val)
  {
    using p_t = boost::simd::pack<T>;
    auto pr = segmented_input_range(first,last);
    // prologue
    auto r0 = std::get<0>(pr);
    auto c = std::count(r0.begin(), r0.end(), val);

    // main simd part
    p_t pval(val);
    for(p_t x :  std::get<1>(pr)) c+= nbtrue(x == pval);

    // epilogue
    auto r2 = std::get<2>(pr);
    c += std::count(r2.begin(), r2.end(), val);

    return c;
  }

} }

#endif
