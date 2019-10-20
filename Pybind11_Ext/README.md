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
git clone --recursive https://github.com/pybind/cmake_example.git
pip install ./cmake_example
```

With the `setup.py` file included in this example, the `pip install` command will
invoke CMake and build the pybind11 module as specified in `CMakeLists.txt`.

*Copied from [the cmake_example repository](https://github.com/pybind/cmake_example)*