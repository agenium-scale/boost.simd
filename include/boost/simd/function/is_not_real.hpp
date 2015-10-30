//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_REAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_REAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True or @ref False according x is real or not.
    For non complex numbers it is always false

    @par Semantic:

    @code
    as_logical_t<T> r = is_not_real(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = @ref False;
    @endcode


    @return a logical value

**/
  template<typename T> auto is_not_real(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True or @ref False according x is real or not.
      For non complex numbers it is always false


      Function object tied to simd::is_not_real

      @see simd::is_not_real
    **/
    const boost::dispatch::functor<tag::is_not_real_> is_not_real = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_not_real.hpp>
#include <boost/simd/arch/common/scalar/function/is_not_real.hpp>
#include <boost/simd/arch/common/generic/function/is_not_real.hpp>
#include <boost/simd/function/simd/is_not_real.hpp>

#endif
