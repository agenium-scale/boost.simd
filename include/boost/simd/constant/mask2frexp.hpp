//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MASK2FREXP_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MASK2FREXP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant mask2frexp, a utility mask for frexp implementation.

@par Semantic:

    @code
    as_integer<T> r = Mask2frexp<T>();
    @endcode

    @code
    if T is double
      r =  4602678819172646912ll;
    else if T is float
      r =  1056964608;
    @endcode

    @return The Mask2frexp constant for the proper type
  **/
  template<typename T> T Mask2frexp();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant
      Generate the  constant mask2frexp.

      @return The Mask2frexp constant for the proper type
    **/
    const boost::dispatch::functor<tag::mask2frexp_> mask2frexp = {};
  }
} }
#endif

#include <boost/simd/constant/definition/mask2frexp.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
