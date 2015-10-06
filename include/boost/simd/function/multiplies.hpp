//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MULTIPLIES_INCLUDED
#define BOOST_SIMD_FUNCTION_MULTIPLIES_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-operator

    Perform the product of two parameters of the same type.

    @par Semantic

    For any value @c a and @c b of type @c T,

    @code
    T x = multiplies(a,b);
    @endcode

    returns the product of @c a and @c b

    @param a0 First  parameter of the product
    @param a1 Second parameter of the product

    @return The product of the two parameters.
  **/
  template<typename T> auto multiplies(T const& a0, T const& a1);

  namespace functional
  {
    /*!
      @ingroup group-operator

      Function object tied to boost::simd::multiplies

      @see boost::simd::multiplies
    **/
    const boost::dispatch::functor<tag::multiplies_> multiplies = {};
  }
} }
#endif

#include <boost/simd/function/definition/multiplies.hpp>
#include <boost/simd/arch/common/function/scalar/multiplies.hpp>
//#include <boost/simd/arch/common/function/simd/multiplies.hpp>

#endif
