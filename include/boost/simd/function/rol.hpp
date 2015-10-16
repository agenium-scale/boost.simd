//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ROL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ROL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes rol value of its parameter.

  **/
  template<typename T> auto rol(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::rol

      @see simd::rol
    **/
    const boost::dispatch::functor<tag::rol_> rol = {};
  }
} }
#endif

#include <boost/simd/function/definition/rol.hpp>
#include <boost/simd/arch/common/generic/function/rol.hpp>
//#include <boost/simd/arch/common/function/simd/rol.hpp>

#endif
