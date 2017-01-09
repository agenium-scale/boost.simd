//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACSCH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACSCH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-hyperbolic
    Ths function object returns the hyperbolic cosecant argument \f$\mathop{\textrm{asinh}}(1/x)\f$

     @see cosh, sinh,  acosh, asinh, atanh, asech, acoth, atanh

    @par Example:

       @snippet atanh.cpp atanh

    @par Possible output:

       @snippet atanh.txt atanh


  **/
  Value acsch(Value const & x);
} }
#endif

#include <boost/simd/function/scalar/acsch.hpp>
#include <boost/simd/function/simd/acsch.hpp>

#endif
