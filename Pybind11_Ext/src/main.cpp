#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <numeric>
#include <random>

namespace py = pybind11;

class Model {
  public:
    Model(const std::string &name) : m_name(name) {
      std::generate(m_data.begin(), m_data.end(), std::rand);
    }
    std::string getName() { return m_name; }
  private:
    std::string m_name;
    std::vector<int> m_data;
};

class Geresim {
  public:
    Geresim() {}
};

PYBIND11_MODULE(geresim, m) {
    m.doc() = R"(
        Geresim data module
        -------------------
    )";
    
#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
