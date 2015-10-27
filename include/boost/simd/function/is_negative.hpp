//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NEGATIVE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NEGATIVE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True if a0 is negative else False.

    This function differs from is_ltz from floating point argument,
    because Mzero is negative but not less than zero.  and Mzero is
    not positive and not greater than zero, It's probably is_ltz that
    you want.

    @par Semantic:

    @code
    logical<T> r = is_negative(a0);
    @endcode

    is similar to:

    @code
    if T is signed
      logical<T> r = bitofsign(a0) == 1;
    else
      logical<T> r = False;
    @endcode

    @par Note:

    Mzero is the floating point 'minus zero',
    i.e. all bits are zero but the sign bit.
    Such a value is treated as zero by ieee standards.


    @return a logical value

**/
  template<typename T> auto is_negative(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-predicates

      Function object tied to simd::is_negative

      @see simd::is_negative
    **/
    const boost::dispatch::functor<tag::is_negative_> is_negative = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_negative.hpp>
#include <boost/simd/arch/common/scalar/function/is_negative.hpp>
//#include <boost/simd/arch/common/function/simd/is_negative.hpp>

#endif
