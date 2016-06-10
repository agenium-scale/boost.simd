//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DECORATOR_HPP_INCLUDED
#define BOOST_SIMD_DECORATOR_HPP_INCLUDED

namespace boost { namespace simd
{
#if defined(DOXYGEN_ONLY)
  /*!
    @ingroup group-functions
    @defgroup group-decorator  Decorators


    @par Rationale
       Up to now we have six different decarotors that can be used to modify the behaviour of some functors.

       if a decorator `foo_` has to be called to modify the functor `bar` the call

         @code
          z = bar(x);
         @endcode

         has to be replaced by

         @code
          z = foo_(bar)(x);
         @endcode



      TO COMPLETE by joel perhaps

    @par provided decorators
    - fast_

      The `fast_` decorator means that the user calls a version of the functor
      that can do agressive optimization at the lost of certain properties or corner cases of the original
      functor of the `fast_math` kind.

      TO DO list and example

    - raw_

      The `raw_` decorator is used to grant access to low-evel,  low-accuracy intrinsics
      provided by some SIMD architectures.

      TO DO list and example

    - restricted_

      The `restricted_` decorator is used to restrict the range of validity of some functors
      (thus avoiding possible test and branches), but ensures an as accurate though  speedier version on the range.

      TO DO list and example

    - saturated_

      The `saturated_` decorator is used to provide a saturated version of some functors
      when producing integral typed values on return.


      This is peculiarly interesting in SIMD mode, as unlike scalars, SIMD @ref pack of integers are not promoted
      during current arithmetic operations which increases the overflow risks.

      TO DO list and example

    - std

      The `std_` decorator provides an easy way to use the stdlibc++ function that is duplicated by one of our functors.
      Of course in SIMD mode the standarsd function is automapped on packs and no SIMD speed can be gained..


      This is only a convenience feature for people which sometimes have to stick/test the standard
      behaviour against **Boost.SIMD**.

      TO DO list and example

    - conformant_

      The `conformant_` decorator if associated to std_ if it is available it gives a slower version of the algorithm,
      but that is fully conformant to the standard requirements.

      Up to now only @ref min and @max can use the conformant_ decorator to avoid @ref Nan related corner cases on some
      architectures as vmx..

  **/

} }
#endif

#include <boost/simd/function/conformant.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/function/restricted.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/std.hpp>

#endif
