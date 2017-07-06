//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/config.hpp>
#include <boost/simd/arch/limits.hpp>
#include <boost/simd/arch/spec.hpp>
#include <simd_test.hpp>

using namespace boost::simd;

STF_CASE_TPL( "Check existence of limits for SSE1 extension", (sse1_) )
{
  STF_TYPE_IS( typename limits<T>::smallest_real, float);
  STF_TYPE_IS( typename limits<T>::largest_real , float);

  STF_TYPE_IS( (nsm::apply<typename limits<T>::smallest_integer,signed>)   , nsm::no_such_type_  );
  STF_TYPE_IS( (nsm::apply<typename limits<T>::smallest_integer,unsigned>) , nsm::no_such_type_  );
  STF_TYPE_IS( (nsm::apply<typename limits<T>::largest_integer,signed>)    , nsm::no_such_type_  );
  STF_TYPE_IS( (nsm::apply<typename limits<T>::largest_integer,unsigned>)  , nsm::no_such_type_  );

  STF_EQUAL( limits<T>::bits, 128 );
  STF_EQUAL( limits<T>::bytes, 16 );
}

STF_CASE_TPL ( "Check existence of limits for SSE2-like extensions"
                , (sse2_)(sse3_)(ssse3_)
                  (sse4_1_)(sse4_2_)
                )
{
  STF_TYPE_IS( typename limits<T>::smallest_real, float);
  STF_TYPE_IS( typename limits<T>::largest_real, double);

  STF_TYPE_IS( (nsm::apply<typename limits<T>::smallest_integer,signed>)   , std::int8_t  );
  STF_TYPE_IS( (nsm::apply<typename limits<T>::smallest_integer,unsigned>) , std::uint8_t  );
  STF_TYPE_IS( (nsm::apply<typename limits<T>::largest_integer,signed>)    , std::int64_t  );
  STF_TYPE_IS( (nsm::apply<typename limits<T>::largest_integer,unsigned>)  , std::uint64_t  );

  STF_EQUAL( limits<T>::bits, 128 );
  STF_EQUAL( limits<T>::bytes, 16 );
}
