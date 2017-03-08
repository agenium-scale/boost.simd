//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_FOR_EACH_N_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_FOR_EACH_N_HPP_INCLUDED

#include <boost/simd/range/segmented_output_range.hpp>
#include <boost/simd/pack.hpp>
#include <algorithm>

namespace boost { namespace simd
{
  /*!
    @ingroup group-std

    Applies the given function @c f to the Contiguous Range @range{first, first+n}.

    @param first  Beginning of the range of elements
    @param n      the number of elements to apply the function to
    @param f      unary operation function object that will be applied and return value.

    @par Requirement

      - @c first , @c last and @c out must be pointer to type which can be used within
        boost::simd::pack.
      - @c f must be a polymorphic unary function object, i.e callable on generic types.
        Its return value, if any, is ignored.

      - @c f may modify the elements of the range through the dereferenced iterator.
        If f returns a result, the result is ignored.
        If n is less than zero, the behavior is undefined.

    @par Example:

      @snippet for_each_n.cpp for_each_n

    @par Possible output:

      @snippet for_each_n.txt for_each_n

    @return f.
  **/
  template<typename T, typename UnOp>
  UnOp for_each_n(T * first, Size n, UnOp f)
  {
    return for_each(first, first+n, f);
  }

} }

#endif
