//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SBITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SBITS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the signed integer value which has the bit pattern of the input

    @par Semantic:

    @code
    T r = sbits(x);
    @endcode

    is similar to:

    @code
    T r = bitwise_cast<as_integer_t<T,signed>>(x);
    @endcode


    @return a value of same type as the input

**/
  template<typename T> auto sbits(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns the signed integer value which has the bit pattern of the input


      Function object tied to simd::sbits

      @see simd::sbits
    **/
    const boost::dispatch::functor<tag::sbits_> sbits = {};
  }
} }
#endif

#include <boost/simd/function/definition/sbits.hpp>
#include <boost/simd/arch/common/scalar/function/sbits.hpp>
#include <boost/simd/function/simd/sbits.hpp>

#endif
