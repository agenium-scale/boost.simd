//==================================================================================================
/*!
  @file

  Convenience header for Boost.SIMD

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_HPP_INCLUDED
#define BOOST_SIMD_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/arch.hpp>
#include <boost/simd/as.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/detail/math.hpp>
#include <boost/simd/pack.hpp>

/// Main Boost namespace
namespace boost
{
  /// Main Boost.SIMD namespace
  namespace simd
  {
    /*!
      @defgroup group-api User API

      The Boost.SIMD User API includes all the types, meta-functions, algorithms, functions
      and callable objects allowing the design and implementation of SIMD code.
    **/

     /*!
      @ingroup group-api
      @defgroup group-config Configuration
      Configuration options

      Behavior of Boost.SIMD functions can be globally modified by this set of preprocessor
      definitions.
    **/

    /*!
      @ingroup group-api
      @defgroup group-types Types and helpers

      Boost.SIMD provides a set of types to handle SIMD operations in a portable way.
      These types include:

      - boost::simd::pack which encapsulates SIMD registers
      - boost::simd::logical which encapsulates typed boolean values
    **/

    /*!
      @ingroup group-api
      @defgroup group-functions Functions and Constants

      Boost.SIMD functions and constants are designed to work seamlessly on both scalar
      and SIMD parameters. Their compile-time polymorphic behavior ensures that the best
      available implementation will be selected for any given combination of types, architecture
      and options (if any).

      While being documented as functions, most Boost.SIMD functions are actually Function Objects.
      This implementation allow Boost.SIMD to use its functions directly in standard algorithms
      and to support functions decorators to handle variations in functions' behavior.

      Boost.SIMD functions are accessible via the header files located in the
      @c boost/simd/function folder. E.g, boost::simd::abs requires the inclusion
      of boost/simd/function/abs.hpp.

      Similarly, Boost.SIMD constants are accessible via the header files located in the
      @c boost/simd/constant folder. E.g, boost::simd::True requires the inclusion
      of boost/simd/constant/true.hpp. All Boost.SIMD functions begin with a lower-case
      letter and all Boost.SIMD constants begin with an upper-case letter.

      Function semantics are usually similar to the pre-existing ones, if any, with the
      following caveats:

      - All functions are assumed to be @c noexcept.
      - Type mixing may be prohibited for fundamental types , i.e boost::simd::plus @c (char,char)
        is valid while boost::simd::plus @c (int,char) is not
      - Type promotion on result type may be disabled, i.e boost::simd::plus @c (char,char)
        returns @c char

      These limitations are due to the hardware implementation of these functions.

      @par Notes:

        - Almost all prototype of the Boost.SIMD functions and constants are decribed using prototypes with types as:

           - IntegerValue designing any integer type among @c std::int8_t, @c std::int16_t, @c std::int32_t,
              @c std::int64_t, @c std::uint8_t, @c std::uint16_t, @c std::uint32_t, @c std::uint64_t
              or @cpack of such types

           - IEEEValue   designing float or double  or @cpack of such types

           - Value designing any IntegerValue or IEEEValue type and in obvious cases can also be logical types.

        - Some functors transform IntegerValue inputs to IEEEValue outputs

           - This behaviour is only allowed in SIMD mode if the integral types elements are 32 ou 64 bits allowing size
             preserving vector transforms.

        - In most situations calling a functor with mixed scalar/simd parameters result in the autmatic splat of the scalar values
          to the SIMD parmeter type.

          The major exceptions are shift operation for which on many architecture a scalar integer shift is much more efficient that
          a SIMD one.
    **/
} }

#endif
