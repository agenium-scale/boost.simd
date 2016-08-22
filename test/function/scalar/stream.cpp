//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/function/stream.hpp>

#include <simd_test.hpp>

STF_CASE_TPL("stream", STF_NUMERIC_TYPES)
{
  using boost::simd::stream;

  T data[5];

  for(int32_t i=0;i<5;++i)
    stream(static_cast<T>(2-i),&data[i]);

  STF_EQUAL( data[0], T(2)  );
  STF_EQUAL( data[1], T(1)  );
  STF_EQUAL( data[2], T(0)  );
  STF_EQUAL( data[3], T(-1) );
  STF_EQUAL( data[4], T(-2) );
}

STF_CASE_TPL("stream_offset", STF_NUMERIC_TYPES)
{
  using boost::simd::stream;

  T data[5];

  for(int32_t i=0;i<5;++i)
    stream(static_cast<T>(2-i),&data[0],i);

  STF_EQUAL( data[0], T(2)  );
  STF_EQUAL( data[1], T(1)  );
  STF_EQUAL( data[2], T(0)  );
  STF_EQUAL( data[3], T(-1) );
  STF_EQUAL( data[4], T(-2) );
}
