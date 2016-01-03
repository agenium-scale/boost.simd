//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_POWLARGELIM_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_POWLARGELIM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Generates constant powlargelim

    @par Semantic:

    @code
    T r = powlargelim<T>();
    @endcode


**/
  template<typename T> T Powlargelim();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Generates constant powlargelim

      Generate the  constant powlargelim.

      @return The Powlargelim constant for the proper type
    **/
    const boost::dispatch::functor<tag::powlargelim_> powlargelim = {};
  }
} }
#endif

#include <boost/simd/constant/definition/powlargelim.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
