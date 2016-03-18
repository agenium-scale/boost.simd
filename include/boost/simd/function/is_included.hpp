//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_INCLUDED_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_INCLUDED_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing is_included capabilities

    Returns @ref True is only if all bits set in x are also set in y

    @par Semantic:

    For every parameters of type T0, T1 of same bit size:

    @code
    logical<scalar_of_t<T0>> r = is_included(x,y);
    @endcode

    is similar to:

    @code
    logical<scalar_of_t<T0>> r = all((x&y) == y);
    @endcode

  **/
  const boost::dispatch::functor<tag::is_included_> is_included = {};
} }
#endif

#include <boost/simd/function/scalar/is_included.hpp>
#include <boost/simd/function/simd/is_included.hpp>

#endif
