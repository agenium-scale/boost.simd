//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

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
    Function object implementing ffs capabilities

    returns the index
    of the first bit set (beginning with the least
    significant bit) in the parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer_t<T,unsigned> r = ffs(x);
    @endcode

    @see  firstbitset,  firstbitunset

  **/
  const boost::dispatch::functor<tag::ffs_> ffs = {};
} }
#endif

#include <boost/simd/function/scalar/ffs.hpp>
#include <boost/simd/function/simd/ffs.hpp>

#endif
