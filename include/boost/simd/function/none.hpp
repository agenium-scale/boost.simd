//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NONE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NONE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing none capabilities

    Returns True if all elements of the input vector are zero.

    @par Semantic:

    For every parameter of type T

    @code
    as_logical_t<scalar_of_t<T>> r = none(x);
    @endcode

    is similar to:

    @code
    as_logical_t<scalar_of_t<T>> r = !any(x);
    @endcode

  **/
  const boost::dispatch::functor<tag::none_> none = {};
} }
#endif

#include <boost/simd/function/scalar/none.hpp>
#include <boost/simd/function/simd/none.hpp>

#endif
