#!/usr/bin/env python

import platform

print("This is Python " + platform.python_version());

import helloworld

a = 10
b = 32
print("%d + %d = %d" % (a, b, helloworld.add(a, b)));
