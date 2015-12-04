//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NEZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NEZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True if x is not equal to @ref Zero else returns @ref False.

    @par Semantic:

    @code
    as_logical_t<T> r = is_nez(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = x != 0;
    @endcode


    @return a logical value

**/
  template<typename T> auto is_nez(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True if x is not equal to @ref Zero else returns @ref False.


      Function object tied to simd::is_ne

z      @see simd::is_ne
z    **/
    const boost::dispatch::functor<tag::is_nez_> is_nez = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_nez.hpp>
#include <boost/simd/arch/common/scalar/function/is_nez.hpp>
#include <boost/simd/function/simd/is_nez.hpp>

#endif
