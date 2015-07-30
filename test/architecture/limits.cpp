//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/arch/limits.hpp>
#include <boost/simd/arch/spec.hpp>
#include <nstest.hpp>

NSTEST_CASE_TPL( "Check existence of limits for SSE1 extension", (boost::simd::sse_) )
{
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::smallest_real, float);
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::largest_real , float);

  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template smallest_integer<signed>  , brigand::no_such_type_   );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template smallest_integer<unsigned>, brigand::no_such_type_  );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template largest_integer<signed>   , brigand::no_such_type_  );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template largest_integer<unsigned> , brigand::no_such_type_ );

  NSTEST_EQUAL( boost::simd::limits<T>::bits, 128 );
  NSTEST_EQUAL( boost::simd::limits<T>::bytes, 16 );
}

NSTEST_CASE_TPL ( "Check existence of limits for SSE2-like extensions"
                , (boost::simd::sse2_)(boost::simd::sse3_)(boost::simd::ssse3_)
                  (boost::simd::sse4_1_)(boost::simd::sse4_2_)(boost::simd::sse4a_)
                  (boost::simd::vsx_)
                )
{
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::smallest_real, float);
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::largest_real, double);

  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template smallest_integer<signed>  , std::int8_t   );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template smallest_integer<unsigned>, std::uint8_t  );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template largest_integer<signed>   , std::int64_t  );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template largest_integer<unsigned> , std::uint64_t );

  NSTEST_EQUAL( boost::simd::limits<T>::bits, 128 );
  NSTEST_EQUAL( boost::simd::limits<T>::bytes, 16 );
}

NSTEST_CASE_TPL ( "Check existence of limits for AVX-like extensions"
                , (boost::simd::avx_)(boost::simd::avx2_)
                  (boost::simd::fma4_)(boost::simd::fma3_)(boost::simd::xop_)
                )
{
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::smallest_real, float);
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::largest_real, double);

  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template smallest_integer<signed>  , std::int8_t   );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template smallest_integer<unsigned>, std::uint8_t  );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template largest_integer<signed>   , std::int64_t  );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template largest_integer<unsigned> , std::uint64_t );

  NSTEST_EQUAL( boost::simd::limits<T>::bits, 256 );
  NSTEST_EQUAL( boost::simd::limits<T>::bytes, 32 );
}

NSTEST_CASE_TPL ( "Check existence of limits for MIC-like extensions"
                , (boost::simd::mic_)
                )
{
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::smallest_real, float);
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::largest_real, double);

  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template smallest_integer<signed>  , std::int32_t   );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template smallest_integer<unsigned>, std::uint32_t  );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template largest_integer<signed>   , std::int64_t  );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template largest_integer<unsigned> , std::uint64_t );

  NSTEST_EQUAL( boost::simd::limits<T>::bits, 512 );
  NSTEST_EQUAL( boost::simd::limits<T>::bytes, 64 );
}

NSTEST_CASE_TPL ( "Check existence of limits for VMX-like extensions"
                , (boost::simd::vmx_)
                )
{
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::smallest_real, float);
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::largest_real , float);

  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template smallest_integer<signed>  , std::int8_t   );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template smallest_integer<unsigned>, std::uint8_t  );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template largest_integer<signed>   , std::int32_t  );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template largest_integer<unsigned> , std::uint32_t );

  NSTEST_EQUAL( boost::simd::limits<T>::bits, 128 );
  NSTEST_EQUAL( boost::simd::limits<T>::bytes, 16 );
}

NSTEST_CASE_TPL( "Check existence of limits for QPX extension", (boost::simd::qpx_) )
{
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::smallest_real, double);
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::largest_real , double);

  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template smallest_integer<signed>  , brigand::no_such_type_   );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template smallest_integer<unsigned>, brigand::no_such_type_  );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template largest_integer<signed>   , brigand::no_such_type_  );
  NSTEST_TYPE_IS( typename boost::simd::limits<T>::template largest_integer<unsigned> , brigand::no_such_type_ );

  NSTEST_EQUAL( boost::simd::limits<T>::bits, 256 );
  NSTEST_EQUAL( boost::simd::limits<T>::bytes, 32 );
}
