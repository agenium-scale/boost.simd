//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MAXLEFTSHIFT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MAXLEFTSHIFT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the number of bits-1 of the scalar component of the value type

    @par Semantic:

    @code
    as_integer<T> r = Maxleftshift<T>();
    @endcode

    is similar to:

    @code
    as_integer<T> r =size(scalar_of<T>)*8-1;
    @endcode

    @return The Maxleftshift constant for the proper type
  **/
  template<typename T> T Maxleftshift();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant
      Generate the  constant maxleftshift.

      @return The Maxleftshift constant for the proper type
    **/
    const boost::dispatch::functor<tag::maxleftshift_> maxleftshift = {};
  }
} }
#endif

#include <boost/simd/constant/definition/maxleftshift.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
