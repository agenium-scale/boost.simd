//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

#include <boost/simd/pack.hpp>
#include <boost/simd/io.hpp>
#include <boost/simd/functions/splat.hpp>
#include <boost/simd/functions/plus.hpp>
#include <boost/simd/functions/multiplies.hpp>
#include <iostream>

//! [scalar-dot]
template<typename Value> Value dot(Value* first1, Value* last1, Value* first2)
{
  Value v(0);

  while(first1 != last1)
  {
    v += *first1 *  *first2;
    first1++;
    first2++;
  }

  return v;
}
//! [scalar-dot]

int main()
{
}
