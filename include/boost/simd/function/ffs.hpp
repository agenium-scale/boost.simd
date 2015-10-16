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
#ifndef BOOST_SIMD_FUNCTION_FFS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FFS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes ffs value of its parameter.

  **/
  template<typename T> auto ffs(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::ffs

      @see simd::ffs
    **/
    const boost::dispatch::functor<tag::ffs_> ffs = {};
  }
} }
#endif

#include <boost/simd/function/definition/ffs.hpp>
#include <boost/simd/arch/common/scalar/function/ffs.hpp>
//#include <boost/simd/arch/common/function/simd/ffs.hpp>

#endif
