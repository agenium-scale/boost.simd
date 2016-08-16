//! [reduc]
#include <iostream>
#include <boost/simd/pack.hpp>
//! [reduc-inc]
#include <boost/simd/function/sum.hpp>
//! [reduc-inc]

#define size 64

int main(void) {
  namespace bs = boost::simd;

  int *array = new int[size];
  int sum;

  // Initialize array values
  for ( size_t i = 0 ; i < size ; ++i )
    array[i] = i;

//! [reduc-scalar]
  // Scalar version
  sum = 0;
  for ( size_t i = 0 ; i < size ; ++i )
    sum += array[i];
//! [reduc-scalar]
  std::cout << "Scalar = " << sum << std::endl;

//! [reduc-simd-l]
  // Size power of 2 and known at compile time SIMD version
  bs::pack< int , size > array_pack(array);
  sum = bs::sum(array_pack);
//! [reduc-simd-l]
  std::cout << "SIMD 1 = " << sum << std::endl;

//! [reduc-simd-o]
  // Size agnostic SIMD
  bs::pack< int > sum_p{0};
  for ( size_t i = 0 ; i < size ; i += card_int )
    sum_p += bs::pack< int >( array + i );
  sum = bs::sum( sum_p );
//! [reduc-simd-o]
  std::cout << "SIMD 2 = " << sum << std::endl;

  return 0;
}
//! [reduc]
