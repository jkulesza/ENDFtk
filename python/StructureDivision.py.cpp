#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "ENDFtk.hpp"

namespace py = pybind11;
using namespace njoy::ENDFtk;

void py_StructureDivision(py::module &m) {

  py::class_< StructureDivision >(m, "StructureDivision")
    .def("to_string",
         [](StructureDivision& div) {
           std::string buffer;
           auto output = std::back_inserter( buffer );
           div.print( output );
           return buffer;
         });

  m.def("SEND", &SEND);
  m.def("MEND", &MEND);
  m.def("TEND", &TEND);

}
