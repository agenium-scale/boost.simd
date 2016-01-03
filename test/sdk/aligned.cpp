//==================================================================================================
/*
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/sdk/aligned.hpp>
#include <boost/dispatch/hierarchy_of.hpp>
#include <simd_test.hpp>

using namespace boost::simd;
using namespace boost::dispatch;

STF_CASE( "Check aligned pointer interface" )
{
  double       x{};
  std::uint64_t const const_x{};

  auto ax = aligned(&x);
  auto acx = aligned(&const_x);

  STF_EQUAL( ax.get()   , &x        );
  STF_EQUAL( acx.get()  , &const_x  );
}

STF_CASE( "hierarchy_of of aligned pointer")
{
  float f{};
  char const c{};

  using aligned_ptr_t = decltype(aligned(&f));
  using c_aligned_ptr_t = decltype(aligned(&c));

  STF_TYPE_IS ( hierarchy_of_t<aligned_ptr_t>
              , (aligned_pointer_<hierarchy_of_t<float,aligned_ptr_t>>)
              );

  STF_TYPE_IS ( hierarchy_of_t<c_aligned_ptr_t>
              , (aligned_pointer_<hierarchy_of_t<char const,c_aligned_ptr_t>>)
              );
}
