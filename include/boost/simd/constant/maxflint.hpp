//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MAXFLINT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MAXFLINT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the least integer value which is exactly
    representable in floating point numbers and
    equal to its integral successor.

    All floating numbers greater than Maxflint are integral.

    @par Semantic:

    @code
    T r = Maxflint<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r = 9007199254740992.0
    else if T is float
      r = 16777216.0f
    @endcode


    @return The Maxflint constant for the proper type
  **/
  template<typename T> T Maxflint();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant
      Generate the  constant maxflint.

      @return The Maxflint constant for the proper type
    **/
    const boost::dispatch::functor<tag::maxflint_> maxflint = {};
  }
} }
#endif

#include <boost/simd/constant/definition/maxflint.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
