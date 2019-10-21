# Pybind11 extension

So, the Python/C API is not that bad, but does not support C++ data structures from the Standard Template Library (STL), and has a bunch of boilerplate that you have to add for every new function of your extension module.

Pybind11 tries to solve that issue by providing a handful of headers which contains plenty of useful macros and function-like macros. It also provides support for iterating through Python iterables (lists, dicts, sets...) and STL iterables (vectors, sets...), plus many other useful features.

## Requirements

Since I am making use of the CMake file provided by [this repository](https://github.com/pybind/cmake_example) (crafted from the same crew of [pybind11](https://github.com/pybind)), the requirements are the same for the Python/C API subdirectory plus the additional requirements for the pybind11 files.

**On Unix (Linux, OS X)**

* A compiler with C++11 support
* CMake >= 2.8.12

**On Windows**

* Visual Studio 2015 (required for all Python versions, see notes below)
* CMake >= 3.1

*Copied from [the cmake_example repository](https://github.com/pybind/cmake_example)*

## Installation

Just clone this repository and pip install. Note the `--recursive` option which is
needed for the pybind11 submodule:

```bash
git clone --recursive https://github.com/guidanoli/pythoncapi.git
python setup.py install
```

The `setup.py` file included in this example will invoke CMake and build the pybind11 module as specified in `CMakeLists.txt`.

*Copied and edited from [the cmake_example repository](https://github.com/pybind/cmake_example)*

## Test

Just go to the /tests/ folder and run the test Python script.

```bash
python test.py
```

Or simply go to your Python interpreter and fiddle around with the functions yourself.

```bash
$ pyton
Python 3.7.4 (tags/v3.7.4:e09359112e, Jul  8 2019, 20:34:20) [MSC v.1916 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license" for more information.
>>> import cmake_example as m
>>> help(m)
Help on module cmake_example:

NAME
    cmake_example

DESCRIPTION
    Pybind11 module doc
    -------------------

    This is a Python extension module written in C++!

FUNCTIONS
    add(...) method of builtins.PyCapsule instance
        add(arg0: int, arg1: int) -> int

        Add two numbers

    divide(...) method of builtins.PyCapsule instance
        divide(arg0: float, arg1: float) -> float

        Divide two numbers

    factorial(...) method of builtins.PyCapsule instance
        factorial(arg0: int) -> int

        Obtain the factorial of a number

    multiply(...) method of builtins.PyCapsule instance
        multiply(arg0: int, arg1: int) -> int

        Multiply two numbers

    subtract(...) method of builtins.PyCapsule instance
        subtract(arg0: int, arg1: int) -> int

        Subtract two numbers

VERSION
    0.0.1

FILE
    c:\users\guidanoli\appdata\local\programs\python\python37\lib\site-packages\cmake_example-0.0.1-py3.7-win-amd64.egg\cmake_example.cp37-win_amd64.pyd


>>> m.factorial(10)
3628800
>>> m.divide(1,0)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
ValueError: Cannot divide by zero
```
