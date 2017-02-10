#!/usr/bin/env python
# -*- coding: UTF-8  -*-
##############################################################################
#          Distributed under the Boost Software License, Version 1.0
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################
from __future__ import print_function

__author__    = "Pyry Jahkola (pyry.jahkola@iki.fi)"
__license__   = "Boost Software License, Version 1.0"


import sys
from os import walk, listdir
from os.path import dirname, basename, sep, normpath, isdir, isfile, join
from itertools import chain, groupby

def iterfiles(root, *dirs):
    dir = join(root, *dirs)
    for file in listdir(dir):
        if isdir(join(dir, file)):
            for f in iterfiles(root, *(dirs + (file,))): yield f
        elif isfile(join(dir, file)):
            yield join(*(dirs + (file,)))

def list_files(root):
    return list(iterfiles(root))

def exclude_files(files, *excludes):
    return list(f for f in files if basename(f) not in excludes)

def find_duplicates(xs):
    return list(y for y, ys in groupby(sorted(xs)) if len(list(ys)) > 1)

def make_include_guard(path):
    convert = lambda s: s.upper().replace('.', '_').strip('_')
    tokens = list(convert(t) for t in normpath(path).split(sep) if t)
    return '_'.join(tokens + ['INCLUDED'])

def find_include_guard(file):
    first = lambda it: next(it, None)
    guard_line = first(ln for ln in open(file) if ln.startswith('#ifndef'))
    return guard_line and guard_line.split()[-1]

# ------------------------------------------------------------------------------

def usage():
    print('usage: {0} <root-path>'.format(sys.argv[0]))

if len(sys.argv[1:]) == 1:
    root = sys.argv[1]
else:
    usage()
    sys.exit(1)

modules = [join(root, 'include')]

module_includes = dict(
    (m, list_files(m)) for m in modules)

all_includes = list(chain(*module_includes.values()))

# Check that we don't have include files with conflicting include paths in
# any two different modules.
print('\nChecking uniqueness of includes...')
duplicates = find_duplicates(all_includes)
if duplicates:
    print('WARNING: Found duplicate includes!')
    for f in duplicates:
        print('  - file <{0}> in:'.format(f))
        print('\n'.join('    - {0}'.format(m)
                        for m, fs in module_includes.items() if f in fs))
print('\n=== Done. ' + '=' * 70 + '\n')


# Check that the include guards as they currently are, "#ifndef FILE_WHATEVER",
# are unique
print('\nChecking uniqueness of current include guards...')
guards = sorted(((m, f, find_include_guard(join(m, f)))
                 for m, fs in module_includes.items() for f in fs),
                key=lambda (m, f, g): g)
by_guard = dict((g, list((m, f) for m, f, g in ls))
                for g, ls in groupby(guards, key=lambda (m, f, g): g))
duplicates = dict((g, ls) for g, ls in by_guard.items() if len(ls) > 1)
if duplicates:
    print('WARNING: Found duplicate includes!\n')
    for g, ls in duplicates.items():
        print('  - the guard {0} is present in each of:'.format(g or '(none)'))
        print('\n'.join('    - <{0}> in module {1}'.format(f,m) for m,f in ls))
        print()
print('\n=== Done. ' + '=' * 70 + '\n')


# Check that the include guard for any include file <path/to/file.hpp> is of the
# corrected format #ifndef PATH_TO_FILE_HPP_INCLUDED
print('\nChecking correctness of current include guards...')
broken_guards = dict(filter(
    lambda (module, errors): errors,
    ((m, filter(lambda (file, expected, found): expected != found,
               ((f, make_include_guard(f),
                    find_include_guard(join(m, f))) for f in fs)))
    for m, fs in module_includes.iteritems())))
if broken_guards:
    print('WARNING: Found broken include guards!')
    for module in broken_guards:
        print('\n  - in module "{0}":\n'.format(module))
        for file, expected, found in broken_guards[module]:
            print('    - in file: <{0}>'.format(file))
            print('      expected: {0}'.format(expected))
            print('      found:    {0}\n'.format(found))

    print('--- SUGGESTED REPLACEMENTS ' + '-' * 53)
    for module in broken_guards:
        for file, expected, found in broken_guards[module]:
            if found and found not in 'BOOST_DISPATCH_DECLTYPE BOOST_PP_IS_ITERATING'.split():
                print("sed -i -e 's/{0}/{1}/g' {2}".format(found, expected, join(module, file)))
print('\n=== Done. ' + '=' * 70 + '\n')


# Lastly, check that there are no files where the corrected include guards might
# conflict. (E.g. path/to_file.hpp and path/to/file.hpp would have conflicting
# include guards PATH_TO_FILE_HPP_INCLUDED.) If this is the case, it has to be
# fixed manually.
print('\nChecking uniqueness of corrected include guards...')
duplicates = find_duplicates(make_include_guard(f) for f in all_includes)
if duplicates:
    print('WARNING: Found duplicates!')
    for g in duplicates:
        print('  - guard <{0}> for:'.format(g))
        print('\n'.join('    - {0} in module {1}'.format(f, m)
                        for m, fs in module_includes.items()
                        if f in map(make_include_guard, fs)))
print('\n=== Done. ' + '=' * 70 + '\n')
