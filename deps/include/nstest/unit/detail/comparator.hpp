 //==================================================================================================
 /*!
   @file

   Defines extensible comparator for relation tests macro

   @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Parcompare_ Sud XI
   @copyright 2012 - 2015 NumScale SAS

   Distributed under the Boost Software License, Version 1.0.
   (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

 **/
 //==================================================================================================
 #ifndef NSTEST_UNIT_DETAIL_COMPARATOR_HPP_INCLUDED
 #define NSTEST_UNIT_DETAIL_COMPARATOR_HPP_INCLUDED

namespace nstest { namespace detail
{
  template<typename LHS, typename RHS>
  inline bool compare_equal(LHS const& l, RHS const& r)         { return l == r; }

  template<typename LHS, typename RHS>
  inline bool compare_less(LHS const& l, RHS const& r)          { return l < r; }

  template<typename LHS, typename RHS>
  inline bool compare_not_equal(LHS const& l, RHS const& r)     { return l != r; }

  template<typename LHS, typename RHS>
  inline bool compare_less_equal(LHS const& l, RHS const& r)    { return l <= r; }

  template<typename LHS, typename RHS>
  inline bool compare_greater(LHS const& l, RHS const& r)       { return l > r; }

  template<typename LHS, typename RHS>
  inline bool compare_greater_equal(LHS const& l, RHS const& r) { return l >= r; }
} }

#endif
