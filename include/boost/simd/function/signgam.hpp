//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIGNGAM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIGNGAM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
  @ingroup group-euler
    This function object computes the sign of gamma function

    @c signgam does not computes @ref gamma and is fast.

    @see gamma, gammaln

    @par Example:

       @snippet stirling.cpp stirling

    @par Possible output:

       @snippet stirling.txt stirling
  **/
  Value signgam(Value const & x);
} }
#endif

#include <boost/simd/function/scalar/signgam.hpp>
//#include <boost/simd/function/simd/signgam.hpp>

#endif
