//==================================================================================================
/*!
  @file
  Copyright 2015 NumScale SAS
  Copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_WHERE_INCLUDED
#define BOOST_SIMD_FUNCTION_WHERE_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-boolean

    If cond is @ref True returns t else returns f

    This is a convenient alias of @ref if_else
  **/
  template<typename C typename T1, typename T2>
  auto where(C const& cond, T1 const& t, T2 const& f );
  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      If cond is @ref True returns t else returns f


      Function object tied to boost::simd::where

      @see boost::simd::where
    **/
    const boost::dispatch::functor<tag::where_> where = {};
  }
} }
#endif

#include <boost/simd/function/scalar/where.hpp>
#include <boost/simd/function/simd/where.hpp>


#endif
