# Python/C API

This directory is reserved for using only the Python/C API provided for extending the Python scripting language with C/C++ modules (for CPython implementation).

## Setting up

Be aware that this was build on a Fedora Thirty. Incompatibilities with Windows, Mac OS, or even with other Linux distributions may arise. Well... first, build the extension of your preferred Python version. (You can fiddle around with the Makefile if you wish so)

``` bash
make 2 # for Python 2.x
make 3 # for Python 3.x
make # same as make 3
```

I had to install the Python developer tools in order to have the header files necessary for the `distutils` tool to compile the extension module correctly. See [this StackOverflow question](https://stackoverflow.com/questions/21530577/fatal-error-python-h-no-such-file-or-directory) in order to know how to install the correct package for your Linux distribution.

After downloading the correct packages and compiling successfully, a `.so` will magically pop up. This is the Python C extension. Now, run the test:

``` bash
# With Python 3.x
make 3
python3 test.py
This is Python 3.7.4
10 + 32 = 42

# Cleaning up...
make clean

# With Python 2.x
make 2
python test.py
This is Python 2.7.16
10 + 32 = 42
```

Hooray! My first Python extension module, and working for both Python versions! :)

## Notice

This code was borrowed from [this repository](github.com/starnight/python-c-extension/), by [this user](https://github.com/starnight).

## Analysis

Using the API seemed quite bureaucratic at first, but I enjoyed it quite a bit. The API is really convenient and easy to use. The boilerplate code didn't bothered me that much as to the promoters of pybind11. It would of course make the life a lot easier, but for a few functions in pure C, it's not that big of a pain in the butt. Also, making it cross-version (Python 2.x and 3.x compatible) was only one preprocessor #if in the `bind.c` file.

Also, adding one function to the module requires:
* Implementing the function in C, of course
* Adding its prototype to the header file
* Adding it to the binding source file boilerplate + documentation string
* Adding call to test.py for, well, testing purposes

Hopefully the API extensions such as pybind11 are able to remove of that work, other than providing more compatibility with C++ features.