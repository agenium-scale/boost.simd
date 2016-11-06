#include <memory>
#include <vector>

#include <boost/simd/pack.hpp>
#include <boost/align/aligned_allocator.hpp>
#include <boost/align/aligned_delete.hpp>

int main(int argc, char** argv)
{
  {
    //! [align-manual]
    namespace bs = boost::simd;
    using pack_t = bs::pack<int>;

    std::size_t num_elements = 1024;
    std::size_t alignment    = pack_t::alignment;
    std::size_t buffer_size  = num_elements + alignment;
    std::unique_ptr<char[]> ptr(new char[buffer_size]);
    void* pv = ptr.get();
    if (std::align(alignment, num_elements, pv, buffer_size) == nullptr) {
      std::cerr << " alignment failed " << std::endl;
    }
    //! [align-manual]
  }

  {
    //! [align-allocator]
    namespace bs = boost::simd;
    namespace ba = boost::alignment;
    using pack_t = bs::pack<int>;

    std::size_t num_elements = 1024;
    std::size_t alignment    = pack_t::alignment;
    std::unique_ptr<char[], ba::aligned_delete> ptr2(
      (char*)ba::aligned_alloc(alignment, num_elements));
    //! [align-allocator]
  }
  {
    //! [align-vector]
    namespace bs = boost::simd;
    namespace ba = boost::alignment;
    using pack_t = bs::pack<int>;

    std::size_t num_elements = 1024;
    std::size_t alignment    = pack_t::alignment;
    std::vector<int, ba::aligned_allocator<int, pack_t::alignment>> input_buffer(num_elements);
    //! [align-vector]
  }
}
