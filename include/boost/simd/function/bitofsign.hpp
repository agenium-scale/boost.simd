//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITOFSIGN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITOFSIGN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns a value of the same type as the input with all bits set to zero
    except the bit of sign which is preserved.

    Returns always @ref Zero for unsigned types

    @par Semantic:

    @code
    T r = bitofsign(x);
    @endcode

    for signed types is similar to:

    @code
    T r = x&SignMask;
    @endcode

    @see sign, signnz

    @return a value of same type as the input

**/
  template<typename T> auto bitofsign(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns a value of the same type as the input with all bits set to zero
      except the bit of sign which is preserved.


      Function object tied to simd::bitofsign

      @see simd::bitofsign
    **/
    const boost::dispatch::functor<tag::bitofsign_> bitofsign = {};
  }
} }
#endif

#include <boost/simd/function/definition/bitofsign.hpp>
#include <boost/simd/arch/common/scalar/function/bitofsign.hpp>
#include <boost/simd/function/simd/bitofsign.hpp>

#endif
