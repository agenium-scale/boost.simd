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
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_NOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_NOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    return the logical negation of the parameter,
    i.e. True or False of the logical type associated entry type according that
    the input is zero or non zero (False or True).

    Infix notation can be used with operator '!'

    @par Semantic:

    For every parameter of type T0

    @code
    as_logical_t<T0> r = logical_not(a0);
    @endcode

    is similar to:

    @code
    as_logical_t<T0> r =!a0;
    @endcode

    @par Alias:
    @c l_not

    @see  logical_or, logical_xor, logical_notand,
    logical_andnot, logical_notor, logical_ornot

    @return a value of the logical type associated to the parameter

**/
  template<typename T> auto logical_not(T const& a0) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::logical_not

      @see simd::logical_not
    **/
    const boost::dispatch::functor<tag::logical_not_> logical_not = {};
  }
} }
#endif

#include <boost/simd/function/definition/logical_not.hpp>
#include <boost/simd/arch/common/scalar/function/logical_not.hpp>
//#include <boost/simd/arch/common/function/simd/logical_not.hpp>

#endif
