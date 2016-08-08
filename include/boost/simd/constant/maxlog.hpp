//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MAXLOG_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MAXLOG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Generates constant MaxLog used in logarithm/exponential computations
    log(x) return inf if x is greater than Maxlog (overflow)

    @par Semantic:

    @code
    T r = Maxlog<T>();
    @endcode

    is similar to:

    @code
    if T is double
      r = 709.78271289338400;
    else if T is float
      r =  88.3762626647949
    @endcode

    @see Minlog


**/
  template<typename T> T Maxlog();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Generates constant MaxLog used in logarithm/exponential computations
      nt2::log(x) return inf if x is greater than Maxlog (overflow)

      Generate the  constant maxlog.

      @return The Maxlog constant for the proper type
    **/
    Value Maxlog();
  }
} }
#endif

#include <boost/simd/constant/definition/maxlog.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>
#include <boost/simd/arch/common/simd/constant/constant_value.hpp>

#endif
