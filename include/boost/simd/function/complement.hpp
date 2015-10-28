//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMPLEMENT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPLEMENT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    return the bitwise complement of the entry
    Infix notation can be used with operator '~'

    @par Semantic:

    For every parameter of type T0

    @code
    T0 r = complement(x);
    @endcode

    is similar to:

    @code
    T0 r = ~x;
    @endcode

    @par Alias:
    @c b_not, @c bitwise_not

    @see  bitwise_and, bitwise_or, bitwise_xor, bitwise_notand,
    bitwise_andnot, bitwise_notor, bitwise_ornot

    @return a value of the same type as the second parameter

**/
  template<typename T> auto complement(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      return the bitwise complement of the entry
      Infix notation can be used with operator '~'


      Function object tied to simd::complement

      @see simd::complement
    **/
    const boost::dispatch::functor<tag::complement_> complement = {};
  }
} }
#endif

#include <boost/simd/function/definition/complement.hpp>
#include <boost/simd/arch/common/scalar/function/complement.hpp>
//#include <boost/simd/arch/common/function/simd/complement.hpp>

#endif
