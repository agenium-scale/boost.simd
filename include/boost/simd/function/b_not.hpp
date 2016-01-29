//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_B_NOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_B_NOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    return the bitwise b_not of the entry
    Infix notation can be used with operator '~'

    This is a convenient alias of @ref complement
**/
  template<typename T> auto b_not(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      return the bitwise b_not of the entry
      Infix notation can be used with operator '~'


      Function object tied to simd::b_not

      @see simd::b_not
    **/
    const boost::dispatch::functor<tag::b_not_> b_not = {};
  }
} }
#endif

#include <boost/simd/function/scalar/complement.hpp>
#include <boost/simd/function/simd/b_not.hpp>

#endif
