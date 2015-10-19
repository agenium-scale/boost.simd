//==================================================================================================
/*!
  @file

  Convenience header for Boost.SIMD

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_HPP_INCLUDED
#define BOOST_SIMD_HPP_INCLUDED

#include <boost/simd/arch.hpp>
#include <boost/simd/math.hpp>
#include <boost/simd/config.hpp>

/// Main Boost namespace
namespace boost
{
  /// Main Boost.SIMD namespace
  namespace simd
  {
    /*!
      @defgroup group-api User API
      Public user API provided by the library
    **/

    /*!
      @defgroup group-config Configuration
      Configuration options for the library
    **/

    /*!
      @defgroup group-hierarchy Hierarchies
      Type hierarchies defined by the library
    **/

    namespace concept
    {
      /*!
        @defgroup group-concept Concepts
        Concepts defined by the library
      **/
    }

    namespace ext
    {
      /*!
        @defgroup group-ext Library extension points
        USer specilizable elements of the library
      **/
    }

    namespace detail
    {
      /*!
        @defgroup group-detail Implementation details
        Implementation details
      **/
    }

  }
}

#endif
