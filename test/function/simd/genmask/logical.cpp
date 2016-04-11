//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

STF_CASE_TPL ("Check genmask logical behavior",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::genmask;
  static const std::size_t N = bs::pack<T>::static_size;

  STF_TYPE_IS(decltype(bs::genmask( bs::pack<bs::logical<T>,N   >())), (bs::pack<T,N  >));
  STF_TYPE_IS(decltype(bs::genmask( bs::pack<bs::logical<T>,N/2 >())), (bs::pack<T,N/2>));
  STF_TYPE_IS(decltype(bs::genmask( bs::pack<bs::logical<T>,N*2 >())), (bs::pack<T,N*2>));

  STF_IEEE_EQUAL( genmask ( bs::pack<bs::logical<T>,N>(true))
                          , (bs::Allbits<bs::pack<T,N>>()
                          )
                );
  STF_IEEE_EQUAL( genmask ( bs::pack<bs::logical<T>,N/2>(true))
                          , (bs::Allbits<bs::pack<T,N/2>>()
                          )
                );
  STF_IEEE_EQUAL( genmask ( bs::pack<bs::logical<T>,N*2>(true))
                          , (bs::Allbits<bs::pack<T,N*2>>()
                          )
                );

  STF_IEEE_EQUAL( genmask ( bs::pack<bs::logical<T>,N>(bs::logical<T>(false)))
                          , (bs::pack<T,N>(T(0))
                          )
                );
  STF_IEEE_EQUAL( genmask ( bs::pack<bs::logical<T>,N/2>(bs::logical<T>(false)))
                          , (bs::pack<T,N/2>(T(0))
                          )
                );
  STF_IEEE_EQUAL( genmask ( bs::pack<bs::logical<T>,N*2>(bs::logical<T>(false)))
                          , (bs::pack<T,N*2>(T(0))
                          )
                );
}

// TODO when if_else_zero is available
#if 0
// STF_CASE_TPL ("Check genmask logical behavior when re-targeted",  STF_NUMERIC_TYPES)
// {
//   namespace bs = boost::simd;
//   using bs::genmask;

//   STF_TYPE_IS(decltype(bs::genmask<char>(bs::logical<T>())),char);

//   STF_IEEE_EQUAL(genmask<char>(bs::logical<T>(true)), bs::Allbits<char>());
//   STF_EQUAL(genmask<char>(bs::logical<T>(false)) , char(0));
// }
#endif
