//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SEL_INCLUDED
#define BOOST_SIMD_FUNCTION_SEL_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-boolean

    If cond is true returns t else returns f

    This is a convenient alias of if_else
  **/
  template<typename COND typename T1, typename T2>
  auto sel(COND const& cond, T1 const& t, T2 const& f );
  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      If cond is true returns t else returns f


      Function object tied to boost::simd::sel

      @see boost::simd::sel
    **/
    const boost::dispatch::functor<tag::sel_> sel = {};
  }
} }
#endif

#include <boost/simd/function/scalar/sel.hpp>
#include <boost/simd/function/simd/sel.hpp>


#endif
