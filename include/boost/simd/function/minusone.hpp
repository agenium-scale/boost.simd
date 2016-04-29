//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINUSONE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINUSONE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing minusone capabilities

    Return the entry minus one.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = minusone(x);
    @endcode

    is similar to:

    @code
    T r = x-One<T>();
    @endcode

  **/
  const boost::dispatch::functor<tag::minusone_> minusone = {};
} }
#endif

#include <boost/simd/function/scalar/minusone.hpp>
#include <boost/simd/function/simd/minusone.hpp>

#endif
