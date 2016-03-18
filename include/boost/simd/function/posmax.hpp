//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_POSMAX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POSMAX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing posmax capabilities

    Returns the index of the first occurence of greatest element of the SIMD vector

    @par Semantic:

    For every parameter of type T

    @code
    std::size_t r = posmax(x);
    @endcode

    is similar to:

    @code
      scalar_of_t<T> m =  maximum(x);
      std::size_t r;
      for(std::size_t i=0; i < cardinal_of<T>; i++)
        if (m == x[i]) { r = i;  break; }
    @endcode

  **/
  const boost::dispatch::functor<tag::posmax_> posmax = {};
} }
#endif

#include <boost/simd/function/scalar/posmax.hpp>
#include <boost/simd/function/simd/posmax.hpp>

#endif
