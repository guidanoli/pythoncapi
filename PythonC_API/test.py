#!/usr/bin/env python

import platform

print("This is Python " + platform.python_version());

import helloworld

a = 32
b = 10
print("%d + %d = %d" % (a, b, helloworld.add(a, b)));
print("%d - %d = %d" % (a, b, helloworld.sub(a, b)));
print("%d * %d = %d" % (a, b, helloworld.mul(a, b)));
print("%f / %f = %f" % (a, b, helloworld.div(a, b)));
