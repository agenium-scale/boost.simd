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
#ifndef BOOST_SIMD_FUNCTION_IS_REAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_REAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True or @ref False according x is real or not.
    For non complex numbers this is always true.

    @par Semantic:

    @code
    as_logical_t<T> r = is_real(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = True ;
    @endcode


    @return a logical value

**/
  template<typename T> auto is_real(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True or @ref False according x is real or not.
      For non complex numbers this is always true.


      Function object tied to simd::is_real

      @see simd::is_real
    **/
    const boost::dispatch::functor<tag::is_real_> is_real = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_real.hpp>
#include <boost/simd/arch/common/scalar/function/is_real.hpp>
#include <boost/simd/arch/common/generic/function/is_real.hpp>
#include <boost/simd/function/simd/is_real.hpp>

#endif
