//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIVIDES_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIVIDES_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-operator
    Function object implementing divides capabilities

    Perform the quotient of two parameters of the same type.

    @par Semantic

    For any value @c a and @c b of type @c T,

    @code
    T r = divides(a,b);
    @endcode

    returns the quotient of @c a by @c b

  **/
  const boost::dispatch::functor<tag::divides_> divides = {};
} }
#endif

#include <boost/simd/function/scalar/divides.hpp>
#include <boost/simd/function/scalar/divides.hpp>
#include <boost/simd/function/simd/divides.hpp>

#endif
