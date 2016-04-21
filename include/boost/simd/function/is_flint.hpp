//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_FLINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_FLINT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    Function object implementing is_flint capabilities

    Returns @ref True or @ref False according x is a flint or not.

    @par Semantic:

    @code
    as_logical_t<T> r = is_flint(x);
    @endcode

    @par Note:

    A flint is a 'floating integer' i.e. a floating number
    representing exactly an integer value.

    Be conscious that all sufficiently great floating points values
    are flint and even are even...

  **/
  const boost::dispatch::functor<tag::is_flint_> is_flint = {};
} }
#endif

#include <boost/simd/function/scalar/is_flint.hpp>
#include <boost/simd/function/simd/is_flint.hpp>

#endif
