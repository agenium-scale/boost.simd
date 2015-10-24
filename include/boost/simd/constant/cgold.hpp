//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_CGOLD_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_CGOLD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generates the conjugate golden ratio that is\f$\bar\phi = \frac{1-\sqrt5}{2}\f$

    @par Semantic:

    @code
    T r = Cgold<T>();
    @endcode

    is similar to:

    @code
    T r = (1-sqrt(T(5)))/2;
    @endcode

    @return The Cgold constant for the proper type
  **/
  template<typename T> T Cgold();

  namespace functional
  {
    /*!
      @ingroup group-callable-constant
      Generate the  constant cgold.

      @return The Cgold constant for the proper type
    **/
    const boost::dispatch::functor<tag::cgold_> cgold = {};
  }
} }
#endif

#include <boost/simd/constant/definition/cgold.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
