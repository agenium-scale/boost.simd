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

    This is a convenient alias of @ref seladd
  **/
  const boost::dispatch::functor<tag::if_add_> if_add = {};
} }
#endif

#include <boost/simd/function/scalar/seladd.hpp>
#include <boost/simd/function/simd/if_add.hpp>

#endif
