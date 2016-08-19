//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_POSMIN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POSMIN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing posmin capabilities

    Returns the index of the first occurence of least element of the SIMD vector

    @par Semantic:

    For every parameter of type T

    @code
    std::size_t r = posmin(x);
    @endcode

    is similar to:

    @code
      T m =  minimum(x);
      std::size_t r;
      for(std::size_t i=0; i < cardinal_of<T>; i++)
        if (m == x[i]) { r = i;  break; }
    @endcode

  **/
  std::size_t posmin(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/posmin.hpp>
#include <boost/simd/function/simd/posmin.hpp>

#endif
