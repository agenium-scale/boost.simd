//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_C180_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_C180_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the value 180 in the chosen type

    @code
    T r = C180<T>();
    @endcode

    is similar to

    @code
    T r = T(180);
    @endcode

    @return The C180 constant for the proper type
  **/
  template<typename T> T C180();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant c180.

      @return The C180 constant for the proper type
    **/
    const boost::dispatch::functor<tag::c180_> c180 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/c180.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>
#include <boost/simd/arch/common/simd/constant/constant_value.hpp>

#endif
