//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#error This file is documentation-only and must not be included

/*!
  @defgroup group-concept Concepts
  Concepts defined by @projectname
**/

/*!
  @ingroup group-concept
  @defgroup group-concept-types Types

  Those Concepts specifies the requirement and relationship between types that the library
  functions can interact with through functions or classes.

  The main Concepts defined by @projectname is the Vectorizable and Vectorized one.
  Those two Concepts are used to define which type can be turned into a SIMD compatible type
  and what expressions and operations are valids for such a SIMD compatible type.

  From those two Concepts, we define the Value-related Concepts that describes the types
  usable as arguments of @projectname 's functions. They are the IEEEValue and the IntegerValue
  Concepts which represent types which can be either Vectorizable or Vectorized and supports a
  subset of numerical properties. This ambivalence around the SIMD or scalar status of types modeling
  these Concepts is what make @projectname 's functions usable with both regular scalar type
  (e.g. calling <tt>boost::simd::cos(4.f)</tt>) and SIMD ones (e.g. calling
  <tt>boost::simd::cos(pack<double,2>{(}0.1,0.2})</tt>). Such behavior will be paramount to support
  the polymorphic aspect of the SIMDCallable Concepts, thus allowing polymorphic function objects
  to be used for both scalar and SIMD computation.

  Finally, the Value Concept aggregates all types modeling either IEEEValue or IntegerValue. Similarly,
  the LogicalValue Concept defines types that represent SIMD-compatible logical values. LogicalValue
  and Value are separate as some @projectname 's functions may not support one or the other (e.g.
  there is no support for boost::simd::plus on logical values).
**/


