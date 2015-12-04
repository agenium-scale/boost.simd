//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_L_NOTAND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_L_NOTAND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    return the logical and of the negation of the first parameter and the second parameter

    The operands must share the same @ref cardinal_of value.

    The result type is logical type associated to the first parameter.

    This is a convenient alias of @ref logical_notand
**/
  template<typename T1, typename T2> auto l_notand(T1 const& x, T2 const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      return the logical and of the negation of the first parameter and the second parameter

      Function object tied to simd::l_notand

      @see simd::l_notand
    **/
    const boost::dispatch::functor<tag::l_notand_> l_notand = {};
  }
} }
#endif

#include <boost/simd/function/definition/l_notand.hpp>
#include <boost/simd/arch/common/scalar/function/logical_notand.hpp>
#include <boost/simd/function/simd/l_notand.hpp>

#endif
