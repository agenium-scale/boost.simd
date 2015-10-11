//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_ONEOTWOEPS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_ONEOTWOEPS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate \f$1/(2\epsilon)\f$

    @par Semantic:

    @code
    T r = Oneotwoeps<T>();
    @endcode

    is similar to:

    @code
    if T is integral
      r = T(0)
    else if T is double
      r =  pow(2.0, 52);
    else if T is float
      r =  pow(2.0f, 22);
    @endcode

    @return The Oneotwoeps constant for the proper type
  **/
  template<typename T> T Oneotwoeps();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant oneotwoeps.

      @return The Oneotwoeps constant for the proper type
    **/
    const boost::dispatch::functor<tag::oneotwoeps_> oneotwoeps = {};
  }
} }
#endif

#include <boost/simd/constant/definition/oneotwoeps.hpp>
#include <boost/simd/arch/common/constant/scalar/constant_value.hpp>

#endif
