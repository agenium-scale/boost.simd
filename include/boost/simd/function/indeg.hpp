//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INDEG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INDEG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing indeg capabilities

    convert radian to degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = indeg(x);
    @endcode

    is similar to:

    @code
    T r = Radindeg<T>()*x;
    @endcode

    @see  inrad, Radindeg, Radindegr, Deginrad

  **/
  const boost::dispatch::functor<tag::indeg_> indeg = {};
} }
#endif

#include <boost/simd/function/scalar/indeg.hpp>
#include <boost/simd/function/simd/indeg.hpp>

#endif
