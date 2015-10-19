//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_BITINCREMENT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_BITINCREMENT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate a value in the chosen type the least significant bit set to 1.

    @par Semantic:

    @code
    T r = Bitincrement<T>();
    @endcode

    @return The Bitincrement constant for the proper type
  **/
  template<typename T> T Bitincrement();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant bitincrement.

      @return The Bitincrement constant for the proper type
    **/
    const boost::dispatch::functor<tag::bitincrement_> bitincrement = {};
  }
} }
#endif

#include <boost/simd/constant/definition/bitincrement.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
