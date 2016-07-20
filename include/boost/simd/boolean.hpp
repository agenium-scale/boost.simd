//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_BOOLEAN_HPP_INCLUDED
#define BOOST_SIMD_BOOLEAN_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-boolean Boolean functions

      Those functions provides scalar and SIMD algorithms for testing values properties.
      Tests like checks for validity, infinity, sign and others are provided. As for @ref
      group-boolean, those functions handles and returns typed logical types.
  **/

  /*!
    @ingroup group-callable
    @defgroup group-callable-boolean Boolean Callable Objects
    Callable objects version of @ref group-boolean

    Their specific semantic limitations are similar to those of their function
    equivalents as described in the @ref group-boolean section.
  **/
} }

#include <boost/simd/function/if_allbits_else.hpp>
#include <boost/simd/function/if_allbits_else_zero.hpp>
#include <boost/simd/function/if_else_allbits.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_else_nan.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/ifnot_plus.hpp>
#include <boost/simd/function/ifnot_dec.hpp>
#include <boost/simd/function/ifnot_inc.hpp>
#include <boost/simd/function/ifnot_minus.hpp>
#include <boost/simd/function/if_one_else_zero.hpp>
#include <boost/simd/function/if_zero_else_allbits.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/if_zero_else_one.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_andnot.hpp>
#include <boost/simd/function/logical_notand.hpp>
#include <boost/simd/function/logical_notor.hpp>
#include <boost/simd/function/logical_ornot.hpp>
#include <boost/simd/function/logical_xor.hpp>
#include <boost/simd/function/mask2logical.hpp>
#include <boost/simd/function/negif.hpp>
#include <boost/simd/function/negifnot.hpp>
#include <boost/simd/function/if_plus.hpp>
#include <boost/simd/function/if_dec.hpp>
#include <boost/simd/function/if_inc.hpp>
#include <boost/simd/function/if_minus.hpp>

#endif
