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
#ifndef BOOST_SIMD_FUNCTION_L_ANDNOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_L_ANDNOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    return the logical and of the first parameter and of the negation the second parameter.

    The operands must share the same @ref cardinal_of value.

    The result type is logical type associated to the first parameter.

    This is a convenient alias of @ref logical_andnot
**/
 template<typename T1, typename T2> auto l_andnot(T1 const& x, T2 const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      return the logical and of the first parameter and of the negation the second parameter.

      Function object tied to simd::l_andnot

      @see simd::l_andnot
    **/
    const boost::dispatch::functor<tag::l_andnot_> l_andnot = {};
  }
} }
#endif

#include <boost/simd/function/definition/l_andnot.hpp>
#include <boost/simd/arch/common/scalar/function/logical_andnot.hpp>
#include <boost/simd/function/simd/l_andnot.hpp>

#endif
