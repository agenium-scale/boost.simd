//==================================================================================================
/*!
  @file

  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIV_INCLUDED
#define BOOST_SIMD_FUNCTION_DIV_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-operator

    Perform the quotient of two parameters of the same type with or without options.

    @par Semantic

    For any value @c a and @c b of type @c T,

    @code
    T r = div(a, b{, option});
    @endcode

    returns the quotient of @c a by @c b according to the option

    if there is no option the call is equivalent to divides(a, b),  else
    option can be ceil_(), floor_(), fix_(), round_(), round2even_() and provide the
    sme result as divceil(a, b), divfloor(a, b), divfix(a, b), divround(a, b)

    @param a First  parameter of the quotient
    @param b Second parameter of the quotient
    @param option is the option

    @return The quotient of the two parameters.
  **/
  template<typename T> auto div(T const& a, T const& b);

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      Perform the quotient of two parameters of the same type.


      Function object tied to boost::simd::div

      @see boost::simd::div
    **/
    const boost::dispatch::functor<tag::div_> div = {};
  }
} }
#endif

#include <boost/simd/function/scalar/div.hpp>


#endif
