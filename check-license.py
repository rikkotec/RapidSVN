#!/usr/bin/env python
#
# check if a file has the proper license in it
#
# USAGE: check-license.py [-C] file1 file2 ... fileN
#
# If the license cannot be found, then the filename is printed to stdout.
# Typical usage:
#    $ find . -name "*.[ch]" | xargs check-license.py > bad-files
#
# -C switch is used to change licenses. Typical usage:
#    $ find . -name "*.[ch]" | xargs check-license.py -C
#

OLD_LICENSE = '''\
/\*
 \* ====================================================================
 \* Copyright \(c\) 2002(, 2003)? The RapidSvn Group.  All rights reserved.
 \*
 \* This software is licensed as described in the file LICENSE.txt,
 \* which you should have received as part of this distribution.
 \*
 \* This software consists of voluntary contributions made by many
 \* individuals.  For exact contribution history, see the revision
 \* history and logs, available at http://rapidsvn.tigris.org/.
 \* ====================================================================
 \*/
'''

# Remember not to do regexp quoting for NEW_LICENSE.  Only OLD_LICENSE
# is used for matching; NEW_LICENSE is inserted as-is.
NEW_LICENSE = '''\
/*
 * ====================================================================
 * Copyright (c) 2002, 2003 The RapidSvn Group.  All rights reserved.
 *
 * This software is licensed as described in the file LICENSE.txt,
 * which you should have received as part of this distribution.
 *
 * This software consists of voluntary contributions made by many
 * individuals.  For exact contribution history, see the revision
 * history and logs, available at http://rapidsvn.tigris.org/.
 * ====================================================================
 */
'''

import sys
import re

re_OLD = re.compile(OLD_LICENSE)

def check_file(fname):
  s = open(fname).read()
  if not re_OLD.search(s):
    print fname

def change_license(fname):
  s = open(fname).read()
  m = re_OLD.search(s)
  if not m:
    insert_license(fname)
  else:
    s = s[:m.start()] + NEW_LICENSE + s[m.end():]
    open(fname, 'w').write(s)
    print 'Changed:', fname

def insert_license(fname):
  s = open(fname).read()
  s = NEW_LICENSE + s
  open(fname, 'w').write(s)
  print 'Inserted:', fname

if __name__ == '__main__':
  if sys.argv[1] == '-C':
    print 'Changing license text...'
    for f in sys.argv[2:]:
      change_license(f)
  else:
    for f in sys.argv[1:]:
      check_file(f)
