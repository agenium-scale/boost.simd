//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITINTEGER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITINTEGER_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Transforms a floating point value in a pattern of bits
    stored in an integer with different formulas according to
    the floating point @ref bitofsign (the converse of @ref bitfloating)

    @par Semantic:

    @code
     as_integer_t<T> r = bitinteger(x);
    @endcode

    is similar to:

    @code
      as_integer_t<T> r =
         (is_positive(x) ?
           bitwise_cast<as_integer_t<T>>(x) :
           Signmask<as_integer_t<T>>()-bitwise_cast<as_integer_t<T>>(x);
    @endcode

    @par Note:
    This is an utility function related to the computation of floating
    successors or predecessors

    @see next, prev, successor,  predecessor,  nextafter

    @return a value of the integer type associated to the input

**/
  template<typename T> auto bitinteger(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Transforms a floating point value in a pattern of bits
      stored in an integer with different formulas according to
      the floating point sign (the converse of bitfloating)


      Function object tied to simd::bitinteger

      @see simd::bitinteger
    **/
    const boost::dispatch::functor<tag::bitinteger_> bitinteger = {};
  }
} }
#endif

#include <boost/simd/function/scalar/bitinteger.hpp>
#include <boost/simd/function/simd/bitinteger.hpp>

#endif
