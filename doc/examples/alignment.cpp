#include <memory>
#include <vector>

#include <boost/simd/memory/allocate.hpp>
#include <boost/simd/memory/allocator.hpp>
#include <boost/simd/pack.hpp>

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
    //! [align-allocate]
    std::size_t num_elements = 1024;
    using aligned_ptr        = std::unique_ptr<int[], boost::simd::aligned_delete>;

    aligned_ptr ptr2(boost::simd::allocate<int>(num_elements));
    //! [align-allocate]
  }

  {
    //! [align-vector]
    std::size_t num_elements = 1024;
    std::vector<int, boost::simd::allocator<float>> input_buffer(num_elements);
    //! [align-vector]
  }
}
