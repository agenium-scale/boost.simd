#include <boost/simd/include/functions/sum.hpp>
#include <boost/simd/include/functions/load.hpp>
#include <boost/simd/include/functions/plus.hpp>
#include <boost/simd/include/functions/multiplies.hpp>

// [scalar-dot-simd]
template<typename Value>
Value dot(Value* first1, Value* last1, Value* first2)
{
  using boost::simd::sum;
  using boost::simd::pack;
  using boost::simd::load;

  typedef pack<Value> type;
  type tmp;

  // Let's assume that (last1-first1) is divisible by the size of the pack.
  while(first1 != last1)
  {
    // Load current values from the datasets
    pack<Value> x1 = load< type >(first1);
    pack<Value> x2 = load< type >(first2);

    // Computation
    tmp = tmp + x1 * x2;

    // Advance to the next SIMD vector
    first1 += type::static_size;
    first2 += type::static_size;
  }

  return sum(tmp);
}
//! [scalar-dot-simd]
