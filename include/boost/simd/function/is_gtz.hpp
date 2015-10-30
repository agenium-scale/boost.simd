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
#ifndef BOOST_SIMD_FUNCTION_IS_GTZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_GTZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True or False according x is greater than @ref Zero or not.

    @par Semantic:

    @code
    as_logical_t<T> r = is_gtz(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = x > 0;
    @endcode


    @return a logical value

**/
  template<typename T> auto is_gtz(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True or False according x is greater than @ref Zero or not.


      Function object tied to simd::is_gt

z      @see simd::is_gt
z    **/
    const boost::dispatch::functor<tag::is_gtz_> is_gtz = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_gtz.hpp>
#include <boost/simd/arch/common/scalar/function/is_gtz.hpp>
#include <boost/simd/function/simd/is_gtz.hpp>

#endif
