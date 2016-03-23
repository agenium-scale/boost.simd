//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEGATENZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGATENZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing negatenz capabilities

    Returns x multiplied by the @ref signnz of y.

    The result is unspecified if y is @ref Nan

    @par Semantic:

    @code
    T r = negatenz(x,y);
    @endcode

    is similar to:

    @code
    T r = x*signnz(y);
    @endcode

    @par Note
    If x is  null the result is @ref \f$\pm0\f$. Take care that negatenz distinguish
    between the signs of T(0) and -T(0) when T is a floating type.

    @see negatenz, Mzero, is_positive, is_negative

  **/
  const boost::dispatch::functor<tag::negatenz_> negatenz = {};
} }
#endif

#include <boost/simd/function/scalar/negatenz.hpp>
#include <boost/simd/function/simd/negatenz.hpp>

#endif
