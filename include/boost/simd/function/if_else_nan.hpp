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
#ifndef BOOST_SIMD_FUNCTION_IF_ELSE_NAN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ELSE_NAN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    If cond is true returns t else returns allbits

    This is a convenient alias of if_else_allbits
**/
  template<typename COND, typename T> auto if_else_nan(COND const& cond, const T& t) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      If cond is true returns t else returns allbits


      Function object tied to simd::if_else_nan

      @see simd::if_else_nan
    **/
    const boost::dispatch::functor<tag::if_else_nan_> if_else_nan = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_else_nan.hpp>
#include <boost/simd/arch/common/scalar/function/if_else_allbits.hpp>
#include <boost/simd/function/simd/if_else_nan.hpp>

#endif
