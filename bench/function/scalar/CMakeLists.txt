## -------------------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## -------------------------------------------------------------------------------------------------

set(SOURCES
    abs.cpp
    abs_s.cpp
    acos.cpp
    acos.accurate.cpp
    acosd.cpp
    acospi.cpp
    acosh.cpp
    acot.cpp
    acotd.cpp
    acoth.cpp
    acotpi.cpp
    acsc.cpp
    acscd.cpp
    acsch.cpp
    acscpi.cpp
    all.cpp
    any.cpp
    arg.cpp
    asec.cpp
    asecd.cpp
    asech.cpp
    asecpi.cpp
    asin.cpp
    asind.cpp
    asinh.cpp
    asinpi.cpp
    atan2.cpp
    atan2d.cpp
    atan2pi.cpp
    atan.cpp
    atand.cpp
    atanh.cpp
    atanpi.cpp
    average.cpp
    bitfloating.cpp
    bitget.cpp
    bitinteger.cpp
    bitset.cpp
    bitwise_and.cpp
    bitwise_andnot.cpp
#######    bitwise_cast.cpp
    bitwise_notand.cpp
    bitwise_notor.cpp
    bitwise_or.cpp
    bitwise_ornot.cpp
#######      bitwise_select.cpp
    bitwise_xor.cpp
    broadcast.cpp
    cbrt.cpp
    ceil.cpp
    clz.cpp
    compare_equal.cpp
    compare_greater.cpp
    compare_greater_equal.cpp
    compare_less.cpp
    compare_less_equal.cpp
    compare_not_equal.cpp
    complement.cpp
    conj.cpp
    copysign.cpp
    cos.cpp
    cosd.cpp
    cosh.cpp
    cospi.cpp
    cot.cpp
    cotd.cpp
    coth.cpp
    cotpi.cpp
    cscd.cpp
    csch.cpp
    cscpi.cpp
    csc.cpp
    ctz.cpp
    dec.cpp
    dec_s.cpp
#    deinterleave_first.cpp
#    deinterleave_second.cpp
    dist.cpp
    dist_s.cpp
    divides.cpp
    divides_s.cpp
    dot.cpp
#    enumerate.cpp
    erf.cpp
    erfc.cpp
    exp2.cpp
    exp.cpp
    exp.std.cpp
    expm1.cpp
    exprecnegc.cpp
    exprecneg.cpp
    expx2.cpp
    exp10.cpp
    fast.frexp.cpp
    fast.hypot.cpp
    fast.rec.cpp
    fast.rem.cpp
    fast.rsqrt.cpp
    fast.sqrt.cpp
    fast.trunc.cpp
    ffs.cpp
    firstbitset.cpp
    firstbitunset.cpp
    floor.cpp
    fma.cpp
    correct_fma.cpp
    fms.cpp
    fnma.cpp
    fnms.cpp
    fpclassify.cpp
    frac.cpp
    frexp.cpp
    gammaln.cpp
    genmask.cpp
    genmaskc.cpp
##########    group.cpp
##########    groups.cpp
    hi.cpp
    hmsb.cpp
    hypot.cpp
    iceil.cpp
    if_allbits_else.cpp
    if_else_allbits.cpp
    if_else.cpp
    if_dec.cpp
    if_inc.cpp
    if_else_zero.cpp
    ifloor.cpp
     ifnot_plus.cpp
    ifnot_dec.cpp
    ifnot_inc.cpp
     ifnot_minus.cpp
    if_one_else_zero.cpp
    if_zero_else.cpp
    if_zero_else_one.cpp
    ilog2.cpp
    ilogb.cpp
    inc.cpp
    inc_s.cpp
    indeg.cpp
    inrad.cpp
#   interleave_even.cpp
#    interleave_first.cpp
#    interleave_odd.cpp
#    interleave_second.cpp
    iround.cpp
    is_denormal.cpp
    is_equal.cpp
    is_equal_with_equal_nans.cpp
    is_eqz.cpp
    is_even.cpp
    is_finite.cpp
    is_flint.cpp
    is_gez.cpp
    is_greater.cpp
    is_greater_equal.cpp
    is_gtz.cpp
    is_imag.cpp
    is_included_c.cpp
    is_included.cpp
    is_inf.cpp
    is_invalid.cpp
    is_less.cpp
    is_less_equal.cpp
    is_lessgreater.cpp
    is_lez.cpp
    is_ltz.cpp
    is_nan.cpp
    is_negative.cpp
    is_nez.cpp
    is_ngez.cpp
    is_ngtz.cpp
    is_nlez.cpp
    is_nltz.cpp
    is_normal.cpp
    is_not_denormal.cpp
    is_not_equal.cpp
    is_not_equal_with_equal_nans.cpp
    is_not_greater.cpp
    is_not_greater_equal.cpp
    is_not_infinite.cpp
    is_not_less.cpp
    is_not_less_equal.cpp
    is_not_nan.cpp
    is_not_real.cpp
    is_odd.cpp
    is_ord.cpp
    is_positive.cpp
    is_real.cpp
    is_unord.cpp
    ldexp.cpp
    lo.cpp
    log10.cpp
    log1p.cpp
    log2.cpp
    log.cpp
    logical_and.cpp
    logical_andnot.cpp
    logical_notand.cpp
    logical_not.cpp
    logical_notor.cpp
    logical_or.cpp
    logical_ornot.cpp
    logical_xor.cpp
#    lookup.cpp
    majority.cpp
    mantissa.cpp
    max.cpp
    maxmag.cpp
    maxnum.cpp
    maxnummag.cpp
    meanof.cpp
    min.cpp
    minmag.cpp
    minmod.cpp
    minnum.cpp
    minnummag.cpp
    minus.cpp
    minus_s.cpp
    modf.cpp
    multiplies.cpp
    multiplies_s.cpp
    nbtrue.cpp
    negate.cpp
    negatenz.cpp
    negif.cpp
    negifnot.cpp
    nextafter.cpp
    next.cpp
    none.cpp
    nthroot.cpp
    oneminus.cpp
    oneminus_s.cpp
    plus.cpp
    plus_s.cpp
    pow2.cpp
    pow_abs.cpp
    pow.cpp
    predecessor.cpp
    prev.cpp
    rec.cpp
    rem.cpp
    rem_pio2_cephes.cpp
    rem_pio2.cpp
    rem_pio2_medium.cpp
    rem_pio2_straight.cpp
    remquo.cpp
#    repeat_lower_half.cpp
#    repeat_upper_half.cpp
    restricted.cosd.cpp
    restricted.cos.cpp
    restricted.cospi.cpp
    restricted.cotd.cpp
    restricted.cot.cpp
    restricted.cotpi.cpp
    restricted.cscd.cpp
    restricted.csc.cpp
    restricted.cscpi.cpp
    restricted.secd.cpp
    restricted.sec.cpp
    restricted.secpi.cpp
    restricted.sincosd.cpp
    restricted.sincos.cpp
    restricted.sincospi.cpp
    restricted.sind.cpp
    restricted.sin.cpp
    restricted.sinpi.cpp
    restricted.tand.cpp
    restricted.tan.cpp
    restricted.tanpi.cpp
    reversebits.cpp
    reverse.cpp
#    rol.cpp
#    ror.cpp
    nearbyint.cpp
    round.cpp
#    rrol.cpp
#    rror.cpp
    rsqrt.cpp
    safe_max.cpp
    safe_min.cpp
    secd.cpp
    sech.cpp
    secpi.cpp
    sec.cpp
    shift_left.cpp
    shift_right.cpp
#    shr1.cpp
    sign.cpp
    significants.cpp
    signnz.cpp
    sinc.cpp
    sincos.cpp
    sincosd.cpp
    sincospi.cpp
    sincpi.cpp
    sin.cpp
    sind.cpp
    sinh.cpp
    sinhc.cpp
    sinhcosh.cpp
    sinpi.cpp
#    splatted_maximum.cpp
#    splatted_minimum.cpp
#    split_multiplies.cpp
    sqr_abs.cpp
    sqr.cpp
    sqr_s.cpp
    sqrt1pm1.cpp
    sqrt.cpp
    std.abs.cpp
    std.acos.cpp
    std.asin.cpp
    std.atan2.cpp
    std.atan.cpp
    std.cbrt.cpp
    std.ceil.cpp
    std.erfc.cpp
    std.erf.cpp
    std.exp2.cpp
    std.exp.cpp
    std.expm1.cpp
    std.fma.cpp
    std.fpclassify.cpp
    std.frexp.cpp
    std.gammaln.cpp
    std.hypot.cpp
    std.log10.cpp
    std.log2.cpp
    std.log.cpp
    std.maxnum.cpp
    std.minnum.cpp
    std.rem.cpp
    std.sqrt.cpp
    std.trunc.cpp
    successor.cpp
    tan.cpp
    tand.cpp
    tanh.cpp
    tanpi.cpp
#    tenpower.cpp
    tofloat.cpp
    toint.cpp
    toint_s.cpp
    touint.cpp
    touint_s.cpp
    trunc.cpp
########    two_add.cpp
#    twopower.cpp
########    two_prod.cpp
########    two_split.cpp
    ulpdist.cpp
    unary_minus.cpp
    unary_minus_s.cpp
    unary_plus.cpp
)

make_bench("function.scalar" ${SOURCES})
