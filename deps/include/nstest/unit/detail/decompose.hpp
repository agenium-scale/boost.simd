//==================================================================================================
/*!
  @file

  Defines types and macros for macro expression display

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_UNIT_DETAIL_DECOMPOSE_HPP_INCLUDED
#define NSTEST_UNIT_DETAIL_DECOMPOSE_HPP_INCLUDED

#include <nstest/common/to_string.hpp>
#include <nstest/unit/detail/result.hpp>
#include <nstest/unit/detail/comparator.hpp>

namespace nstest { namespace detail
{
  // Carry value around up to display point inside test macro
  template<typename Expression> struct lhs_expr
  {
    Expression lhs;

    lhs_expr( Expression x ) : lhs( x ) {}

    lhs_expr(lhs_expr const&)             = delete;
    lhs_expr& operator=(lhs_expr const&)  = delete;

    #define NSTEST_BINARY_DECOMPOSE(OP,SB,FN)                                                       \
    template<typename R> result operator OP( R const & rhs )                                        \
    {                                                                                               \
      using nstest::detail::FN;                                                                     \
      return  { FN(lhs, rhs)                                                                        \
              , nstest::to_string( lhs ), nstest::split_line(lhs,rhs,SB), nstest::to_string(rhs)    \
              };                                                                                    \
    }                                                                                               \
    /**/

    NSTEST_BINARY_DECOMPOSE( ==,  "==", compare_equal         )
    NSTEST_BINARY_DECOMPOSE( !=,  "!=", compare_not_equal     )
    NSTEST_BINARY_DECOMPOSE( < ,  "<" , compare_less          )
    NSTEST_BINARY_DECOMPOSE( <=,  "<=", compare_less_equal    )
    NSTEST_BINARY_DECOMPOSE( > ,  ">" , compare_greater       )
    NSTEST_BINARY_DECOMPOSE( >=,  ">=", compare_greater_equal )

    #undef NSTEST_BINARY_DECOMPOSE
  };

  /*!
    @brief Trampoline type for custom display of value injected from a macro.
    @ingroup group-details

    When a macro like NTEST_EXPECT( a == b ) is called, it's often useful to be able to
    display the value of a and b without having to butcher the macro API. The decomposer
    type is used to provide a member pointer access overload able to catch arbitrary binary
    expression and forward them to the display system.

    @note This code is sa direct adaptation of the similar technique used by Martin Moene in LEST
  **/
  struct decomposer
  {
    template <typename Expression>
    lhs_expr<Expression const &> operator->* ( Expression const& expr )
    {
      return { expr };
    }
  };
} }

/*!
  @brief Macro decomposing a test expression for display
  @ingroup group-details

  @param XPR Expression to display
**/
#define NSTEST_DECOMPOSE( XPR ) ( nstest::detail::decomposer()->* XPR )

#endif
