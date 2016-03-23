//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SPLATTED_PROD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SPLATTED_PROD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-swar
    Function object implementing splatted_prod capabilities

  **/
  const boost::dispatch::functor<tag::splatted_prod_> splatted_prod = {};
} }
#endif

#include <boost/simd/function/scalar/splatted_prod.hpp>
#include <boost/simd/function/simd/splatted_prod.hpp>

#endif
