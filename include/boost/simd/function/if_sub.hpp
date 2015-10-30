//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_SUB_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_SUB_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean


    The function returns the second entry or the difference of the
    second and third entries, according to the first entry being False
    or True

    This is a convenient alias of @ref selsub
**/
 template<typename C, typename T> auto if_sub(C const& cond, T const& t1, T const& t2) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean



      Function object tied to simd::if_sub

      @see simd::if_sub
    **/
    const boost::dispatch::functor<tag::if_sub_> if_sub = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_sub.hpp>
#include <boost/simd/arch/common/scalar/function/selsub.hpp>
#include <boost/simd/function/simd/if_sub.hpp>

#endif
