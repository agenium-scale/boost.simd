//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/detail/dispatch/meta/upgrade.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Check upgrade for pack types"
            , (std::int8_t)(std::int16_t)(std::int32_t)
              (std::uint8_t)(std::uint16_t)(std::uint32_t)
              (float)
            )
{
  using boost::simd::pack;
  using boost::dispatch::upgrade_t;

  static const std::size_t N = pack<T>::static_size;

  STF_TYPE_IS( (upgrade_t<pack<T,N>        >) , (pack<upgrade_t<T>,N/2>) );
  STF_TYPE_IS( (upgrade_t<pack<T,N>&       >) , (pack<upgrade_t<T>,N/2>) );
  STF_TYPE_IS( (upgrade_t<pack<T,N> const  >) , (pack<upgrade_t<T>,N/2>) );
  STF_TYPE_IS( (upgrade_t<pack<T,N> const& >) , (pack<upgrade_t<T>,N/2>) );
  STF_TYPE_IS( (upgrade_t<pack<T,N>&&      >) , (pack<upgrade_t<T>,N/2>) );
}
