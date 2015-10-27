//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_GREATER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_GREATER_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True if a0 is not greater than a1 else returns False.

    @par Semantic:

    @code
    logical<T> r = is_not_greater(a0,a1);
    @endcode

    is similar to:

    @code
    logical<T> r = ;
    @endcode

    @par Note:

    Due to existence of nan, this is not equivalent to @c is_less_equal(a0, a1)
    for floating types

    @par Alias:

    @c is_ngt



    @return a logical value

**/
  template<typename T> auto is_not_greater(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-predicates

      Function object tied to simd::is_not_greater

      @see simd::is_not_greater
    **/
    const boost::dispatch::functor<tag::is_not_greater_> is_not_greater = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_not_greater.hpp>
#include <boost/simd/arch/common/scalar/function/is_not_greater.hpp>
//#include <boost/simd/arch/common/function/simd/is_not_greater.hpp>

#endif
