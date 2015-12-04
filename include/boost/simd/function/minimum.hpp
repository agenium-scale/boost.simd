//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINIMUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINIMUM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns the least element of the SIMD vector

    @par Semantic:

    For every parameter of type T

    @code
    scalar_of_t<T> r = minimum(x);
    @endcode

    is similar to:

    @code
      scalar_of_t<T> r = Inf;
      for(std::size_t i=0;i<cardinal_of<T>;++i)
        r =  r > x[i] ? x[i] : r;
    @endcode

    @see min, minnummag, minmag

    @return a value of the scalar type associated to the parameter

**/
  template<typename T> auto minimum(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Returns the least element of the SIMD vector


      Function object tied to simd::minimum

      @see simd::minimum
    **/
    const boost::dispatch::functor<tag::minimum_> minimum = {};
  }
} }
#endif

#include <boost/simd/function/definition/minimum.hpp>
#include <boost/simd/arch/common/scalar/function/minimum.hpp>
#include <boost/simd/function/simd/minimum.hpp>

#endif
