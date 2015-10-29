//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NGEZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NGEZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True if x is not greater or equal to zero else returns False.

    @par Semantic:

    @code
    as_logical_t<T> r = is_ngez(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = !(x >= 0);
    @endcode

    @par Note:

    Due to existence of nan, this is not equivalent to @c is_ltz(x)
    for floating types


    @return a logical value

**/
  template<typename T> auto is_ngez(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True if x is not greater or equal to zero else returns False.


      Function object tied to simd::is_nge

z      @see simd::is_nge
z    **/
    const boost::dispatch::functor<tag::is_ngez_> is_ngez = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_ngez.hpp>
#include <boost/simd/arch/common/scalar/function/is_ngez.hpp>
#include <boost/simd/function/simd/is_ngez.hpp>

#endif
