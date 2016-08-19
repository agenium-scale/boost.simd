#include <iostream>
#include <memory>
#include <numeric>

#include <boost/simd/pack.hpp>
#include <boost/align/aligned_alloc.hpp>
#include <boost/align/aligned_delete.hpp>

namespace bs = boost::simd;
namespace ba = boost::alignment;

//! [iota-print]
template <typename T>
void iota_and_print()
{
  // The number of elements will be deduced automatically according to the target architecture selected
  using pack_t = bs::pack<T>;

  // Allocates aligned memory using expected alignment
  std::unique_ptr<T[], ba::aligned_delete> data(
    (T*)(ba::aligned_alloc(pack_t::alignment, pack_t::static_size * sizeof(T))));
  std::iota(data.get(), data.get() + pack_t::static_size, T(1));

  // Constructs a pack (which will call `boost::simd::aligned_load<pack_t>` to fill up its data)
  pack_t p{data.get()};

  // Now just print the loaded data
  std::cout << p << std::endl;
}

int main() {
  iota_and_print<std::int8_t>();
  iota_and_print<std::uint8_t>();
  // --
  iota_and_print<std::int16_t>();
  iota_and_print<std::uint16_t>();
  // --
  iota_and_print<std::int32_t>();
  iota_and_print<std::uint32_t>();
  // --
  iota_and_print<std::int64_t>();
  iota_and_print<std::uint64_t>();
  // --
  iota_and_print<float>();
  // --
  iota_and_print<double>();
  return 0;
}
//! [iota-print]
