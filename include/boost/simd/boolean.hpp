//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

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

      These functions provides SIMD algorithms for logical operations and branching
      in SIMD mode,  their use is possible but not encouraged on scalars entries.

      - **Logical operators**

        They provide results of @ref logical types,  can not have shortcuts and acts
        in an elementwise way on SIMD vectors.

       <center>
         | name               | name                | name              |
         |:------------------:|:-------------------:|:-----------------:|
         | @ref logical_and   | @ref logical_notand | @ref logical_ornot|
         | @ref logical_andnot| @ref logical_notor  | @ref logical_xor  |
         | @ref logical_not   | @ref logical_or     | @ref mask2logical |
        </center>

        Masks are pattern of bits all zeros or all ones that can allow masking
        using bitwise operations. @ref mask2logical provides a way to transform a mask vector
        into a logical vector.

        Logical types are architecture dependant,  for instance on intel sse or avx
        logical types are mask valued simd vectors.

      - **Branching utilities**

        Be aware that using SIMD and branching are quite antagonist.

        For instance if an SIMD vector contain more tha ne element (!) a test on the
        elements will simultaneouly provide true results for some and false results
        for other: so branching in simd resume in compute all branches and select the
        pertinent results...

        The functors listed above are mostly interesting when one of the branch is very cheap
        compared to the others.

        All branching utilities begin by if_ or ifnot_ the first parameter is a SIMD test
        pack that can be of any of any available type and for which the decision is taken
        for each element as not zero being true and zero being false and have two branches
        (implicit or explicity) to define which result will be chosen for each scalar test.

        However the functor will generally computes all the possible outcomes and select
        at last the propers ones. If each branch as the same cost (notwithstanding the cost of the test
        and the inner pipelining of the processor) a branch can cost twice the one branch...
        This become interesting only if the simd vector has a cardinal greater than 2.

       <center>
         | name                            | name                 | name                         |  name               |
         |:-------------------------------:|:--------------------:|:----------------------------:| :------------------:|
         | @ref if_allbits_else.hpp        | @ref if_else_nan.hpp | @ref if_one_else_zero.hpp    | @ref ifnot_dec.hpp  |
         | @ref if_allbits_else_zero.hpp   | @ref if_else_zero.hpp| @ref if_plus.hpp             | @ref ifnot_inc.hpp  |
         | @ref if_dec.hpp                 | @ref if_inc.hpp      | @ref if_zero_else_allbits.hpp| @ref ifnot_minus.hpp|
         | @ref if_else_allbits.hpp        | @ref if_minus.hpp    | @ref if_zero_else.hpp        | @ref ifnot_plus.hpp |
         | @ref if_else.hpp                | @ref if_nan_else.hpp | @ref if_zero_else_one.hpp    |                     |
       </center>

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
