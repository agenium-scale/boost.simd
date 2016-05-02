//==================================================================================================
/*!
  @file

  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IDIV_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IDIV_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-operator

    Perform the quotient of two parameters of the same type with or without options to return
    an integer result of the type associated to the first parameter.

    @par Semantic

    For any value @c a and @c b of type @c T,

    @code
    T r = idiv(a, b{, option});
    @endcode

    returns the quotient of @c a by @c b according to the option

    if there is no option the call is equivalent to divfix(a, b),  else
    option can be ceil_(), floor_(), fix_(), round_(), round2even_() and provide the
    same result as idivceil(a, b), idivfloor(a, b), idivfix(a, b), idivround(a, b)

    @param a First  parameter of the quotient
    @param b Second parameter of the quotient
    @param option is the option

    @return The quotient of the two parameters.
  **/
  template<typename T> auto idiv(T const& a, T const& b);

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      Perform the quotient of two parameters of the same type.


      Function object tied to boost::simd::idiv

      @see boost::simd::idiv
    **/
    const boost::dispatch::functor<tag::idiv_> idiv = {};
  }
} }
#endif

#include <boost/simd/function/scalar/idiv.hpp>


#endif
