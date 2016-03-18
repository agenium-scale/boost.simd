//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ALL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ALL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing all capabilities

    Returns @ref True if all elements of the input vector are non zero.

    @par Semantic:

    For every parameter of type T

    @code
    logical<scalar_of_t<T>> r = all(x);
    @endcode

    is similar to:

    @code
    logical<scalar_of_t<T>> r = True;
    for(result_type i = 0; i != meta::cardinal_of<T>; ++i)
      if (!x[i]) {r =  False; break; }
    @endcode

  **/
  const boost::dispatch::functor<tag::all_> all = {};
} }
#endif

#include <boost/simd/function/scalar/all.hpp>
#include <boost/simd/function/simd/all.hpp>

#endif
