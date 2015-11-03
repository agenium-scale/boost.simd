#ifndef NONTRIVIAL_HPP
#define NONTRIVIAL_HPP

#include <iostream>

namespace foo
{
  template<class T>
  struct nontrivial
  {
    nontrivial(const T & aa, const T & bb) :a(aa), b(bb){};
    nontrivial() :nontrivial(0, 0){};
    T a, b;
  };

  template < class T>
  bool compare_equal (const nontrivial<T> & z1, const nontrivial<T> & z2)
  {
    return (z1.a == z2.a) &&  (z1.b == z2.b);
  }

  template < class T>
  bool compare_less (const nontrivial<T> & z1, const nontrivial<T> & z2)
  {
    return (z1.a < z2.a) &&  (z2.b < z2.b);
  }

  template < class T>
  nontrivial<T> perform (const nontrivial<T> & z1, const nontrivial<T> & z2)
  {
    return nontrivial<T>(z1.a + z2.a,  z1.b * z2.b);
  }

  template < class T>
  nontrivial<T> perform (const nontrivial<T> & z1)
  {
    return nontrivial<T>(T(2)*z1.a, z1.b*T(3));
  }

  template<typename T>
  inline std::ostream& operator<<(std::ostream& os, nontrivial<T> const& v)
  {
    os <<  "(" << v.a << ",  " << v.b << ")";
    return os;
  }
}

#endif
