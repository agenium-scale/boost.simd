//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ANY_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ANY_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns @ref True if at least one element of the input vector is non zero.

    @par Semantic:

    For every parameter of type T

    @code
    logical<scalar_of_t<T>> r = any(x);
    @endcode

    is similar to:

    @code
    logical<scalar_of_t<T>> r = False;
    for(result_type i = 0; i != cardinal_of<T>; ++i)
      if (x[i]) {r =  True; break; }
    @endcode


    @return a value of the scalar type associated to the parameter

**/
  template<typename T> auto any(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Returns @ref True if at least one element of the input vector is non zero.


      Function object tied to simd::any

      @see simd::any
    **/
    const boost::dispatch::functor<tag::any_> any = {};
  }
} }
#endif

#include <boost/simd/function/scalar/any.hpp>
#include <boost/simd/function/simd/any.hpp>

#endif
