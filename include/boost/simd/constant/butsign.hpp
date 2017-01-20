//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_BUTSIGN_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_BUTSIGN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate value with all bits set to one except the most sinificant
    set to zero (the sign bit)

     @return The Butsign constant for the proper type
  **/
  template<typename T> T Butsign();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant
      Generate the  constant butsign.

      @return The Butsign constant for the proper type
    **/
    Value Butsign();
  }
} }
#endif

#include <boost/simd/constant/scalar/butsign.hpp>
#include <boost/simd/constant/simd/butsign.hpp>

#endif
