//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_NOTOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_NOTOR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-boolean

    Computes logical_notor value of its parameter.

  **/
  template<typename T> auto logical_notor(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::logical_notor

      @see simd::logical_notor
    **/
    const boost::dispatch::functor<tag::logical_notor_> logical_notor = {};
  }
} }
#endif

#include <boost/simd/function/definition/logical_notor.hpp>
#include <boost/simd/arch/common/scalar/function/logical_notor.hpp>
//#include <boost/simd/arch/common/function/simd/logical_notor.hpp>

#endif
