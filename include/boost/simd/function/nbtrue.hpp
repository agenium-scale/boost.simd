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
#ifndef BOOST_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns the number of non zero elements of the input SIMD vector.

    @par Semantic:

    For every parameter of type T

    @code
    T r = nbtrue(x);
    @endcode

    is similar to:

    @code
    T r = sum(if_one_else_zero(x));
    @endcode


    @return a value of the scalar type associated to the parameter

**/
  template<typename T> auto nbtrue(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-reduction

      Returns the number of non zero elements of the input SIMD vector.


      Function object tied to simd::nbtrue

      @see simd::nbtrue
    **/
    const boost::dispatch::functor<tag::nbtrue_> nbtrue = {};
  }
} }
#endif

#include <boost/simd/function/definition/nbtrue.hpp>
#include <boost/simd/arch/common/scalar/function/nbtrue.hpp>
//#include <boost/simd/arch/common/function/simd/nbtrue.hpp>

#endif
