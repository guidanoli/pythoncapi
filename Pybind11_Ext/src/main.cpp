#include <pybind11/pybind11.h>

namespace py = pybind11;

unsigned long long factorial(int n) {
    if (n < 0) throw std::domain_error("n! for n < 0 is undefined");
    if (n < 2) return 1;
    return n * factorial(n-1);
}

double divide(double i, double j) {
    if (j == 0.0) throw std::invalid_argument("Cannot divide by zero");
    return i / j;
}

PYBIND11_MODULE(cmake_example, m) {
    m.doc() = R"(
        Pybind11 module doc
        -------------------

        This is a Python extension module written in C++!
    )";

    m.def("add", [](int i, int j) { return i + j; },
        "Add two numbers");

    m.def("subtract", [](int i, int j) { return i - j; },
        "Subtract two numbers");

    m.def("multiply", [](int i, int j) { return i * j; },
        "Multiply two numbers");

    m.def("divide", &divide,
        "Divide two numbers");

    m.def("factorial", &factorial,
        "Obtain the factorial of a number");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
