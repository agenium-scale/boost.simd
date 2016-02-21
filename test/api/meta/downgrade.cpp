//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/dispatch/meta/downgrade.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Check downgrade for pack types"
            , (std::int16_t)(std::int32_t)(std::int64_t)
              (std::uint16_t)(std::uint32_t)(std::uint64_t)
              (double)
            )
{
  using boost::simd::pack;
  using boost::dispatch::downgrade_t;

  static const std::size_t N = pack<T>::static_size;

  STF_TYPE_IS( (downgrade_t<pack<T,N>        >) , (pack<downgrade_t<T>,N*2>) );
  STF_TYPE_IS( (downgrade_t<pack<T,N>&       >) , (pack<downgrade_t<T>,N*2>) );
  STF_TYPE_IS( (downgrade_t<pack<T,N> const  >) , (pack<downgrade_t<T>,N*2>) );
  STF_TYPE_IS( (downgrade_t<pack<T,N> const& >) , (pack<downgrade_t<T>,N*2>) );
  STF_TYPE_IS( (downgrade_t<pack<T,N>&&      >) , (pack<downgrade_t<T>,N*2>) );
}
