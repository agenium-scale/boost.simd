//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITFLOATING_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITFLOATING_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Transform a pattern of bits stored in an integer value
    in a floating point with different formulas according to
    the integer sign (converse of bitinteger)

    @par Semantic:

    @code
    as_floating<T> r = bitfloating(x);
    @endcode

    is similar to:

    @code
    as_floating<T> r =  bitwise_cast<as_floating<T>>(x >=0 ? x : Signmask<T>()-x);
    @endcode

    @return a value of the floating type associated to the input

**/
  template<typename T> auto bitfloating(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Transform a pattern of bits stored in an integer value
      in a floating point with different formulas according to
      the integer sign (converse of bitinteger)


      Function object tied to simd::bitfloating

      @see simd::bitfloating
    **/
    const boost::dispatch::functor<tag::bitfloating_> bitfloating = {};
  }
} }
#endif

#include <boost/simd/function/definition/bitfloating.hpp>
#include <boost/simd/arch/common/scalar/function/bitfloating.hpp>
//#include <boost/simd/arch/common/function/simd/bitfloating.hpp>

#endif
