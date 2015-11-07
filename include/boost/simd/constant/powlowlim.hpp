//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_POWLOWLIM_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_POWLOWLIM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-constant

    Generates constant powlowlim

    @par Semantic:

    @code
    T r = powlowlim<T>();
    @endcode


**/
  template<typename T> T Powlowlim();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant


      Generates constant powlowlim

      Generate the  constant powlowlim.

      @return The Powlowlim constant for the proper type
    **/
    const boost::dispatch::functor<tag::powlowlim_> powlowlim = {};
  }
} }
#endif

#include <boost/simd/constant/definition/powlowlim.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
