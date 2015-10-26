//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_NOTAND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_NOTAND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    return the logical and of the negation of the first parameter and the second parameter
    the result type is logical type associated to the first parameter

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    as_logical<T0> r = logical_notand(a0,a1);
    @endcode

    is similar to:

    @code
    as_logical<T0> r = !a0 && a1;
    @endcode

    @par Alias:
    @c l_notand



    @return a value of the logical type asssociated to the first parameter

**/
  template<typename T> auto logical_notand(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::logical_notand

      @see simd::logical_notand
    **/
    const boost::dispatch::functor<tag::logical_notand_> logical_notand = {};
  }
} }
#endif

#include <boost/simd/function/definition/logical_notand.hpp>
#include <boost/simd/arch/common/scalar/function/logical_notand.hpp>
//#include <boost/simd/arch/common/function/simd/logical_notand.hpp>

#endif
