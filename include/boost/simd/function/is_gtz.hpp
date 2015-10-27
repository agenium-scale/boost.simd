//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_GTZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_GTZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True or False according a0 is greater than zero or not.

    @par Semantic:

    @code
    logical<T> r = is_gtz(a0);
    @endcode

    is similar to:

    @code
    logical<T> r = a0 > 0;
    @endcode


    @return a logical value

**/
  template<typename T> auto is_gtz(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-predicates

      Function object tied to simd::is_gt

z      @see simd::is_gt
z    **/
    const boost::dispatch::functor<tag::is_gtz_> is_gtz = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_gtz.hpp>
#include <boost/simd/arch/common/scalar/function/is_gtz.hpp>
//#include <boost/simd/arch/common/function/simd/is_gtz.hpp>

#endif
