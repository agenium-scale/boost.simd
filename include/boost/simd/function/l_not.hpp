//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_L_NOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_L_NOT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-operator

    return the logical negation of the parameter,
    i.e. True or False of the logical type associated entry type according that
    the input is @ref Zero or non @ref Zero (False or True).

    Infix notation can be used with operator '!'

    This is a convenient alias of @ref logical_not
**/
  template<typename T> auto l_not(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      return the logical negation of the parameter,
      i.e. True or False of the logical type associated entry type according that
      the input is @ref Zero or non @ref Zero (False or True).


      Function object tied to simd::l_not

      @see simd::l_not
    **/
    const boost::dispatch::functor<tag::l_not_> l_not = {};
  }
} }
#endif

#include <boost/simd/function/definition/l_not.hpp>
#include <boost/simd/arch/common/scalar/function/logical_not.hpp>
#include <boost/simd/function/simd/l_not.hpp>

#endif
