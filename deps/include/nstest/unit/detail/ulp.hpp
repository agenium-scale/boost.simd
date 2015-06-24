//==================================================================================================
/*!
  @file

  Defines the ULP related helpers

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_UNIT_DETAIL_ULP_HPP_INCLUDED
#define NSTEST_UNIT_DETAIL_ULP_HPP_INCLUDED

#include <nstest/common/detail/is_container.hpp>
#include <nstest/unit/detail/ulpdist.hpp>
#include <algorithm>

namespace nstest
{
  // Provides the basic services to perform ULP distance computation and report
  template<typename Reference> struct ulp_
  {
    ulp_(Reference const& r, double u) : ref(r), diff(u), size_mismatch(false), max_diff(u) {}

    template<typename U> inline bool compare(U const& data) const
    {
      using nstest::ulpdist;

      size_mismatch = detail::size(ref) != detail::size(data);
      if(size_mismatch) return false;

      auto dist = ulpdist(data,ref);

      auto br = detail::begin(data);
      auto bi = detail::begin(ref);
      auto bd = detail::begin(dist);
      auto sz = detail::size(data);

      for(std::size_t idx=0;idx < sz; ++idx)
        check( *bd++, *br++, *bi++, (sz>1 ? idx : -1) );

      return errors.size() == 0;
    }

    struct ulp_error
    {
      double          ulp;
      std::string     ref,data;
      std::ptrdiff_t  idx;
    };

    bool                          mismatched()  const { return size_mismatch; }
    double                        max()         const { return max_diff;      }
    std::vector<ulp_error> const& report()      const { return errors;        }

    private:

    template<typename U, typename X, typename Y>
    inline void check(U const& u, X const& x, Y const& y, std::ptrdiff_t idx) const
    {
      using nstest::to_string;

      if( u  > diff )
      {
        errors.push_back( {u, to_string(x),to_string(y), idx} );
        max_diff = std::max(max_diff,u);
      }
    }

    Reference                               ref;
    double                          diff;
    mutable bool                    size_mismatch;
    mutable double                  max_diff;
    mutable std::vector<ulp_error>  errors;
  };

  // Streaming ulp_ builds the report
  template<typename Reference> std::string to_string( ulp_<Reference> const& u )
  {
    std::ostringstream s;
    s.precision(20);

    if(u.mismatched()) return "arguments with mismatched size.";

    for(auto const& e : u.report())
    {
      (e.idx >= 0) ? s << "  [" << e.idx << "]: " : s << "  ";
      s << to_string(e.ref) << " vs " << to_string(e.data) << " ("<< e.ulp << " ulp)\n";
    }

    return "{\n"  + s.str() + "}\n with a maximal error of " + to_string(u.max()) + " ULPs";
  }

  // Simple ulp_ constructor like call
  template<typename Reference> inline ulp_<Reference> ulp(Reference const& t, double n) { return {t,n}; }

  // ADL compare_equal for ulp_
  template<typename Reference, typename U> inline bool compare_equal(U const& l, ulp_<Reference> const& r)
  {
    return r.compare(l);
  }
}

#endif
