//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_FINITE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_FINITE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True if a0 is not inf, -inf or nan, else returns False.

    @par Semantic:

    @code
    logical<T> r = is_finite(a0);
    @endcode

    is similar to:

    @code
    logical<T> r = a0-a0 ==  0;
    @endcode


    @return a logical value

**/
  template<typename T> auto is_finite(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-predicates

      Function object tied to simd::is_finite

      @see simd::is_finite
    **/
    const boost::dispatch::functor<tag::is_finite_> is_finite = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_finite.hpp>
#include <boost/simd/arch/common/scalar/function/is_finite.hpp>
//#include <boost/simd/arch/common/function/simd/is_finite.hpp>

#endif
