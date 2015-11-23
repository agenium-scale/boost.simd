//==================================================================================================
/*!
  @file
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_TGAMMA_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_TGAMMA_HPP_INCLUDED

#include <boost/simd/options.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/constant/real.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/function/scalar/exp.hpp>
#include <boost/simd/function/scalar/inc.hpp>
#include <boost/simd/function/scalar/is_odd.hpp>
#include <boost/simd/function/scalar/is_flint.hpp>
#include <boost/simd/function/scalar/is_lez.hpp>
#include <boost/simd/function/scalar/is_nan.hpp>
#include <boost/simd/function/scalar/itrunc.hpp>
#include <boost/simd/function/scalar/log.hpp>
#include <boost/simd/function/scalar/minusone.hpp>
#include <boost/simd/function/scalar/modf.hpp>
#include <boost/simd/function/scalar/negif.hpp>
#include <boost/simd/function/scalar/oneplus.hpp>
#include <boost/simd/function/scalar/round.hpp>
#include <boost/simd/function/scalar/rec.hpp>
#include <boost/simd/function/scalar/sinpi.hpp>
#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/function/scalar/is_nan.hpp>
#endif
#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/function/scalar/is_inf.hpp>
#include <boost/simd/function/scalar/signnz.hpp>
#endif
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( tgamma_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 x) const BOOST_NOEXCEPT
    {
      if (x == Minf<A0>()) return Nan<A0>();
      if (is_nan(x)) return x;
      if (is_eqz(x)) return rec(x);
      A0 xbig =  Real<A0,0x406573f7ced91687ll,0x420c28f6>();
      A0 res = Zero<A0>();
      A0 fact = One<A0>();
      bool parity =  false;
      int n = 0;
      A0 y = x;
      A0 y1;
      if (is_ltz(y))
      {
        y = -x;
        res = modf(y, y1);
        if (is_nez(res))
        {
          parity = is_odd(y1);
          fact = -Pi<A0>()/sinpi(res, bs::small_); // res is between 0 and 1
          y =  inc(y);
        }
        else
          return Nan<A0>();
      }
      if(y < Eps<A0>())
      {
        if (y >= Smallestposval<A0>())
          res = rec(y);
        else
          return Inf<A0>();
      }
      else if (y < Ratio<A0, 12>())
      {
        A0 z;
        y1 = y;
        if(y < One<A0>())
        {
          z = y;
          y =  inc(y);
        }
        else
        {
          n = minusone(itrunc(y));
          y -= n;
          z = minusone(y);
        }
        A0 xnum = Zero<A0>();
        A0 xden = One<A0>();

        A0 p[8] = {-1.71618513886549492533811E+0,2.47656508055759199108314E+1,
                   -3.79804256470945635097577E+2,6.29331155312818442661052E+2,
                   8.66966202790413211295064E+2,-3.14512729688483675254357E+4,
                   -3.61444134186911729807069E+4,6.64561438202405440627855E+4
        };
        A0 q[8] = {-3.08402300119738975254353E+1,3.15350626979604161529144E+2,
                   -1.01515636749021914166146E+3,-3.10777167157231109440444E+3,
                   2.25381184209801510330112E+4,4.75584627752788110767815E+3,
                   -1.34659959864969306392456E+5,-1.15132259675553483497211E+5
        };

        for(int i=0; i <8 ; ++i)
        {
          xnum = (xnum + p[i]) * z;
          xden = xden * z + q[i];
        }
        res = oneplus( xnum / xden);
        if  (y1 < y)
        {
          res/= y1;
        }
        else if (y1 > y)
        {
          for(int i=0; i < n ; ++i)
          {
            res*= y;
            y = inc(y);
          }
        }
      }
      else // arg > 12
      {
        if (y <= xbig)
        {
          A0 c[7] = {-1.910444077728E-03,8.4171387781295E-04,
                     -5.952379913043012E-04,7.93650793500350248E-04,
                     -2.777777777777681622553E-03,8.333333333333333331554247E-02,
                     5.7083835261E-03
          };

          A0 ysq = rec(sqr(y));
          A0 sum = c[6];
          for(int i=0; i < 6 ; ++i)
          {
            sum = sum * ysq + c[i];
          }
          sum = sum/y - y + Real<A0,0x3fed67f1c864beb5ll,0x3f6b3f8e>();
          sum = fma(y-Half<A0>(), log(y), sum);
          res = exp(sum);
        }
        else
        {
          return Inf<A0>();
        }
      }
      res = negif(parity, res);
      if (fact !=  One<A0>()) res = fact/res;
      if (is_flint(x)) return round(res);
      return res;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( tgamma_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bs::std_tag
                          )
  {
    BOOST_FORCEINLINE A0 operator() (A0 a0, std_tag const&) const BOOST_NOEXCEPT
    {
      return std::tgamma(a0);
    }
  };
} } }


#endif
