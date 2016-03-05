//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SPLAT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-ieee

    splat the value of its parameter on the Target.

  **/
  template<typename Target, typename T> auto splat(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      splat the value of its parameter on the Target.


      Function object tied to simd::splat

      @see simd::splat
    **/
    const boost::dispatch::functor<tag::splat_> splat = {};
  }
} }
#endif

#include <boost/simd/function/scalar/splat.hpp>


#endif
