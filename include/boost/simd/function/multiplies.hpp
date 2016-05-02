//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MULTIPLIES_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MULTIPLIES_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-operator
    Function object implementing multiplies capabilities

    Perform the product of two parameters of the same type.

    @par Semantic

    For any value @c a and @c b of type @c T,

    @code
    T x = multiplies(a,b);
    @endcode

    returns the product of @c a and @c b

  **/
  const boost::dispatch::functor<tag::multiplies_> multiplies = {};
} }
#endif

#include <boost/simd/function/scalar/multiplies.hpp>
#include <boost/simd/function/simd/multiplies.hpp>

#endif
