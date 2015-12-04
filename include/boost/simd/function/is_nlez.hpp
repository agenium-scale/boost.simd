//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NLEZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NLEZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True if x is not less or equal to @ref Zero else returns @ref False.

    @par Semantic:

    @code
    as_logical_t<T> r = is_nlez(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = !(x <= 0);
    @endcode

    @par Note:

    Due to existence of nan, this is not equivalent to a call to @ref is_gtz
    for floating types



    @return a logical value

**/
  template<typename T> auto is_nlez(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True if x is not less or equal to @ref Zero else returns @ref False.


      Function object tied to simd::is_nle

z      @see simd::is_nle
z    **/
    const boost::dispatch::functor<tag::is_nlez_> is_nlez = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_nlez.hpp>
#include <boost/simd/arch/common/scalar/function/is_nlez.hpp>
#include <boost/simd/function/simd/is_nlez.hpp>

#endif
