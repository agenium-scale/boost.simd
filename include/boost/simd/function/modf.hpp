//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MODF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MODF_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing modf capabilities

    Computes the integer and  fractional parts of the input

    @par Semantic:

    @code
    T t = modf(x, f);
    @endcode

    is similar to:

    @code
    T t = trunc(x);
    T f = frac(x);
    @endcode

    The following call can also be used

    @code
    std::pair<T,T> p = modf(x);
    @endcode

    @see frac,  trunc

  **/
  const boost::dispatch::functor<tag::modf_> modf = {};
} }
#endif

#include <boost/simd/function/scalar/modf.hpp>
#include <boost/simd/function/simd/modf.hpp>

#endif
