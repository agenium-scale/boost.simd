##===================================================================================================
##                 Copyright 2012 - 2015   NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
# allbits.cpp
# bitincrement.cpp
# constant.cpp
# cgold.cpp
# eight.cpp
# eps.cpp
# fact_10.cpp
# fact_11.cpp
# fact_12.cpp
# fact_4.cpp
# fact_5.cpp
# fact_6.cpp
# fact_7.cpp
# fact_8.cpp
# fact_9.cpp
# false.cpp
# five.cpp
# four.cpp
# fourthrooteps.cpp
# gold.cpp
# greatestnoninteger.cpp
# half.cpp
# halfeps.cpp
# inf.cpp
# ldexpmask.cpp
# limitexponent.cpp
# log10_pi.cpp
# logeps.cpp
# logpi.cpp
# logsqrt2pi.cpp
# mantissamask.cpp
# mask1frexp.cpp
# mask2frexp.cpp
# maxexponent.cpp
# maxexponentm1.cpp
# maxflint.cpp
# maxinit.cpp
# maxleftshift.cpp
# meight.cpp
# mfive.cpp
# mfour.cpp
# mhalf.cpp
# mindenormal.cpp
# minexponent.cpp
# minf.cpp
# mlogeps2.cpp
# mnine.cpp
# mone.cpp
# mseven.cpp
# msix.cpp
# mten.cpp
# mthree.cpp
# mtwo.cpp
# mzero.cpp
# nan.cpp
# nbdigits.cpp
# nbexponentbits.cpp
# nbmantissabits.cpp
# nine.cpp
 one.cpp
# oneosqrt5.cpp
# oneosqrteps.cpp
# oneotwoeps.cpp
# pi.cpp
# pio_2.cpp
# quarter.cpp
# real.cpp
# ratio.cpp
# seven.cpp
# signmask.cpp
# six.cpp
# smallestposval.cpp
# splitfactor.cpp
# sqrt_1o_5.cpp
# sqrt_2.cpp
# sqrt_2o_2.cpp
# sqrt_2o_3.cpp
# sqrteps.cpp
# sqrtsmallestposval.cpp
# sqrtvalmax.cpp
# ten.cpp
# third.cpp
# thirdrooteps.cpp
# three.cpp
# threeeps.cpp
# true.cpp
# twoto31.cpp
# twotom10.cpp
# twotonmb.cpp
# valmax.cpp
# valmin.cpp
# zero.cpp
#exponential
# euler.cpp
# exp_1.cpp
# invexp_1.cpp
# invlog10_2.cpp
# invlog_10.cpp
# invlog_2.cpp
# log10_2hi.cpp
# log10_2lo.cpp
# log10_ehi.cpp
# log10_elo.cpp
# log_10.cpp
# log2_e.cpp
# log2_em1.cpp
# log_2hi.cpp
# log_2.cpp
# log_2lo.cpp
# log_2olog_10.cpp
# maxlog10.cpp
# maxlog2.cpp
# maxlog.cpp
# minlog10.cpp
# minlog2.cpp
# minlog.cpp
# mlog10two2nmb.cpp
# mlog2two2nmb.cpp
# mlogtwo2nmb.cpp
# powlargelim.cpp
# powlowlim.cpp
# twotomnmbo_3.cpp
  )

make_unit( "boost.simd.constant.simd"     ${SOURCES})
make_coverage("boost.simd.constant.simd"  ${SOURCES})
