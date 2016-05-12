//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ALL_REDUCE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ALL_REDUCE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-swar
    Function object implementing all_reduce capabilities

  **/
  const boost::dispatch::functor<tag::all_reduce_> all_reduce = {};
} }
#endif

#include <boost/simd/function/scalar/all_reduce.hpp>
#include <boost/simd/function/simd/all_reduce.hpp>

#endif
