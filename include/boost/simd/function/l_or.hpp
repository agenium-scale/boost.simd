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
#ifndef BOOST_SIMD_FUNCTION_L_OR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_L_OR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    return the logical or of the two parameters

    The operands must share the same Cardinal_of value.

    Infix notation can be used with operator '||'

    This is a convenient alias of logical_or
**/
  template<typename T1, typename T2> auto l_or(T1 const& x, T2 const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      return the logical or of the two parameters


      Function object tied to simd::l_or

      @see simd::l_or
    **/
    const boost::dispatch::functor<tag::l_or_> l_or = {};
  }
} }
#endif

#include <boost/simd/function/definition/l_or.hpp>
#include <boost/simd/arch/common/scalar/function/logical_or.hpp>
#include <boost/simd/function/simd/l_or.hpp>

#endif
