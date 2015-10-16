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
#ifndef BOOST_SIMD_FUNCTION_BROADCAST_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BROADCAST_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-swar

    Computes broadcast value of its parameter.

  **/
  template<typename T> auto broadcast(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::broadcast

      @see simd::broadcast
    **/
    const boost::dispatch::functor<tag::broadcast_> broadcast = {};
  }
} }
#endif

#include <boost/simd/function/definition/broadcast.hpp>
#include <boost/simd/arch/common/scalar/function/broadcast.hpp>
//#include <boost/simd/arch/common/function/simd/broadcast.hpp>

#endif
