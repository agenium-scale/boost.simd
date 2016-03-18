//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ENUMERATE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ENUMERATE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-swar
    Function object implementing enumerate capabilities

    Linear enumeration of value

    Return a SIMD register containing a linear enumeration of value defined
    by a seed value and a step.

    @par Semantic:

    For any given SIMD type @c T, and any value @c seed and @c step of a scalar
    type @c S, the following  code :

    @code
    T r = enumerate<T>(seed, step);
    @endcode

    is equivalent to

    @code
    T r = make<T>(seed, seed + step, ... ,  seed + (N-1)*step);
    @endcode

    where @c N is the equal to <tt>cardinal_of<T>::value</tt>.

    For any given SIMD type @c T, and any value @c seed and @c step of a SIMD
    type @c S, the following  code :

    @code
    T r = enumerate<T>(seed, step);
    @endcode

    is equivalent to

    @code
    T r = splat<T>(seed) + splat<T>(step)*enumerate<T>();
    @endcode

  **/
  const boost::dispatch::functor<tag::enumerate_> enumerate = {};
} }
#endif

#include <boost/simd/function/scalar/enumerate.hpp>
#include <boost/simd/function/simd/enumerate.hpp>

#endif
