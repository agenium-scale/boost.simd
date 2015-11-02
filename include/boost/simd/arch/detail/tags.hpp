#ifndef BOOST_SIMD_ARCH_DETAIL_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_DETAIL_TAGS_HPP_INCLUDED

namespace boost { namespace simd { namespace tag
{
  typedef boost::mpl::false_ not_simd_type;
  typedef boost::mpl::true_      simd_type;
  struct accu_tag{};

} } }

#endif
