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
    and third entries, according to the first entry being False or
    True

    This is a convenient alias of seladd
**/
  template<typename COND, typename T> auto if_add(COND const& cond, T const& t1, T const& t2) {}


  namespace functional
  {
    /*!
      @ingroup group-callable-boolean



      Function object tied to simd::if_add

      @see simd::if_add
    **/
    const boost::dispatch::functor<tag::if_add_> if_add = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_add.hpp>
#include <boost/simd/arch/common/scalar/function/seladd.hpp>
#include <boost/simd/function/simd/if_add.hpp>

#endif
