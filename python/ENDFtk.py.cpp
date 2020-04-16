#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

/* forward declarations */
void py_syntaxTree(py::module &m);
void py_syntaxTree_GENDF(py::module &m);
void py_section_3(py::module &m);

/*
 * Python bindings!!
 */
PYBIND11_MODULE(ENDFtk, m) {
  py_syntaxTree(m);
  py_syntaxTree_GENDF(m);
  py_section_3(m);
}
