//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_POW2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_FUNCTION_SCALAR_POW2_HPP_INCLUDED

#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

#include <boost/assert.hpp>
#include <nt2/include/constants/one.hpp>
#include <nt2/include/functions/simd/fast_ldexp.hpp>
#include <nt2/include/functions/simd/toint.hpp>

#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/operator/functions/details/assert_utils.hpp>
#include <nt2/include/functions/simd/is_finite.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_IMPLEMENT  ( pow2_, tag::cpu_
                            , (A0)(A1)
                            , (generic_< floating_<A0> >)
                              (generic_< integer_<A1> >)
                            )
  {
    typedef A0 result_type;

    NT2_FUNCTOR_CALL(2)
    {
      return nt2::fast_ldexp(a0, a1);
    }
  };

  BOOST_DISPATCH_IMPLEMENT  ( pow2_, tag::cpu_
                            , (A0)
                            , (generic_< floating_<A0> >)
                              (generic_< floating_<A0> >)
                            )
  {

    typedef A0 result_type;

    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      #ifndef BOOST_SIMD_NO_INVALIDS
      BOOST_ASSERT_MSG(boost::simd::assert_all(is_finite(a1)),
                       "pow2 is not defined for an invalid second parameter");
      #endif
      return nt2::fast_ldexp(a0, nt2::toint(a1));
    }
  };

  BOOST_DISPATCH_IMPLEMENT  ( pow2_, tag::cpu_
                            , (A0)(A1)
                            , (generic_< integer_<A0> >)
                              (generic_< integer_<A1> >)
                            )
  {

    typedef A0 result_type;

    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      return nt2::fast_ldexp(a0, a1);
    }
  };

  BOOST_DISPATCH_IMPLEMENT  ( pow2_, tag::cpu_
                            , (A0)
                            , (generic_< integer_<A0> >)
                            )
  {

    typedef A0 result_type;

    NT2_FUNCTOR_CALL_REPEAT(1)
    {
      return nt2::fast_ldexp(One<A0>(), a0);
    }
  };

  BOOST_DISPATCH_IMPLEMENT  ( pow2_, tag::cpu_
                            , (A0)
                            , (generic_< floating_<A0> >)
                            )
  {

    typedef A0 result_type;

    NT2_FUNCTOR_CALL_REPEAT(1)
    {
      #ifndef BOOST_SIMD_NO_INVALIDS
      BOOST_ASSERT_MSG(boost::simd::assert_all(is_finite(a0)),
                       "pow2 with one parameter is not defined for an invalid entry");
      #endif
      return nt2::fast_ldexp(One<A0>(), toint(a0));
    }
  };
} } }


#endif
