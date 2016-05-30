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

You must create a build directory where all temporary building stuffs will be located.

> We assume that you are doing all the following commands in the Boost.SIMD source tree

Let say:
```bash
mkdir -p build
cd build
```

Now, if you want a all-in-one solution, you can do the following:
```bash
cmake .. -DUSE_SELF_BOOST= -DCMAKE_INSTALL_PREFIX=/tmp/boost.simd.install
make update.boost-header-only # This is one is optional
make update.boost.dispatch
make install
```

Of course, you can change the value of `CMAKE_INSTALL_PREFIX` to a different location.
This will install a sufficient version of `boost` header-only (only if you didn't omitted the `update.boost-header-only` part),
as well a `boost.dispatch` and `boost.simd`.

You should now be able to add your install directory as include directory with your favorite compiler!

For example (assuming your file is: `/tmp/main.cpp`):
```cpp
#include <iostream>
#include <boost/simd/pack.hpp>

int main() {
  namespace bs = boost::simd;
  using pack_t = bs::pack<float, 4>;

  float data[pack_t::static_size] = { 1.f, 2.f, 3.f, 4.f };
  pack_t p{&data[0]};

  std::cout << p << std::endl;

  return 0;
}
```

Now compile it:
```
clang++ -std=c++11 -I/tmp/boost.simd.install/include /tmp/main.cpp
```
