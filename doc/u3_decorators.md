Decorators {#decorators}
==========

@tableofcontents

@section decorators-rationale Rationale

TO DO by joel perhaps

@section decorators-fast fast

The `fast_` decorator is used to mean that the user can be  using a version of the decorated functor
that can do agressive optimization at the lost of certain properties or corner cases of the original
functor

TO DO list and example

@section decorators-restricted restricted

The `restricted_` decorator is used to restrict the range of validity of some functors, but ensure an
as accurate, but speedier version on the range.

TO DO list and example

@section decorators-saturated_ saturated

The `saturated_` decorator is used to provide a saturated version of some functors when producing integral typed values.


This is peculiarly interesting in SIMD mode, as unlike scalars, SIMD @ref pack of integers are not promoted
during current arithmetic operations which increases the overflow risks.

TO DO list and example

