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

    /*!
      @ingroup group-functions
      @defgroup group-arithmetic Arithmetic Functions

      Those functions provides scalar and SIMD algorithms for classical arithmetic operators and
      functions provided by the C and C++ standard library. Other functions like, in particular,
      provision for saturated operations are also provided.
    **/

    /*!
      @ingroup group-functions
      @defgroup group-boolean Boolean Functions

      Those functions provides scalar and SIMD algorithms for boolean operations and operators.
      Boolean operations provided include logical operator, prefix form of the ternary operator and
      selected variations and conditional operations.
    **/

    /*!
      @ingroup group-functions
      @defgroup group-bitwise Bitwise Functions

      Those functions provides scalar and SIMD algorithms for bit manipulations and bitwise
      operators. Bitwise operations are provided along more specific ones like bit-level rotations,
      bit set, get and toggling and mapping for compiler-specific first bit set or population count
      operations.

      Note that bitwise functions operators may accept IEEE types as arguments. The implied semantic
      is then that the operations are applied to the IEEE bit patterns.
    **/

    /*!
      @ingroup group-functions
      @defgroup group-constant Constant Functions

      Those functions provides scalar and SIMD constant generators for the most usual
      constant values like zero, numeric limits, IEEE special values.

      Constant generator functions takes no argument but requires a template type parameters
      to choose which type the constant should be stored into.
    **/

    /*!
      @ingroup group-functions
      @defgroup group-ieee IEEE Functions

      Those functions provides scalar and SIMD algorithms for inspecting, generating or
      decomposing IEEE 754 floating point numbers. Operations like exponent and mantissa
      extraction, floating point modulo, IEEE bit patterns manipulation and magnitude comparison
      are provided.
    **/

    /*!
      @ingroup group-functions
      @defgroup group-predicates Predicates Functions

      Those functions provides scalar and SIMD algorithms for testing values properties.
      Tests like checks for validity, infinity, sign and others are provided. As for @ref
      group-boolean , those functions handles and returns typed logical types.
    **/

    /*!
      @ingroup group-functions
      @defgroup group-reduction Reduction Functions

      Those functions provides algorithms for in-register reduction and prefix-scan operations.
      Those functions are usually only defined for SIMD types but may, in some cases like sum or
      product, have a valid scalar semantic.
    **/

    /*!
      @ingroup group-functions
      @defgroup group-swar Intra-register Functions

      Those functions provides algorithms for interleaving, aggregation, splitting and, more
      generally, wide registers sub-element manipulation. Those functions are usually only
      defined for SIMD types but may, in some cases, have a valid scalar semantic.
    **/

    /*!
      @ingroup group-functions
      @defgroup group-exponential Exponential Functions

      Those functions provides algorithms for computing exponentials and logarithms.
    **/

     /*!
      @ingroup group-functions
      @defgroup group-hyperbolic Hyperbolic Functions

      Those functions provides algorithms for computing hyperbolics and logarithms.
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
      @ingroup group-callable
      @defgroup group-callable-arithmetic Arithmetic Callable Objects
      Callable objects version of @ref group-arithmetic

      Their specific semantic limitations are similar to those of their function
      equivalents as described in the @ref group-arithmetic section.
    **/

    /*!
      @ingroup group-callable
      @defgroup group-callable-boolean Boolean Callable Objects
      Callable objects version of @ref group-boolean

      Their specific semantic limitations are similar to those of their function
      equivalents as described in the @ref group-boolean section.
    **/

    /*!
      @ingroup group-callable
      @defgroup group-callable-bitwise Bitwise Callable Objects
      Callable objects version of @ref group-bitwise

      Their specific semantic limitations are similar to those of their function
      equivalents as described in the @ref group-bitwise section.
    **/

    /*!
      @ingroup group-callable
      @defgroup group-callable-constant Constant Callable Objects
      Callable objects version of @ref group-constant

      Their specific semantic limitations are similar to those of their function
      equivalents as described in the @ref group-constant section.
    **/

    /*!
      @ingroup group-callable
      @defgroup group-callable-ieee IEEE Callable Objects
      Callable objects version of @ref group-ieee

      Their specific semantic limitations are similar to those of their function
      equivalents as described in the @ref group-ieee section.
    **/

    /*!
      @ingroup group-callable
      @defgroup group-callable-predicates Predicates Callable Objects
      Callable objects version of @ref group-predicates

      Their specific semantic limitations are similar to those of their function
      equivalents as described in the @ref group-predicates section.
    **/

    /*!
      @ingroup group-callable
      @defgroup group-callable-reduction Reduction Callable Objects
      Callable objects version of @ref group-reduction

      Their specific semantic limitations are similar to those of their function
      equivalents as described in the @ref group-reduction section.
    **/

    /*!
      @ingroup group-callable
      @defgroup group-callable-swar Intra-register Callable Objects
      Callable objects version of @ref group-swar

      Their specific semantic limitations are similar to those of their function
      equivalents as described in the @ref group-swar section.
    **/

    /*!
      @ingroup group-callable
      @defgroup group-callable-exponential Exponential Callable Objects
      Callable objects version of @ref group-exponential

      Their specific semantic limitations are similar to those of their function
      equivalents as described in the @ref group-exponential section.
    **/

    /*!
      @ingroup group-callable
      @defgroup group-callable-hyperbolic Hyperbolic Callable Objects
      Callable objects version of @ref group-hyperbolic

      Their specific semantic limitations are similar to those of their function
      equivalents as described in the @ref group-hyperbolic section.
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
