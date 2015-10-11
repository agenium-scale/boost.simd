//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_THIRD_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_THIRD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate value 1/3

    @par Semantic:

    @code
    T r = Third<T>();
    @endcode

    is similar to:

    @code
    T r = T(1)/T(3);
    @endcode

    @return The Third constant for the proper type
  **/
  template<typename T> T Third();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant third.

      @return The Third constant for the proper type
    **/
    const boost::dispatch::functor<tag::third_> third = {};
  }
} }
#endif

#include <boost/simd/constant/definition/third.hpp>
#include <boost/simd/arch/common/constant/scalar/constant_value.hpp>

#endif
