//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_BITWISE_HPP_INCLUDED
#define BOOST_SIMD_BITWISE_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-bitwise Bitwise functions

      These functions provides scalar and SIMD implementations of bit manipulations and bitwise
      operators. Bitwise operations are provided alongside more specific ones such as bit-level rotations,
      bit set, get and toggling and mapping for compiler-specific first bit set or population count
      operations.

      Note that bitwise function operators may accept IEEE types as arguments. The implied semantic
      is then that the operations are applied to the IEEE bit patterns.

      Be also aware that all binary bitwise functions return a result of the type of the first argument
      and that the second argument must only have the same number of bits of the first.
  **/

  /*!
    @ingroup group-callable
    @defgroup group-callable-bitwise Bitwise Callable Objects
    Callable objects version of @ref group-bitwise

    Their specific semantic limitations are similar to those of their function
    equivalents as described in the @ref group-bitwise section.
  **/
} }

#include <boost/simd/function/bitget.hpp>
#include <boost/simd/function/bitset.hpp>
#include <boost/simd/function/bits.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_andnot.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/bitwise_notand.hpp>
#include <boost/simd/function/bitwise_notor.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/bitwise_ornot.hpp>
#include <boost/simd/function/bitwise_select.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/clz.hpp>
#include <boost/simd/function/ctz.hpp>
#include <boost/simd/function/ffs.hpp>
#include <boost/simd/function/firstbitset.hpp>
#include <boost/simd/function/firstbitunset.hpp>
#include <boost/simd/function/genmaskc.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/hi.hpp>
#include <boost/simd/function/ilog2.hpp>
#include <boost/simd/function/lo.hpp>
#include <boost/simd/function/popcnt.hpp>
#include <boost/simd/function/reversebits.hpp>
#include <boost/simd/function/rol.hpp>
#include <boost/simd/function/ror.hpp>
#include <boost/simd/function/rrol.hpp>
#include <boost/simd/function/rror.hpp>
#include <boost/simd/function/rshl.hpp>
#include <boost/simd/function/rshr.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/simd/function/swapbytes.hpp>
#include <boost/simd/function/twopower.hpp>

#endif
