//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    returns the dot product of the two vector arguments

    @par Semantic:

    For every parameters of type T:

    @code
    scalar_of_t<T> r = dot(x,y);
    @endcode

    is similar to:

    @code
    scalar_of_t<T> r = sum(x*conj(y));
    @endcode



    @return a value of the scalar type associated to the parameters

**/
  template<typename T> auto dot(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      returns the dot product of the two vector arguments


      Function object tied to simd::dot

      @see simd::dot
    **/
    const boost::dispatch::functor<tag::dot_> dot = {};
  }
} }
#endif

#include <boost/simd/function/definition/dot.hpp>
#include <boost/simd/arch/common/scalar/function/dot.hpp>
#include <boost/simd/function/simd/dot.hpp>

#endif
