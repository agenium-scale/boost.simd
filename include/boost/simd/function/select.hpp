//==================================================================================================
/*!
  @file
  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS
  Copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SELECT_INCLUDED
#define BOOST_SIMD_FUNCTION_SELECT_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-boolean

    If cond is @ref True returns t else returns f

    This is a convenient alias of @ref if_else
  **/
  template<typename C typename T1, typename T2>
  auto select(C const& cond, T1 const& t, T2 const& f );
  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      If cond is @ref True returns t else returns f


      Function object tied to boost::simd::select

      @see boost::simd::select
    **/
    const boost::dispatch::functor<tag::select_> select = {};
  }
} }
#endif

#include <boost/simd/function/scalar/select.hpp>
#include <boost/simd/function/simd/select.hpp>


#endif
