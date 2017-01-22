//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/mask.hpp>
#include <boost/simd/detail/dispatch/hierarchy_of.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <boost/pointee.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <simd_test.hpp>

using namespace boost::simd;
using namespace boost::dispatch;
using namespace nsm;

STF_CASE( "Check masked pointer interface" )
{
  double       x{};
  std::uint64_t const const_x{};

  auto ax = mask(&x, true, 69.);
  auto acx = mask(&const_x, false, 42ul);

  STF_EQUAL( ax.get()   , &x        );
  STF_EQUAL( acx.get()  , &const_x  );

  STF_EQUAL( ax.mask()   , true   );
  STF_EQUAL( acx.mask()  , false  );

  STF_EQUAL( ax.value()   , 69.   );
  STF_EQUAL( acx.value()  , 42u  );
}

STF_CASE( "hierarchy_of of masked pointer")
{
  float f{};
  char const c{};

  auto m1 = mask(&f, true, f+1);
  auto m2 = mask(&f, true);
  auto m3 = mask(&c, false, c+1);
  auto m4 = mask(&c, false);

  using masked_ptr_t        = decltype(m1);
  using zero_masked_ptr_t   = decltype(m2);
  using c_masked_ptr_t      = decltype(m3);
  using zero_c_masked_ptr_t = decltype(m4);

  STF_TYPE_IS ( hierarchy_of_t<masked_ptr_t>
              , (masked_pointer_<hierarchy_of_t<float,masked_ptr_t>, type_traits::false_type>)
              );

  STF_TYPE_IS ( hierarchy_of_t<zero_masked_ptr_t>
              , (masked_pointer_<hierarchy_of_t<float,zero_masked_ptr_t>, type_traits::true_type>)
              );

  STF_TYPE_IS ( hierarchy_of_t<c_masked_ptr_t>
              , (masked_pointer_<hierarchy_of_t<char const,c_masked_ptr_t>, type_traits::false_type>)
              );

  STF_TYPE_IS ( hierarchy_of_t<zero_c_masked_ptr_t>
              , (masked_pointer_<hierarchy_of_t<char const,zero_c_masked_ptr_t>, type_traits::true_type>)
              );
}
