//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIVIDES_INCLUDED
#define BOOST_SIMD_FUNCTION_DIVIDES_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-operator

    Perform the quotient of two parameters of the same type.

    @par Semantic

    For any value @c a and @c b of type @c T,

    @code
    T r = divides(a,b);
    @endcode

    returns the quotient of @c a by @c b

    @param a First  parameter of the quotient
    @param b Second parameter of the quotient

    @return The quotient of the two parameters.
  **/
  template<typename T> auto divides(T const& a, T const& b);

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      Perform the quotient of two parameters of the same type.


      Function object tied to boost::simd::divides

      @see boost::simd::divides
    **/
    const boost::dispatch::functor<tag::divides_> divides = {};
  }
} }
#endif

#include <boost/simd/function/scalar/divides.hpp>
#include <boost/simd/function/scalar/divides.hpp>
#include <boost/simd/function/simd/divides.hpp>

#endif
