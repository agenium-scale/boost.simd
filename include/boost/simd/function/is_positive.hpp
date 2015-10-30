//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_POSITIVE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_POSITIVE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True if x is positive else False.

    This function differs from @ref is_gtz for floating point arguments,
    because @ref Zero is positive but not greater than 0, and @ref Mzero is
    not positive and not greater than 0, It's probably @ref is_gtz that
    you want.


    @par Semantic:

    @code
    as_logical_t<T> r = is_positive(x);
    @endcode

    is similar to:

    @code
    if T is signed
      as_logical_t<T> r = @ref bitofsign(x) == 0;
    else
      as_logical_t<T> r = @ref True;
    @endcode


    @par Note:

    Mzero is the floating point 'minus zero',
    i.e. all bits are @ref Zero but the sign bit.
    Such a value is treated as @ref Zero by ieee standards.

    behaviour of is_positive on @ref Nan is undefined.

    @return a logical value

**/
  template<typename T> auto is_positive(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True if x is positive else False.


      Function object tied to simd::is_positive

      @see simd::is_positive
    **/
    const boost::dispatch::functor<tag::is_positive_> is_positive = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_positive.hpp>
#include <boost/simd/arch/common/scalar/function/is_positive.hpp>
#include <boost/simd/function/simd/is_positive.hpp>

#endif
