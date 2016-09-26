#include <boost/simd/function/load.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/sum.hpp>
#include <boost/simd/pack.hpp>

// [scalar-dot-simd]
Value simddot(Value* first1, Value* last1, Value* first2)
{
  namespace bs = boost::simd;
  using pack_t = bs::pack<Value>;

  pack_t tmp{0};
  int card = pack_t::static_size;

  for (; first1 + card <= last1; first1 += card, first2 += card) {
    // Load current values from the datasets
    pack_t x1 = bs::load<pack_t>(first1);
    pack_t x2 = bs::load<pack_t>(first2);
    // Computation
    tmp = tmp + x1 * x2;
  }

  Value dot_product = bs::sum(tmp); // horizontal SIMD vector summation
  for (; first1 < last1; ++first1, ++first2) {
    dot_product += (*first1) * (*first2);
  }

  return dot_product;
}
//! [scalar-dot-simd]
