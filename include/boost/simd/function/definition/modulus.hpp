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
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_MODULUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_MODULUS_HPP_INCLUDED

#include <boost/simd/function/definition/abs.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
#if defined(DOXYGEN_ONLY)
  /*!
  @ingroup group-arithmetic

    Computes the absolute value of its parameter.

    This is an alias of function abs.

    @Note abs is a current function name and sometimes a C
    version can be an unwanted
    concurrent of @c boost::simd::abs.  Using @c modulus instead
    can circumvent this problem.

    @see abs
  **/
  template<typename T> auto modulus(T const& x);
#endif
  namespace tag
  {
    using modulus_ = abs_;
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::modulus_,modulus);
  }
  BOOST_DISPATCH_FUNCTION_DEFINITION(tag::modulus_,modulus);
} }

#endif
