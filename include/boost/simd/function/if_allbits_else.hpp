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
#ifndef BOOST_SIMD_FUNCTION_IF_ALLBITS_ELSE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ALLBITS_ELSE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    If cond is true returns allbits else returns f

    @par Semantic:

    For every parameters of types respectively COND, T:

    @code
    T r = if_allbits_else(cond,f);
    @endcode

    is similar to:

    @code
    T r = cond ? Allbits : f;
    @endcode

    @par Alias:
    @c if_nan_else,

    @see genmask, Allbits, Nan


    @return a value of the same type as the second parameter

**/
  template<typename COND, typename T> auto if_allbits_else(COND const& cond, T const & f) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::if_allbits_else

      @see simd::if_allbits_else
    **/
    const boost::dispatch::functor<tag::if_allbits_else_> if_allbits_else = {};
  }
} }
#endif

#include <boost/simd/function/definition/if_allbits_else.hpp>
#include <boost/simd/arch/common/scalar/function/if_allbits_else.hpp>
//#include <boost/simd/arch/common/function/simd/if_allbits_else.hpp>

#endif
