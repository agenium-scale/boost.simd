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
#ifndef BOOST_SIMD_FUNCTION_L_AND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_L_AND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    return the logical and of the two parameters.

    The operands must share the same @ref cardinal_of value.

    Infix notation can be used with operator '&&'.

    This is a convenient alias of @ref logical_and
**/
  template<typename T1, typename T2> auto l_and(T1 const& x, T2 const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      return the logical and of the two parameters.


      Function object tied to simd::l_and

      @see simd::l_and
    **/
    const boost::dispatch::functor<tag::l_and_> l_and = {};
  }
} }
#endif

#include <boost/simd/function/definition/l_and.hpp>
#include <boost/simd/arch/common/scalar/function/logical_and.hpp>
#include <boost/simd/function/simd/l_and.hpp>

#endif
