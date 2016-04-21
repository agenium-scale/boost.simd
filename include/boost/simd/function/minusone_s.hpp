//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINUSONE_S_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINUSONE_S_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing minusone_s capabilities

    Return the entry minus one, saturated in the entry type.
    If @c x is not @ref Nan, @c minusone_s(x) is less or equal to x.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = minusone_s(x);
    @endcode

    is similar to:

    @code
    T r = (x > Valmin) ? x-1 : x;
    @endcode

  **/
  const boost::dispatch::functor<tag::minusone_s_> minusone_s = {};
} }
#endif

#include <boost/simd/function/scalar/minusone_s.hpp>
#include <boost/simd/function/simd/minusone_s.hpp>

#endif
