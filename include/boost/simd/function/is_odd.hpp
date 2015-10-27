//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_ODD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_ODD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True or False according a0 is odd or not.

    @par Semantic:

    @code
    logical<T> r = is_odd(a0);
    @endcode

    is similar to:

    @code
    logical<T> r = (abs(a0)/2)*2 == abs(a0)-1;
    @endcode

    @par Note:

    A floating number a0 is odd if a0-1 is even


    @return a logical value

**/
  template<typename T> auto is_odd(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-predicates

      Function object tied to simd::is_odd

      @see simd::is_odd
    **/
    const boost::dispatch::functor<tag::is_odd_> is_odd = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_odd.hpp>
#include <boost/simd/arch/common/scalar/function/is_odd.hpp>
//#include <boost/simd/arch/common/function/simd/is_odd.hpp>

#endif
