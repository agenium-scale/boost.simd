//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_LTZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_LTZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True or False according x is less than zero or not.

    @par Semantic:

    @code
    as_logical_t<T> r = is_ltz(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = x < 0;
    @endcode


    @return a logical value

**/
  template<typename T> auto is_ltz(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True or False according x is less than zero or not.


      Function object tied to simd::is_lt

z      @see simd::is_lt
z    **/
    const boost::dispatch::functor<tag::is_ltz_> is_ltz = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_ltz.hpp>
#include <boost/simd/arch/common/scalar/function/is_ltz.hpp>
//#include <boost/simd/arch/common/function/simd/is_ltz.hpp>

#endif
