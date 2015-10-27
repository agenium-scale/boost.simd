//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_ORD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_ORD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True if neither a0 nor a1 is nan.

    @par Semantic:

    @code
    logical<T> r = is_ord(a0,a1);
    @endcode

    is similar to:

    @code
    logical<T> r = (a0 == a0) && (a1 == a1);
    @endcode



    @return a logical value

**/
  template<typename T> auto is_ord(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-predicates

      Function object tied to simd::is_ord

      @see simd::is_ord
    **/
    const boost::dispatch::functor<tag::is_ord_> is_ord = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_ord.hpp>
#include <boost/simd/arch/common/scalar/function/is_ord.hpp>
//#include <boost/simd/arch/common/function/simd/is_ord.hpp>

#endif
