//==================================================================================================
/*!
  @file

  @copyright 2012-2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIST_S_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIST_S_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the (saturated) absolute value of the difference of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = dist_s(x, y);
    @endcode

    is similar to:

    @code
    T r = abss(x-y);
    @endcode

    @par Note

    The result is never stricly negative moreover it satisfies the predicate

     @code  is_positive(dist(x, y)) || is_unord(x, y) @endcode


    For floating, it can of course be @ref Nan.

    @see  saturated_, abs_s, ulpdist

    @return      a value of the same type as the input.


**/
  template<typename T> auto dist_s(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the (saturated) absolute value of the difference of its parameters.


      Function object tied to simd::dist_s

      @see simd::dist_s
    **/
    const boost::dispatch::functor<tag::dist_s_> dist_s = {};
  }
} }
#endif

#include <boost/simd/function/scalar/dist_s.hpp>
#include <boost/simd/function/simd/dist_s.hpp>

#endif
