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
#ifndef BOOST_SIMD_FUNCTION_L_ORNOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_L_ORNOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    return the logical or of the first parameter and of the negation the second parameter.

    The operands must share the same @ref cardinal_of value.

    The result type is logical type associated to the first parameter.

    This is a convenient alias of @ref logical_ornot
**/
  template<typename T1, typename T2> auto l_ornot(T1 const& x, T2 const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      return the logical or of the first parameter and of the negation the second parameter.


      Function object tied to simd::l_ornot

      @see simd::l_ornot
    **/
    const boost::dispatch::functor<tag::l_ornot_> l_ornot = {};
  }
} }
#endif

#include <boost/simd/function/definition/l_ornot.hpp>
#include <boost/simd/arch/common/scalar/function/logical_ornot.hpp>
#include <boost/simd/function/simd/l_ornot.hpp>

#endif
