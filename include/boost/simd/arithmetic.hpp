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

    Those functions provides scalar and SIMD algorithms for classical arithmetic operators and
    functions provided by the C and C++ standard library. Other functions like, in particular,
    provision for saturated operations are also provided.

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
#include <boost/simd/function/abs_s.hpp>
#include <boost/simd/function/angle.hpp>
#include <boost/simd/function/arg.hpp>
#include <boost/simd/function/average.hpp>
#include <boost/simd/function/ceil.hpp>
#include <boost/simd/function/conj.hpp>
#include <boost/simd/function/correct_fma.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/dec_s.hpp>
#include <boost/simd/function/dist.hpp>
#include <boost/simd/function/dist_s.hpp>
#include <boost/simd/function/div.hpp>
#include <boost/simd/function/divide_s.hpp>
#include <boost/simd/function/drem.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/function/fabs.hpp>
#include <boost/simd/function/fix.hpp>
#include <boost/simd/function/floor.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/fmod.hpp>
#include <boost/simd/function/fms.hpp>
#include <boost/simd/function/fnma.hpp>
#include <boost/simd/function/fnms.hpp>
#include <boost/simd/function/hypot.hpp>
#include <boost/simd/function/iceil.hpp>
#include <boost/simd/function/idiv.hpp>
#include <boost/simd/function/ifix.hpp>
#include <boost/simd/function/ifloor.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/inc_s.hpp>
#include <boost/simd/function/iround2even.hpp>
#include <boost/simd/function/iround.hpp>
#include <boost/simd/function/itrunc.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/function/meanof.hpp>
#include <boost/simd/function/min.hpp>
#include <boost/simd/function/minmod.hpp>
#include <boost/simd/function/minusone.hpp>
#include <boost/simd/function/minusone_s.hpp>
#include <boost/simd/function/minus_s.hpp>
#include <boost/simd/function/mod.hpp>
#include <boost/simd/function/modulo.hpp>
#include <boost/simd/function/modulus.hpp>
#include <boost/simd/function/multiplie_s.hpp>
#include <boost/simd/function/neg.hpp>
#include <boost/simd/function/neg_s.hpp>
#include <boost/simd/function/oneminus.hpp>
#include <boost/simd/function/oneminus_s.hpp>
#include <boost/simd/function/oneplus.hpp>
#include <boost/simd/function/oneplus_s.hpp>
#include <boost/simd/function/plus_s.hpp
#include <boost/simd/function/rdivide.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/remainder.hpp>
#include <boost/simd/function/remfix.hpp>
#include <boost/simd/function/rem.hpp>
#include <boost/simd/function/remquo.hpp>
#include <boost/simd/function/remround.hpp>
#include <boost/simd/function/rint.hpp>
#include <boost/simd/function/round2even.hpp>
#include <boost/simd/function/round.hpp>
#include <boost/simd/function/rsqrt.hpp>
#include <boost/simd/function/signbit.hpp>
#include <boost/simd/function/sqr_abs.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/sqr_s.hpp>
#include <boost/simd/function/sqrt1pm1.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/function/tenpower.hpp>
#include <boost/simd/function/tofloat.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/toint_s.hpp>
#include <boost/simd/function/touint.hpp>
#include <boost/simd/function/touint_s.hpp>
#include <boost/simd/function/trunc.hpp>
#include <boost/simd/function/two_add.hpp>
#include <boost/simd/function/two_prod.hpp>
#include <boost/simd/function/two_split.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/function/unary_minus_s.hpp>
#include <boost/simd/function/unary_plus.hpp>


#endif
