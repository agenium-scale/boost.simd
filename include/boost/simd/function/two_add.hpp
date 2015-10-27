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
#ifndef BOOST_SIMD_FUNCTION_TWO_ADD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TWO_ADD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    @brief

    For any two reals @c x and @c y two_add computes two reals (in an std::pair)
    @c r0 and @c r1 such that:

    @code
    r0 = x + y
    r1 = r0 -(x + y)
    @endcode

    using perfect arithmetic.

    Its main usage is to be able to compute
    sum of reals and the residual error using IEEE  754 arithmetic.


**/
  template<typename T> auto two_add(T const& x, const T& y) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::two_add

      @see simd::two_add
    **/
    const boost::dispatch::functor<tag::two_add_> two_add = {};
  }
} }
#endif

#include <boost/simd/function/definition/two_add.hpp>
#include <boost/simd/arch/common/generic/function/two_add.hpp>
//#include <boost/simd/arch/common/function/simd/two_add.hpp>

#endif
