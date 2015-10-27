//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INBTRUE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INBTRUE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-reduction

    Returns the number of non zero elements of the input SIMD vector.

    @par Semantic:

    For every parameter of type T0

    @code
    size_t r = inbtrue(a0);
    @endcode

    is similar to:

    @code
    size_t r = sum(if_one_else_zero(a0));
    @endcode


    @return a size_t value

**/
  template<typename T> auto inbtrue(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-reduction

      Function object tied to simd::inbtrue

      @see simd::inbtrue
    **/
    const boost::dispatch::functor<tag::inbtrue_> inbtrue = {};
  }
} }
#endif

#include <boost/simd/function/definition/inbtrue.hpp>
#include <boost/simd/arch/common/scalar/function/inbtrue.hpp>
//#include <boost/simd/arch/common/function/simd/inbtrue.hpp>

#endif
