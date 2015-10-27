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
#ifndef BOOST_SIMD_FUNCTION_IS_LEZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_LEZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True or False according a0 is less or equal to zero or not.

    @par Semantic:

    @code
    logical<T> r = is_lez(a0);
    @endcode

    is similar to:

    @code
    logical<T> r = a0 <= 0;
    @endcode


    @return a logical value

**/
  template<typename T> auto is_lez(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-predicates

      Function object tied to simd::is_le

z      @see simd::is_le
z    **/
    const boost::dispatch::functor<tag::is_lez_> is_lez = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_lez.hpp>
#include <boost/simd/arch/common/scalar/function/is_lez.hpp>
//#include <boost/simd/arch/common/function/simd/is_lez.hpp>

#endif
