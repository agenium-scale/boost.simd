//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_COPY_N_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_COPY_N_HPP_INCLUDED

#include <boost/simd/range/copy.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-std

    Copies the elements in the range, defined by [first, last)
    to another range beginning at out.

    @param first  Beginning of the range of elements
    @param size   number of element to copy
    @param out    Beginning of the destination range

    @par Requirement

      - @c first and @c out must be pointer to type which can be used within
        boost::simd::pack.
      - returns a pointer to the element past the last element copied.

    @par Example:

      @snippet copy_n.cpp copy_n

    @par Possible output:

      @snippet copy_n.txt copy_n

  **/
  template<typename T, typename Size, typename U>
  U* copy_n(T const* first, Size n, U* out)
  {
    if (n <=  Size(0))
      return first;
    else
      return boost::simd::copy(first, first+n, out);
  }

} }

#endif
