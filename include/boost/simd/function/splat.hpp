//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
<<<<<<< HEAD:include/boost/simd/function/splat.hpp
#ifndef BOOST_SIMD_FUNCTION_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SPLAT_HPP_INCLUDED
=======
#ifndef BOOST_SIMD_FUNCTION_SPLATTED_PROD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SPLATTED_PROD_HPP_INCLUDED
>>>>>>> super mega squash of doc:include/boost/simd/function/splatted_sum.hpp

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    Splatted sum

    Computes the splatted sum of the of its argument.

    @par Semantic

    For any type @c T and value @c x of type @c T:

    @code
    T r = splatted_sum(x);
    @endcode

    is similar to:

    @code
    T sum = 0;
    for(int i=0;i<T::static_size;++i) sum += x[i];
    for(int i=0;i<T::static_size;++i) r[i] = sum;
    @endcode

  **/
  template<typename T, typename U> T splat(U const& x) {}
} }
#endif

#include <boost/simd/function/scalar/splat.hpp>
#include <boost/simd/function/simd/splat.hpp>

#endif
