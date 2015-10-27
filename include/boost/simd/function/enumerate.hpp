//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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

    @brief Linear enumeration of value

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

    @tparam T Result type of the enumeration

                to 0.

                equals to 1.

    @return A SIMD register of scalar type @c T

**/
  template<typename T> auto enumerate(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::enumerate

      @see simd::enumerate
    **/
    const boost::dispatch::functor<tag::enumerate_> enumerate = {};
  }
} }
#endif

#include <boost/simd/function/definition/enumerate.hpp>
#include <boost/simd/arch/common/scalar/function/enumerate.hpp>
//#include <boost/simd/arch/common/function/simd/enumerate.hpp>

#endif
