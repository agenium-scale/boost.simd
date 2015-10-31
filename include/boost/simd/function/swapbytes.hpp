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
#ifndef BOOST_SIMD_FUNCTION_SWAPBYTES_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SWAPBYTES_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Reverse the byte order of each scalar value

    @par semantic:
    For any given value @c x of type @c T:

    @code
    T r = swapbytes(x);
    @endcode



    @return      a value of the unsigned integer type associated to the first input.


**/
  template<typename T> auto swapbytes(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Reverse the byte order of each scalar value


      Function object tied to simd::swapbytes

      @see simd::swapbytes
    **/
    const boost::dispatch::functor<tag::swapbytes_> swapbytes = {};
  }
} }
#endif

#include <boost/simd/function/definition/swapbytes.hpp>
#include <boost/simd/arch/common/generic/function/swapbytes.hpp>
#include <boost/simd/function/simd/swapbytes.hpp>

#endif
