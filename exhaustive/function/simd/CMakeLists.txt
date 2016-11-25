## -------------------------------------------------------------------------------------------------
##                              Copyright 2016 - NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## -------------------------------------------------------------------------------------------------

set(SOURCES
abs.cpp
acos.cpp
acos.pedantic.cpp
acosd.cpp
acospi.cpp
acot.cpp
acotd.cpp
acotpi.cpp
acsc.cpp
acscd.cpp
acscpi.cpp
arg.cpp
asec.cpp
asecd.cpp
asecpi.cpp
asin.cpp
asind.cpp
asinpi.cpp
atan.cpp
atand.cpp
atanpi.cpp
cbrt.cpp
ceil.cpp
conj.cpp
cos.cpp
cosd.cpp
cospi.cpp
cot.cpp
cotd.cpp
cotpi.cpp
dec.cpp
erf.cpp
exp10.cpp
exp2.cpp
exp.cpp
expm1.cpp
exprecnegc.cpp
exprecneg.cpp
floor.cpp
frac.cpp
genmaskc.cpp
if_one_else_zero.cpp
if_zero_else_one.cpp
inc.cpp
indeg.cpp
inrad.cpp
log10.cpp
log1p.cpp
log2.cpp
log.cpp
nthroot.cpp
oneminus.cpp
rec.cpp
rec.fast.cpp
rsqrt.cpp
sign.cpp
signnz.cpp
sinc.cpp
sincpi.cpp
sin.cpp
sind.cpp
sinhc.cpp
sinpi.cpp
sqr_abs.cpp
sqr.cpp
sqrt1pm1.cpp
sqrt.cpp
tan.cpp
tand.cpp
tanpi.cpp
unary_minus.cpp
unary_plus.cpp
 )

make_exhaustive("function.simd" ${SOURCES})

















