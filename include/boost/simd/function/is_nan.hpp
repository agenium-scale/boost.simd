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
#ifndef BOOST_SIMD_FUNCTION_IS_NAN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NAN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True or False according a0 is nan or not.

    @par Semantic:

    @code
    logical<T> r = is_nan(a0);
    @endcode

    is similar to:

    @code
    logical<T> r = a0 != a0;
    @endcode


    @return a logical value

**/
  template<typename T> auto is_nan(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-predicates

      Function object tied to simd::is_nan

      @see simd::is_nan
    **/
    const boost::dispatch::functor<tag::is_nan_> is_nan = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_nan.hpp>
#include <boost/simd/arch/common/scalar/function/is_nan.hpp>
//#include <boost/simd/arch/common/function/simd/is_nan.hpp>

#endif
