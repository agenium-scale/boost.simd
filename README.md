# boost.simd

[![Build Status](https://travis-ci.org/NumScale/boost.simd.svg)](https://travis-ci.org/NumScale/boost.simd)

Portable SIMD computation library - To be proposed as a Boost library

## Continuous Integration

| Platform & Compiler | `master`| `develop`|
|---------------------|---------|----------|
| Linux clang & g++   | [![Build Status](https://travis-ci.org/NumScale/boost.simd.png?branch=master)](https://travis-ci.org/NumScale/boost.simd) | [![Build Status](https://travis-ci.org/NumScale/boost.simd.png?branch=develop)](https://travis-ci.org/NumScale/boost.simd) |
| OS X   clang    | [![Build Status](https://travis-ci.org/NumScale/boost.simd.png?branch=master)](https://travis-ci.org/NumScale/boost.simd) | [![Build Status](https://travis-ci.org/NumScale/boost.simd.png?branch=develop)](https://travis-ci.org/NumScale/boost.simd) |

## Getting started with the build process (on linux)

NOTE:
> `boost.simd` *MUST* be used with the current develop version of `boost` (aka 1.62)

You must create a build directory where all temporary building files will be located.

> We assume that you are doing all the following commands in the **Boost.SIMD** source tree

Let say:
```bash
mkdir -p build
cd build
```

Now, if you want a all-in-one solution, you can do the following:
```bash
cmake .. -DUSE_SELF_BOOST= -DCMAKE_INSTALL_PREFIX=/tmp/boost.simd.install
make update.boost-header-only # This is one is optional
make install
```

Of course, you can change the value of `CMAKE_INSTALL_PREFIX` to a different location.
This will install a sufficient version of `boost` (if you used `make update.boost-header-only`
command) and `boost.simd`.

Every files are going to be installed under the `include` directory of your `CMAKE_INSTALL_PREFIX`
directory. You can now use it as include directory when compiling.

For example (assuming your file is: `/tmp/main.cpp`):
```cpp
#include <iostream>
#include <numeric>
#include <boost/simd/pack.hpp>
#include <boost/align/aligned_alloc.hpp>

namespace bs = boost::simd;
namespace ba = boost::alignment;

template <typename T>
void iota_and_print()
{
  // The number of element will be deduced automatically according to the most recent SIMD extension
  using pack_t = bs::pack<T>;

  // Allocates aligned memory using expected alignment
  T* data =
    static_cast<T*>(ba::aligned_alloc(pack_t::alignment, pack_t::static_size * sizeof(T)));
  std::iota(data, data + pack_t::static_size, T(1));

  // Constructs a pack (which will call `boost::simd::aligned_load<pack_t>` to fill up its data)
  pack_t p{data};

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
```

- - -

Now compile it (using SSE2):
```
clang++ -Wall -Wextra -std=c++11 -I/tmp/boost.simd.install/include -msse2 /tmp/main.cpp
```

This gives the following output:
```
(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)
(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)
(1, 2, 3, 4, 5, 6, 7, 8)
(1, 2, 3, 4, 5, 6, 7, 8)
(1, 2, 3, 4)
(1, 2, 3, 4)
(1, 2)
(1, 2)
(1, 2, 3, 4)
(1, 2)
```

- - -

Now compile it (using AVX):
```
clang++ -Wall -Wextra -std=c++11 -I/tmp/boost.simd.install/include -mavx  /tmp/main.cpp
```

This gives the following output:
```
(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32)
(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32)
(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)
(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)
(1, 2, 3, 4, 5, 6, 7, 8)
(1, 2, 3, 4, 5, 6, 7, 8)
(1, 2, 3, 4)
(1, 2, 3, 4)
(1, 2, 3, 4, 5, 6, 7, 8)
(1, 2, 3, 4)
```
