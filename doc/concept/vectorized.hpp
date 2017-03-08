//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#error This file is documentation-only and must not be included

/*!
  @ingroup group-concept-types

  A type is Vectorized if it represents a type which operations are performed in accordance
  with the SIMD execution model.

  @par Requirements

  Vectorized types satisfy [DefaultConstructible](http://en.cppreference.com/w/cpp/concept/DefaultConstructible),
  [CopyConstructible](http://en.cppreference.com/w/cpp/concept/CopyConstructible),
  CopyAssignable and MoveAssignable. Lvalues of Vectorized types satisfy
  [Swappable](http://en.cppreference.com/w/cpp/concept/Swappable).

  Vectorized does not refine [EqualityComparable](http://en.cppreference.com/w/cpp/concept/EqualityComparable)
  (and hence Regular) because @c operator== returns Vectorizable instead of @c bool.

  For any Vectorized type @c V, the following expressions are valid:

  | Expression                        | Type                                          | Notes                                                                                                               |
  |:----------------------------------|:----------------------------------------------|:--------------------------------------------------------------------------------------------------------------------|
  | @c V::storage_type                | native storage type                           |                                                                                                                     |
  | @c V::value_type                  | @c T                                          | Satisfies Vectorizable                                                                                              |
  | @c V::reference                   | proxy reference to @c T                       | Convertible to @c T                                                                                                 |
  | @c V::const_reference             | proxy reference to <tt>T const</tt>           | Convertible to <tt>T const</tt>                                                                                     |
  | @c V::iterator                    | iterator pointing to @c T                     | RandomAccessIterator convertible to @c const_iterator                                                               |
  | @c V::const_iterator              | const iterator pointing to @c T               |                                                                                                                     |
  | @c V::difference_type             | signed integer type                           |                                                                                                                     |
  | @c V::size_type                   | unsigned integer type                         | Must be able to represent all positive values of @c difference_type                                                 |
  | @c V::alignment                   | constant expression of unsigned integer type  | The value of the preferred alignment for @c V                                                                       |
  | @c V::static_size                 | constant expression of unsigned integer type  | The number of Vectorizable elements stored in an instance of @c V                                                   |
  | <tt>V::template rebind<U></tt>    | @c W                                          | For any Vectorizable type @c U, <tt>W::template rebind<T></tt> is @c V                                              |
  | <tt>V::template resize<N></tt>    | @c W                                          | For any integral constant @c N, <tt>W::template resize<V::static_size></tt> is @c V                                 |
  | <tt>V::template retype<U,N></tt>  | @c W                                          | For any integral constant @c N and any Vectorizable type @c U, <tt>W::template retype<T,V::static_size></tt>is @c V |

  For any given @c a and @c b of type @c V, the following expressions are valid:

  | Expression                 | Return type               | Semantics                                        | Conditions | Complexity  |
  |:---------------------------|:--------------------------|:-------------------------------------------------|:-----------|:------------|
  | @c std::begin(a)           | <tt>(const_)iterator</tt> | Iterator to the first element of @c a            |            | Constant    |
  | @c std::end(a)             | <tt>(const_)iterator</tt> | Iterator to one past the last element of @c a    |            | Constant    |
  | @c std::cbegin(a)          | @c const_iterator         | <tt>std::begin(const_cast<const C&>(a))</tt>     |            | Constant    |
  | @c std::cend(a)            | @c const_iterator         | <tt>std::end(const_cast<const C&>(a))</tt>       |            | Constant    |
  | @c a.swap(b)               | @c void                   | Exchanges the values of @c a and @c b            |            | Constant    |
  | @c swap(a, b)              | @c void                   | <tt>a.swap(b)</tt>                               |            | Constant    |
  | @c a.size()                | @c size_type              | <tt>std::distance(a.begin(), a.end())</tt>       |            | Constant    |
  | @c a.empty()               | @c bool                   | <tt>a.size() == 0</tt>                           |            | Constant    |
  | @c a.storage()             | @c storage_type           | Returns the internal native data stored in @c a  |            | Constant    |
  | @c operator storage_type() | @c storage_type           | <tt>return a.storage()</tt>                      |            | Constant    |

  @par Example

  - @c boost::simd::pack<short>
  - @c boost::simd::pack<boost::simd::logical<float>>
**/
struct Vectorized {};
