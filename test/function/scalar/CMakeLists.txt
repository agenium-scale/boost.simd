##===================================================================================================
##                 Copyright 2012 - 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
#memory
   extract.cpp
   splat.cpp
#alias
   modulus.cpp
#arithmetic
   abs.cpp
   abss.cpp
   adds.cpp
   arg.cpp
   average.cpp
   ceil.cpp
#   chop.cpp
   conj.cpp
   correct_fma.cpp
   dec.cpp
   dist.cpp
   dists.cpp
   divceil.cpp
   divfix.cpp
   divfloor.cpp
   divround2even.cpp
   divround.cpp
   divs.cpp
#   fast_hypot.cpp
#   fast_iround2even.cpp
#   fast_rec.cpp
#   fast_sqrt.cpp
#   fast_toint.cpp
   floor.cpp
   fma.cpp
   fms.cpp
   fnma.cpp
   fnms.cpp
   hypot.cpp
   iceil.cpp
   idivceil.cpp
   idivfix.cpp
   idivfloor.cpp
   idivround2even.cpp
   idivround.cpp
   ifloor.cpp
   inc.cpp
   iround2even.cpp
   iround.cpp
   logical_xor.cpp
   max.cpp
   meanof.cpp
   min.cpp
   minmod.cpp
   minusone.cpp
   mod.cpp
   muls.cpp
   negs.cpp
   oneminus.cpp
   oneplus.cpp
#   raw_rec.cpp
   rec.cpp
#   refine_rec.cpp
   remainder.cpp
   rem.cpp
   remquo.cpp
   remround.cpp
   round2even.cpp
   round.cpp
   rsqrt.cpp
   sqr_abs.cpp
   sqr.cpp
   sqrs.cpp
   sqrt.cpp
   subs.cpp
   tenpower.cpp
   tofloat.cpp
   toint.cpp
   toints.cpp
   touint.cpp
   touints.cpp
   trunc.cpp
   two_add.cpp
   two_prod.cpp
   two_split.cpp
#bitwise
   bitget.cpp
   bitset.cpp
   bits.cpp
   bitwise_andnot.cpp
   bitwise_cast.cpp
   bitwise_notand.cpp
   bitwise_notor.cpp
   bitwise_ornot.cpp
   bitwise_select.cpp
   clz.cpp
   ctz.cpp
   ffs.cpp
   firstbitset.cpp
   firstbitunset.cpp
   genmaskc.cpp
   genmask.cpp
   hi.cpp
   ilog2.cpp
   lo.cpp
   popcnt.cpp
   reversebits.cpp
   rol.cpp
   ror.cpp
   rrol.cpp
   rror.cpp
   rshl.cpp
   rshr.cpp
   shr.cpp
   swapbytes.cpp
   twopower.cpp
#boolean
   if_allbits_else.cpp
   if_else_allbits.cpp
   if_else_zero.cpp
   ifnotadd.cpp
   ifnotdec.cpp
   ifnotinc.cpp
   ifnotsub.cpp
   if_one_else_zero.cpp
   if_zero_else.cpp
   if_zero_else_one.cpp
   logical_andnot.cpp
   logical_notand.cpp
   logical_notor.cpp
   logical_ornot.cpp
   mask2logical.cpp
   negif.cpp
   negifnot.cpp
   seladd.cpp
   seldec.cpp
   selinc.cpp
   selsub.cpp
#ieee
   bitfloating.cpp
   bitinteger.cpp
   bitofsign.cpp
   copysign.cpp
   eps.cpp
   exponentbits.cpp
   exponent.cpp
#   fast_frexp.cpp
#   fast_ldexp.cpp
   frac.cpp
   frexp.cpp
   ilogb.cpp
   ldexp.cpp
   mantissa.cpp
   maxmag.cpp
   maxnum.cpp
   maxnummag.cpp
   minmag.cpp
   minnum.cpp
   minnummag.cpp
   modf.cpp
   negate.cpp
   negatenz.cpp
   nextafter.cpp
   next.cpp
   nextpow2.cpp
   predecessor.cpp
   prev.cpp
   safe_max.cpp
   safe_min.cpp
#   saturate_at.cpp
   saturate.cpp
   sbits.cpp
   sign.cpp
   signnz.cpp
   successor.cpp
   ulpdist.cpp
   ulp.cpp
#operator
   bitwise_and.cpp
   bitwise_or.cpp
   bitwise_xor.cpp
   comma.cpp
   complement.cpp
   divides.cpp
#   fast_divides.cpp
   if_else.cpp
   is_equal.cpp
   is_greater_equal.cpp
   is_greater.cpp
   is_less_equal.cpp
   is_less.cpp
   is_not_equal.cpp
   logical_and.cpp
   logical_not.cpp
   logical_or.cpp
#   map.cpp
   minus.cpp
   modulo.cpp
   multiplies.cpp
   plus.cpp
   shift_left.cpp
   shift_right.cpp
   unary_minus.cpp
   unary_plus.cpp
#predicates
   is_denormal.cpp
   is_equal_with_equal_nans.cpp
   is_eqz.cpp
   is_even.cpp
   is_finite.cpp
   is_flint.cpp
   is_gez.cpp
   is_gtz.cpp
   is_imag.cpp
   is_inf.cpp
   is_invalid.cpp
   is_lez.cpp
   is_ltz.cpp
   is_nan.cpp
   is_negative.cpp
   is_nez.cpp
   is_ngez.cpp
   is_ngtz.cpp
   is_nlez.cpp
   is_nltz.cpp
   is_not_denormal.cpp
   is_not_equal_with_equal_nans.cpp
   is_not_finite.cpp
   is_not_greater_equal.cpp
   is_not_greater.cpp
   is_not_imag.cpp
   is_not_infinite.cpp
   is_not_less_equal.cpp
   is_not_less.cpp
   is_not_nan.cpp
   is_not_real.cpp
   is_odd.cpp
   is_ord.cpp
   is_positive.cpp
   is_real.cpp
   is_unord.cpp
   majority.cpp
#reduction
   all.cpp
   any.cpp
   compare_equal.cpp
   compare_greater_equal.cpp
   compare_greater.cpp
   compare_less_equal.cpp
   compare_less.cpp
   compare_not_equal.cpp
   dot.cpp
   hmsb.cpp
   inbtrue.cpp
   is_included_c.cpp
   is_included.cpp
   is_simd_logical.cpp
   maximum.cpp
   minimum.cpp
   nbtrue.cpp
   none.cpp
   posmax.cpp
   posmin.cpp
   prod.cpp
   sum.cpp
#swar
#   all_reduce.cpp
   broadcast.cpp
#   combine.cpp
   cummax.cpp
   cummin.cpp
   cumprod.cpp
   cumsum.cpp
#   deinterleave_first.cpp
#   deinterleave_second.cpp
   enumerate.cpp
#   group.cpp
#   groups.cpp
#   interleave_first.cpp
#   interleave_second.cpp
   lookup.cpp
#   repeat_lower_half.cpp
#   repeat_upper_half.cpp
   reverse.cpp
#   shuffle.cpp
#   slice.cpp
   sort.cpp
   splatted_maximum.cpp
   splatted_minimum.cpp
   splatted_prod.cpp
   splatted_sum.cpp
#   split_high.cpp
#   split.cpp
#   split_low.cpp
#   split_multiplies.cpp
  )

make_unit( "boost.simd.function.scalar"     ${SOURCES})
make_coverage("boost.simd.function.scalar"  ${SOURCES})
