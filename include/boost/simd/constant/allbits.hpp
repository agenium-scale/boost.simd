//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_ALLBITS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_ALLBITS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generates a value in the chosen type all bits of which are set to 1.

    @par Semantic:

    @code
    T r = Allbits<T>();
    @endcode

    is similar to

    @code
    if T is floating point
      r =  Nan<T>();
    else if T is signed integral
      r = -1;
    else
      r = Valmax<T>();
    @endcode

    @return The Allbits constant for the proper type
  **/
  template<typename T> T Allbits();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant
      Generate the  constant allbits. toto

      @return The Allbits constant for the proper type
    **/
    const boost::dispatch::functor<tag::allbits_> allbits = {};
  }
} }
#endif

#include <boost/simd/constant/definition/allbits.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
