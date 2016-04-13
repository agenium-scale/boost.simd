//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_DOWNBREAK_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_DOWNBREAK_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/dispatch/meta/downgrade.hpp>

namespace boost { namespace simd { namespace detail
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  template < class T>  struct downbreak
  {
    using stype =  bd::scalar_of_t<T>;
    using sdtype = bd::downgrade_t<stype>;
    using type = pack<sdtype, bs::cardinal_of<T>::value*2>;
  };
  template < class T>  struct downbreaks
  {
    using stype =  bd::scalar_of_t<T>;
    using sdtype = bd::downgrade_t<stype, signed>;
    using type = pack<sdtype, bs::cardinal_of<T>::value*2>;
  };
  template < class T>  struct downbreaku
  {
    using stype =  bd::scalar_of_t<T>;
    using sdtype = bd::downgrade_t<stype, unsigned>;
    using type = pack<sdtype, bs::cardinal_of<T>::value*2>;
  };

  template < typename T>
  using downbreak_t = typename downbreak<T>::type;
  template < typename T>
  using downbreaks_t = typename downbreaks<T>::type;
  template < typename T>
  using downbreaku_t = typename downbreaku<T>::type;
} } }

#endif
