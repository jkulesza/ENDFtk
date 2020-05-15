#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "ENDFtk.hpp"

namespace py = pybind11;
using namespace njoy::ENDFtk;

void py_TapeIdentification(py::module &m) {

  py::class_< TapeIdentification >(m, "TPID")
    .def(py::init< std::string&&, int >())
    .def("to_string",
         [](TapeIdentification& tpid) {
           std::string buffer;
           auto output = std::back_inserter( buffer );
           tpid.print( output, 0, 0, 0 );
           return buffer;
         });

}
