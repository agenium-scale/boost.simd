//! [reduc]
#include <iostream>
#include <vector>
#include <numeric>

#include <boost/simd/pack.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
//! [reduc-inc]
#include <boost/simd/function/sum.hpp>
//! [reduc-inc]

#define size 64

int main() {
  namespace bs = boost::simd;
  using pack_t = bs::pack<int>;
  int card_int = bs::cardinal_of<pack_t>();

  std::vector<int> array(size);
  std::iota(array.begin(), array.end(), 0);

  int sum;

  //! [reduc-scalar]
  // Scalar version
  sum = 0;
  for ( size_t i = 0 ; i < size ; ++i ){
    sum += array[i];
  }
  //! [reduc-scalar]
  std::cout << "Scalar sum = " << sum << std::endl;

  //! [reduc-simd-l]
  sum = 0
  bs::pack<int, size> array_pack(array);
  sum = bs::sum(array_pack);
  //! [reduc-simd-l]
  std::cout << "SIMD 1 = " << sum << std::endl;

  //! [reduc-simd-o]
  sum = 0;
  pack_t sum_p{0};
  for ( size_t i = 0 ; i < size ; i += card_int ){
    sum_p += pack_t( array + i );
  }
  sum = bs::sum( sum_p );
  //! [reduc-simd-o]
  std::cout << "SIMD 2 = " << sum << std::endl;

  //! [reduc-simd-r]
  //The input data is an arbitrary size
  array.resize(size + 13);
  std::iota(array.begin(), array.end(), 0);

  sum = 0;
  pack_t sum_p{0};
  size_t i = 0;
  for (; i + card_int <= size ; i += card_int ){
    sum_p += pack_t( array + i );
  }
  sum = bs::sum( sum_p );
  for (; i < size ; ++i){
    sum += array[i];
  }
  //! [reduc-simd-r]

  std::cout << "SIMD 3 = " << sum << std::endl;

  return 0;
}
//! [reduc]
