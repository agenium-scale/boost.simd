//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARITHMETIC_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-arithmetic Arithmetic functions

    These functions provide scalar and SIMD implementations of classical arithmetic operators and
    functions provided by the C and C++ standard library. Other functionality, in particular,
    saturated operations are also provided.

    @Notes

     - Saturated operations

     The functors:
       - abs,
       - dec,
       - dist,
       - divides,
       - group,
       - inc,
       - minus,
       - minusone,
       - multiplies,
       - plus,
       - oneminus,
       - oneplus,
       - sqr
       - toint
       - touint
       - unary_minus,
       - unary_plus

       can be decorated with the saturated_ decorator. This decorator has no effect on floating
       calls,  but on integer calls but for integers replace the operation by its saturated equivalent.

       Typically overflows will be replaced by the Valmin/Valmax proper value instead of providing
       undefined behaviour for signed integral types or wrapping modulo Valmax+1 for unsigned ones.

       Peculiarly saturated_(abs) and saturated_(dist) ensure that the result will never be stricly
       negative (which is for instance the case of abs(Valmin<T>()) for T any any signed integral type).

     - Division operations

       divides is the function associated to standard division. There is another one,  providing more
       flexibility,  namely div.

       With two parameters div and divides are equivalent, but div can admit an option first parameter
       that modify its behaviour.

       The option parameter is described in the following table where a and b are of type T,  fT is a
       supposed floating (as_floating_t<T> if it exists) and iT is the integer type associated to T
       (as_integer_t<T>). (fT and iT are here only to support pseudo code description)


      |--------------------|--------------------------|-----------------------------------------------|
      | option             |          call            |      result similar to                        |
      |--------------------|--------------------------|-----------------------------------------------|
      | ceil               |   div(ceil, a, b)        |      T(ceil(fT(a)/fT(b)))                     |
      | floor              |   div(floor, a, b)       |      T(floor(fT(a)/fT(b)))                    |
      | fix                |   div(fix, a, b)         |      T(fix(fT(a)/fT(b)))                      |
      | round              |   div(round, a, b)       |      T(round(fT(a)/fT(b)))                    |
      | round2even         |   div(round2even, a, b)  |      T(round2even(fT(a)/fT(b)))               |
      | iceil              |   div(iceil, a, b)       |      iT(iceil(fT(a)/fT(b)))                   |
      | ifloor             |   div(ifloor, a, b)      |      iT(ifloor(fT(a)/fT(b)))                  |
      | ifix               |   div(ifix, a, b)        |      iT(ifix(fT(a)/fT(b)))                    |
      | iround             |   div(iround, a, b)      |      iT(iround(fT(a)/fT(b)))                  |
      | iround2even        |   div(riound2even, a, b) |      iT(iround2even(fT(a)/fT(b)))             |
      |--------------------|--------------------------|-----------------------------------------------|

     - Remainder operations

       rem is the remander functor providing same lind of facilities as div

       With two parameters rem(a, b) is equivalent to  rem(fix, a, b)are equivalent, but rem can admit
       an option first parameter that modify its behaviour and moreover use the fast_ decorator if
       limiting case values are not a problem.

       The option parameter can be chosen between ceil, floor, fix;, round, round2even and if opt is the option
       the call

         rem(opt, a, b) is equivalent to a-b*div(opt, a, b)

      For floating entries the following corner cases are handled in the following way (unless the fast_
      decorator is used and the result in these cases become undefined)
       -  if x is +/-inf , Nan is returned
       -  if x is +/-0 and y is not 0 x is returned
       -  If y is +/-0, Nan is returned
       -  If either argument is NaN, Nan is returned


  **/

  /*!
    @ingroup group-callable
    @defgroup group-callable-arithmetic Arithmetic Callable Objects
    Callable objects version of @ref group-arithmetic

    Their specific semantic limitations are similar to those of their function
    equivalents as described in the @ref group-arithmetic section.
  **/
} }

#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/arg.hpp>
#include <boost/simd/function/average.hpp>
#include <boost/simd/function/ceil.hpp>
#include <boost/simd/function/conj.hpp>
#include <boost/simd/function/correct_fma.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/dist.hpp>
#include <boost/simd/function/div.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/function/fix.hpp>
#include <boost/simd/function/floor.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/fms.hpp>
#include <boost/simd/function/fnma.hpp>
#include <boost/simd/function/fnms.hpp>
#include <boost/simd/function/hypot.hpp>
#include <boost/simd/function/iceil.hpp>
#include <boost/simd/function/ifix.hpp>
#include <boost/simd/function/ifloor.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/iround2even.hpp>
#include <boost/simd/function/iround.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/function/meanof.hpp>
#include <boost/simd/function/min.hpp>
#include <boost/simd/function/minmod.hpp>
#include <boost/simd/function/mod.hpp>
#include <boost/simd/function/modulo.hpp>
#include <boost/simd/function/modulus.hpp>
#include <boost/simd/function/oneminus.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/rem.hpp>
#include <boost/simd/function/remquo.hpp>
#include <boost/simd/function/round2even.hpp>
#include <boost/simd/function/round.hpp>
#include <boost/simd/function/rsqrt.hpp>
#include <boost/simd/function/signbit.hpp>
#include <boost/simd/function/sqr_abs.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/sqrt1pm1.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/function/tenpower.hpp>
#include <boost/simd/function/tofloat.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/touint.hpp>
#include <boost/simd/function/trunc.hpp>
#include <boost/simd/function/two_add.hpp>
#include <boost/simd/function/two_prod.hpp>
#include <boost/simd/function/two_split.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/function/unary_plus.hpp>


#endif
