//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINUS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-operator

    Perform the difference of two parameters of the same type.

    @par Semantic

    For any value @c a and @c b of type @c T,

    @code
    T x = minus(a,b);
    @endcode

    returns the difference of @c a and @c b

    @param x First  parameter of the difference
    @param y Second parameter of the difference

    @return The difference of the two parameters.
  **/
  template<typename T> auto minus(T const& x, T const& y);

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      Perform the difference of two parameters of the same type.


      Function object tied to boost::simd::minus

      @see boost::simd::minus
    **/
    const boost::dispatch::functor<tag::minus_> minus = {};
  }
} }
#endif

#include <boost/simd/function/definition/minus.hpp>
#include <boost/simd/arch/common/scalar/function/minus.hpp>
#include <boost/simd/function/simd/minus.hpp>

#endif
