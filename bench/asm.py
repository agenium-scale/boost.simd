#!/usr/bin/env python

import re
import sys
import subprocess

if len(sys.argv) != 2:
    sys.stderr.write('usage: {} <file>\n'.format(sys.argv[0]))
    sys.exit(1)

f = sys.argv[1]
in_block = False
rdtsc = re.compile('.*rdtsc\s*$')
try:
    cmd = ['objdump', '-DC', f]
    for line in subprocess.check_output(cmd).split('\n'):
        if rdtsc.match(line):
            if in_block:
                sys.stdout.write(('-' * 100) + '\n')
            in_block = not in_block
            continue
        if in_block:
            sys.stdout.write(line + '\n')
except OSError as e:
    sys.stderr.write(str(e) + '\n')
