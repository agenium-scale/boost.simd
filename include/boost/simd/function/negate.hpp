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
#ifndef BOOST_SIMD_FUNCTION_NEGATE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGATE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Retuns the first element multiplied by the @ref sign of the second.

    @par Semantic:

    @code
    T r = negate(x,y);
    @endcode

    is similar to:

    @code
    T r =  x*sign(y);
    @endcode

    @par Note
    If y is @ref Zero the result is zero. If you want to avoid that use
    @ref negatenz or @ref copysign.

    @see sign, negatenz, copysign,  Mzero,  is_positive, is_negative

    @return a value of same type as the inputs

**/
  template<typename T> auto negate(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Retuns the first element multiplied by the sign of the second.


      Function object tied to simd::negate

      @see simd::negate
    **/
    const boost::dispatch::functor<tag::negate_> negate = {};
  }
} }
#endif

#include <boost/simd/function/definition/negate.hpp>
#include <boost/simd/arch/common/scalar/function/negate.hpp>
#include <boost/simd/function/simd/negate.hpp>

#endif
