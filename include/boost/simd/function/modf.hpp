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
#ifndef BOOST_SIMD_FUNCTION_MODF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MODF_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Computes the integer and  fractional parts of the input

    @par Semantic:

    @code
    T t = modf(x, f);
    @endcode

    is similar to:

    @code
    T t = trunc(x);
    T f = frac(x);
    @endcode

    The following call can also be used

    @code
    std::pair<T,T> p = modf(x);
    @endcode

    @see frac,  trunc

**/
  template<typename T> auto modf(T const& x, T& f) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::modf

      @see simd::modf
    **/
    const boost::dispatch::functor<tag::modf_> modf = {};
  }
} }
#endif

#include <boost/simd/function/definition/modf.hpp>
#include <boost/simd/arch/common/scalar/function/modf.hpp>
//#include <boost/simd/arch/common/function/simd/modf.hpp>

#endif
