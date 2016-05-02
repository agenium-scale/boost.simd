//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SEL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SEL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-boolean
    Function object implementing sel capabilities

    If cond is @ref True returns t else returns f

    This is a convenient alias of @ref if_else
  **/
  const boost::dispatch::functor<tag::sel_> sel = {};
} }
#endif

#include <boost/simd/function/scalar/sel.hpp>
#include <boost/simd/function/simd/sel.hpp>

#endif
