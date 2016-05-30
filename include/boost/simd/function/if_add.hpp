//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ADD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ADD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing if_add capabilities

    The function returns the second entry or the sum of the second
    and third entries, according to the first entry being @ref False or
    @ref True

    @par Semantic:

    For every parameters of types respectively C, T, T:

    @code
    T r = if_add(cond,t1,t2);
    @endcode

    is similar to:

    @code
    T r = cond ? t1+t2 : t1;
    @endcode

    @par Alias:
    @c if_add

  **/
  const boost::dispatch::functor<tag::if_add_> if_add = {};
} }
#endif

#include <boost/simd/function/scalar/if_add.hpp>
#include <boost/simd/function/simd/if_add.hpp>

#endif
