//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DREM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DREM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the drem of division.
    The return value is x-n*y, where n is the value x/y,
    rounded to the nearest integer (using @ref round2even).

    This is a convenient alias of @ref remainder
**/
  template<typename T> auto drem(T const& x, T const & y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the drem of division.
      The return value is x-n*y, where n is the value x/y,
      rounded to the nearest integer (using @ref round2even).


      Function object tied to simd::drem

      @see simd::drem
    **/
    const boost::dispatch::functor<tag::drem_> drem = {};
  }
} }
#endif

#include <boost/simd/function/definition/drem.hpp>
#include <boost/simd/arch/common/scalar/function/remainder.hpp>
#include <boost/simd/function/simd/drem.hpp>

#endif
