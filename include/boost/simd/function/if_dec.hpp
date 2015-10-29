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
#ifndef BOOST_SIMD_FUNCTION_IF_DEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_DEC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    Decrements a value by 1 if a predicate is true.

    This is a convenient alias of seldec
**/
  template<typename COND, typename T> auto if_dec(COND const& cond, T const& t) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      Decrements a value by 1 if a predicate is true.


      Function object tied to simd::if_dec

      @see simd::if_dec
    **/
    const boost::dispatch::functor<tag::if_dec_> if_dec = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_dec.hpp>
#include <boost/simd/arch/common/scalar/function/seldec.hpp>
#include <boost/simd/function/simd/if_dec.hpp>

#endif
