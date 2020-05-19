#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

/* forward declarations */
void py_TapeIdentification(py::module &m);
void py_StructureDivision(py::module &m);
void py_syntaxTree(py::module &m);
// void py_syntaxTree_GENDF(py::module &m);
void py_section_1(py::module &m);
void py_section_3(py::module &m);
void py_section_4(py::module &m);
void py_section_5(py::module &m);
void py_section_6(py::module &m);
void py_file_3(py::module &m);

/*
 * Python bindings!!
 */
PYBIND11_MODULE(ENDFtk, m) {
  py_TapeIdentification(m);
  py_StructureDivision(m);
  py_syntaxTree(m);
  // py_syntaxTree_GENDF(m);
  py_section_1(m);
  py_section_3(m);
  py_section_4(m);
  py_section_5(m);
  py_section_6(m);
  py_file_3(m);
}
