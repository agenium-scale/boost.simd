//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_PROD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_PROD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns the product of the elements of the SIMD vector

    @par Semantic:

    For every parameter of type T

    @code
    scalar<T> r = prod(x);
    @endcode

    is similar to:

    @code
    scalar<T> r = One;
    for(result_type i = 0; i != cardinal_of<T>; ++i)
      r *= x[i];
    @endcode


    @return a value of the scalar type associated to the parameter

**/
  template<typename T> auto prod(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Returns the product of the elements of the SIMD vector


      Function object tied to simd::prod

      @see simd::prod
    **/
    const boost::dispatch::functor<tag::prod_> prod = {};
  }
} }
#endif

#include <boost/simd/function/definition/prod.hpp>
#include <boost/simd/arch/common/scalar/function/prod.hpp>
//#include <boost/simd/arch/common/function/simd/prod.hpp>

#endif
