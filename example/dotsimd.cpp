#include <boost/simd/pack.hpp>
#include <boost/simd/function/sum.hpp>
#include <boost/simd/function/load.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/multiplies.hpp>

// [scalar-dot-simd]
template<typename Value>
Value dot(Value* first1, Value* last1, Value* first2)
{
  using boost::simd::sum;
  using boost::simd::pack;
  using boost::simd::load;

  typedef pack<Value> type;
  type tmp{0};
  int card = type::static_size;

  for(; first1 + card <= last1; first1 += card, first2 += card) {
    // Load current values from the datasets
    pack<Value> x1 = load< type >(first1);
    pack<Value> x2 = load< type >(first2);

    // Computation
    tmp = tmp + x1 * x2;
  }

  Value dot_product = sum(tmp);
  for(; first1 < last1; ++first1, ++first2){
    dot_product += (*first1) * (*first2);
  }

  return dot_product;
}
//! [scalar-dot-simd]
