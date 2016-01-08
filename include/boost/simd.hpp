//==================================================================================================
/*!
  @file

  Convenience header for Boost.SIMD

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_HPP_INCLUDED
#define BOOST_SIMD_HPP_INCLUDED

#include <boost/simd/arch.hpp>
#include <boost/simd/as.hpp>
#include <boost/simd/cardinal_of.hpp>
#include <boost/simd/config.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/math.hpp>

/// Main Boost namespace
namespace boost
{
  /// Main Boost.SIMD namespace
  namespace simd
  {
    /*!
      @defgroup group-api User API

      The Boost.SIMD User's API includes all the types, meta-functions, algorithms, functions,
      callable object allowing the design and implementation of SIMD aware code.
    **/

    /*!
      @ingroup group-api
      @defgroup group-types Types and helpers

      Boost.SIMD provides a set of new types to handle SIMD operations in a portable way.
      Those types include:

      - boost::simd::pack which embeds SIMD wide-registers
      - boost::simd::logical which embeds typed boolean values
    **/

    /*!
      @ingroup group-api
      @defgroup group-functions Functions and Constants

      Boost.SIMD functions and constants are designed to work seamlessly on both scalar
      and SIMD parameters. Their polymorphic behavior ensure that the best available
      implementation will be selected for any given type or types combination.

      Boost.SIMD functions are accessible via its eponymous include file located in the
      @c boost/simd/function folder. E.g, boost::simd::abs requires the inclusion
      of boost/simd/function/abs.hpp.

      Similarly, Boost.SIMD constants are accessible via its eponymous include file located in the
      @c boost/simd/constant folder. E.g, boost::simd::True requires the inclusion
      of boost/simd/constant/true.hpp. Note that contrary to functions, all Boost.SIMD constants
      name starts with a capital letter.

      Function semantics are usually similar to the pre-existing ones, if any, with the
      following caveats:

      - All functions are assumed to be @c noexcept.
      - Type mixing may be prohibited for fundamental types , i.e boost::simd::plus @c (char,char)
        is valid while boost::simd::plus @c (int,char) is not
      - Type promotion on result type may be disabled, i.e boost::simd::plus @c (char,char)
        returns @c char

      Those changes are motivated by the fact SIMD operations require similar limitations.
    **/

    /// Boost.SIMD Callable Objects namespace
    namespace functional {}

    /*!
      @ingroup group-api
      @defgroup group-callable Callable Objects

      Boost.SIMD provides a Callable Object version of most of its scalar and SIMD functions.
      All those Callable Objects are accessible in the boost::simd::functional namespace. Those
      callable objects are meant to be used as parameters by other, higher-order functions and
      algorithms without having to perform complex tricks to pass a function template as an
      argument.

      As an example, the following code demonstrates how to apply boost::simd::abs
      on each value in a std::vector via the standard @c transform algorithm.

      @code
      std::vector<float> data(1024), output(1024);

      std::transform(data.begin(), data.end(), output.begin(), functional::abs);
      @endcode

      For most functions and constant generators, the syntax will be similar to the function version.
      The main exception is the required use of boost::simd::as or boost::simd::as_ to pass type
      informations to the callable object as demonstrated below:

      @code
      // Use the type of an existing value
      auto many = functional::inf( boost::simd::as(1.f) );

      // Use an arbitrary type
      auto a_lot = functional::inf( boost::simd::as_<double>{} );
      @endcode
    **/

     /*!
      @defgroup group-config Configuration
      Configuration options
    **/

    /*!
      @defgroup group-hierarchy Hierarchies
      Type hierarchies defined by the library
    **/

    /// Boost.SIMD Concepts namespace
    namespace concept
    {
      /*!
        @defgroup group-concept Concepts
        Concepts defined by the library
      **/
    }

    /// Boost.SIMD extension points namespace
    namespace ext
    {
      /*!
        @defgroup group-ext Library extension points
        User customizable elements of the library
      **/
    }

    namespace detail
    {
      /*!
        @defgroup group-detail Implementation details
        Implementation details
      **/
    }
} }

#endif
