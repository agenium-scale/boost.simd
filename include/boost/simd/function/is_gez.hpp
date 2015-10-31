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
#ifndef BOOST_SIMD_FUNCTION_IS_GEZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_GEZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True or @ref False according x is greater or equal to @ref Zero or not.

    @par Semantic:

    @code
    as_logical_t<T> r = is_gez(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = x >= 0;
    @endcode


    @return a logical value

**/
  template<typename T> auto is_gez(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True or @ref False according x is greater or equal to @ref Zero or not.


      Function object tied to simd::is_ge

z      @see simd::is_ge
z    **/
    const boost::dispatch::functor<tag::is_gez_> is_gez = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_gez.hpp>
#include <boost/simd/arch/common/scalar/function/is_gez.hpp>
#include <boost/simd/function/simd/is_gez.hpp>

#endif
