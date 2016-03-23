//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMMA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMMA_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-operator
    Function object implementing comma capabilities

    TODO Put description here

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    T0 r = comma(x,y);
    @endcode

    is similar to:

    @code
    T0 r = (x, y);
    @endcode

  **/
  const boost::dispatch::functor<tag::comma_> comma = {};
} }
#endif

#include <boost/simd/function/scalar/comma.hpp>
#include <boost/simd/function/simd/comma.hpp>

#endif
