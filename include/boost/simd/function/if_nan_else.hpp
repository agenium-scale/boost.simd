//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_NAN_ELSE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_NAN_ELSE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    If cond is true returns allbits else returns f

    This is a convenient alias of if_allbits_else
**/
  template<typename COND, typename T> auto if_nan_else(COND const& cond, T const & f) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      If cond is true returns allbits else returns f


      Function object tied to simd::if_nan_else

      @see simd::if_nan_else
    **/
    const boost::dispatch::functor<tag::if_nan_else_> if_nan_else = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_nan_else.hpp>
#include <boost/simd/arch/common/scalar/function/if_allbits_else.hpp>
#include <boost/simd/function/simd/if_nan_else.hpp>

#endif
