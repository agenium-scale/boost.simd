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
#ifndef BOOST_SIMD_FUNCTION_TWO_PROD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TWO_PROD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    For any two reals @c x and @c y two_prod computes two reals (in an std::pair)
    @c r0 and @c r1 so that:

    @code
    r0 = x * y
    r1 = r0 -(x * y)
    @endcode

    using perfect arithmetic.

    Its main usage is to be able to compute
    sum of reals and the residual error using IEEE 754 arithmetic.


**/
  template<typename T> auto two_prod(T const& x, Tconst& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      For any two reals @c x and @c y two_prod computes two reals (in an std::pair)
      @c r0 and @c r1 so that:


      Function object tied to simd::two_prod

      @see simd::two_prod
    **/
    const boost::dispatch::functor<tag::two_prod_> two_prod = {};
  }
} }
#endif

#include <boost/simd/function/definition/two_prod.hpp>
#include <boost/simd/arch/common/generic/function/two_prod.hpp>
#include <boost/simd/function/simd/two_prod.hpp>

#endif
