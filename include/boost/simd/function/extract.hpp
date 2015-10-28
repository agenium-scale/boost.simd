//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXTRACT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXTRACT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Random-access extraction of a value subcomponent

    Extract a sub-element of a given value @c v

    @par Semantic

    Depending on the type of its arguments, extract exhibits different semantics.
    For any value @c v of type @c Value and @c o of type @c Offset:

    @code
    auto x = extract(v,o);
    @endcode

    is similar to:

    - If @c v is a scalar type:

      @code
      x = v;
      @endcode

    - If @c v is a SIMD type:

      @code
      x = v[o];
      @endcode

    @param v   Value to extract
    @param o   Position to extract from (offset)

    @return The extracted value

  **/
  template<typename Value, typename Offset> auto extract( Value const& v
                                                        ,  Offset const& o) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Random-access extraction of a value subcomponent


      Function object tied to simd::extract

      @see simd::extract
    **/
    const boost::dispatch::functor<tag::extract_> extract = {};
  }
} }
#endif

#include <boost/simd/function/definition/extract.hpp>
#include <boost/simd/arch/common/scalar/function/extract.hpp>
//#include <boost/simd/arch/common/function/simd/extract.hpp>

#endif
