//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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

    The function returns the second entry or the sum of the second
    and third entries, according to the first entry being @ref False or
    @ref True

    This is a convenient alias of @ref seladd
**/
  template<typename C, typename T> auto if_add(C const& cond, T const& t1, T const& t2) {}


  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      The function returns the second entry or the sum of the second
      and third entries, according to the first entry being @ref False or
      @ref True

      Function object tied to simd::if_add

      @see simd::if_add
    **/
    const boost::dispatch::functor<tag::if_add_> if_add = {};
  }
} }
#endif

#include <boost/simd/function/scalar/seladd.hpp>
#include <boost/simd/function/simd/if_add.hpp>

#endif
