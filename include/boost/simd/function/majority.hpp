//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MAJORITY_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MAJORITY_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-predicates
    This function object returns @ref True if at least two inputs
    are not @ref Zero else @ref False.

    @par Semantic:

    @code
    auto r = majority(x,y,z);
    @endcode

    is similar to:

    @code
    auto r = (x!= 0)+(y!= 0)+(z!= 0) >= 2;
    @endcode

    @par Example:

       @snippet majority.cpp majority

    @par Possible output:

       @snippet majority.txt majority

  **/
  as_logical_t<Value> Value majority(Value const& x, Value const& y, Value const& z);
} }
#endif

#include <boost/simd/function/scalar/majority.hpp>
#include <boost/simd/function/simd/majority.hpp>

#endif
