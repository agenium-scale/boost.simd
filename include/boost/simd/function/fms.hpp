//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FMS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FMS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing fms capabilities

    Computes the fused  substract-multiply of three values.

    @par semantic:
    For any given value @c x,  @c y,  @c z of type @c T:

    @code
    T r = fms(x, y, z);
    @endcode

    The code is similar to:

    @code
    T r = x*y-z;
    @endcode

    @par Note:

    fms can be called with the same syntax as @ref fma

    @see fma, fnma, fnms, correct_fma

  **/
  const boost::dispatch::functor<tag::fms_> fms = {};
} }
#endif

#include <boost/simd/function/scalar/fms.hpp>
#include <boost/simd/function/simd/fms.hpp>

#endif
