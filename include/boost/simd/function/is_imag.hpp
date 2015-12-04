//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_IMAG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_IMAG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True or @ref False according x is pure imaginary or not.
    For non complex numbers it is same as to be zero

    @par Semantic:

    @code
    as_logical_t<T> r = is_imag(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = x == 0;
    @endcode


    @return a logical value

**/
  template<typename T> auto is_imag(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True or @ref False according x is pure imaginary or not.
      For non complex numbers it is same as to be zero


      Function object tied to simd::is_imag

      @see simd::is_imag
    **/
    const boost::dispatch::functor<tag::is_imag_> is_imag = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_imag.hpp>
#include <boost/simd/arch/common/scalar/function/is_imag.hpp>
#include <boost/simd/arch/common/generic/function/is_imag.hpp>
#include <boost/simd/function/simd/is_imag.hpp>

#endif
