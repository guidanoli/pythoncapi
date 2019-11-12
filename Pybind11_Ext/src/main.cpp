#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <numeric>

namespace py = pybind11;

unsigned long long factorial(int n) {
    if (n < 0)
      throw std::domain_error("n! for n < 0 is undefined");
    if (n < 2) return 1;
    return n * factorial(n-1);
}

double divide(double i, double j) {
    if (j == 0.0)
      throw std::invalid_argument("Cannot divide by zero");
    return i / j;
}

std::vector<int> fib(int n) {
  if (n < 0) throw std::invalid_argument("n > 0");
  std::vector<int> v;
  for (int i = 0; i < n; ++i) {
    int fn;
    if (v.size() < 2) fn = 1;
    else fn = v.back() + v.at(v.size()-2);
    v.push_back(fn);
  }
  return v;
}

class Person {
  public:
    Person(const std::string &name) : m_name(name) {}
    std::string getName() { return m_name; }
  private:
    std::string m_name;
};

class Elder : public Person {
  public:
    Elder(const std::string &name) : Person(name) {}
    std::string getName() { return "Mr(s). " + Person::getName(); }
};

class Baby : public Person {
  public:
    Baby(const std::string &name) : Person(name) {}
    std::string getName() { return "Little " + Person::getName(); }
};

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
    
    m.def("mean", [](const std::vector<int> &v) {
      return std::accumulate(v.begin(),v.end(),0.0)/v.size();
    }, "Obtain the mean value of a list");

    m.def("fib", &fib,
      "Obtain the n first numbers of the Fibonacci sequence");
    
    py::class_<Person> person_class(m, "Person");
    person_class
        .def(py::init<std::string>())
        .def("name", &Person::getName);
    
    /* Either reference parent's class_ object */
    py::class_<Elder>(m, "Elder", person_class)
        .def(py::init<std::string>())
        .def("name", &Elder::getName);
    
    /* Or reference parent's C++ class */
    py::class_<Baby, Person>(m, "Baby")
        .def(py::init<std::string>())
        .def("name", &Baby::getName);
    
#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
