//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINCOSD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINCOSD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-trigonometric
    Function object implementing sincosd capabilities

    Computes simultaneously the sind and cosd of the input

    @par Semantic:

    @code
    T s, c;
    std::tie(s, c) = sincosd(x);
    @endcode

    is similar to:

    @code
    T s =  sind(x);
    T c =  cosd(x);
    @endcode

  **/
  const boost::dispatch::functor<tag::sincosd_> sincosd = {};
} }
#endif

#include <boost/simd/function/scalar/sincosd.hpp>
#include <boost/simd/function/simd/sincosd.hpp>

#endif
