//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/meta/has_native_storage.hpp>
#include <simd_test.hpp>

struct check_native_storage
{
  template<typename T> void operator()(nsm::type_<T> const&)
  {
    using boost::simd::has_native_storage;

    runtime.stream()  << "\n With T = [" << ::stf::type_id<T>() << "]\n";

    STF_EXPECT( ( has_native_storage<T    >::value) );
    STF_EXPECT( (!has_native_storage<T,128>::value) );
  }

  ::stf::unit::env& runtime;
};

STF_CASE( "Check has_native_storage support" )
{
  using limits = boost::simd::limits<BOOST_SIMD_DEFAULT_SITE>;

  nsm::for_each<limits::supported_types>( check_native_storage{runtime} );
}

