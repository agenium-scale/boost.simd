//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INCS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INCS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Returns the entry plus one, saturated in the entry type.

    This is a convenient alias of @ref oneplus
  **/
  template<typename T> auto incs(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Returns the entry plus one, saturated in the entry type.

      Function object tied to simd::incs

      @see simd::incs
    **/
    const boost::dispatch::functor<tag::incs_> incs = {};
  }
} }
#endif

#include <boost/simd/function/definition/incs.hpp>
#include <boost/simd/arch/common/generic/function/oneplus.hpp>

#endif
