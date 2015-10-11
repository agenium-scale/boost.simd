//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_SIGNMASK_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_SIGNMASK_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate a mask with the lone most significand bit set to one
    (even if the type is unsigned).

    @par Semantic:

    @code
    T r = Signmask<T>();
    @endcode

    is similar to:

    @code
    T r = bitwise_cast<T>(1 << sizeof(T)*8-1);
    @endcode

    @return The Signmask constant for the proper type
  **/
  template<typename T> T Signmask();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant signmask.

      @return The Signmask constant for the proper type
    **/
    const boost::dispatch::functor<tag::signmask_> signmask = {};
  }
} }
#endif

#include <boost/simd/constant/definition/signmask.hpp>
#include <boost/simd/arch/common/constant/scalar/constant_value.hpp>

#endif
