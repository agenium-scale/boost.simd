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
#ifndef BOOST_SIMD_FUNCTION_MASK2LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MASK2LOGICAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    The function converts an arithmetic mask where each element is
    Zero or Allbits to a logical value.

    If it is not the case this function asserts.

    @par Semantic:

    For every parameters of types respectively T0:

    @code
    as_logical_t<T0> r = mask2logical(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T0> r = logical(x);
    @endcode


    @return a value of the logical type associated to the parameter

**/
  template<typename T> auto mask2logical(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      The function converts an arithmetic mask where each element is
      Zero or Allbits to a logical value.


      Function object tied to simd::mask2logical

      @see simd::mask2logical
    **/
    const boost::dispatch::functor<tag::mask2logical_> mask2logical = {};
  }
} }
#endif

#include <boost/simd/function/definition/mask2logical.hpp>
#include <boost/simd/arch/common/generic/function/mask2logical.hpp>
//#include <boost/simd/arch/common/function/simd/mask2logical.hpp>

#endif
