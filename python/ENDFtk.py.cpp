#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "ENDFtk.hpp"

namespace py = pybind11;
using namespace njoy::ENDFtk;


/*
 * Python bindings!!
 */
PYBIND11_MODULE(ENDFtk, m) {

  using namespace syntaxTree;

  py::class_< GendfTape >(m, "GendfTape")
    .def(py::init<std::string>())
    .def("hasMaterialNumber", &GendfTape::hasMaterialNumber)
    .def("size", &GendfTape::size)
    .def_property_readonly("materials",
                           [](GendfTape& tape) {
                             tape.convertMap();
                             return tape.getMaterialsAsMap();
                           });

  py::class_< GendfMaterial >(m, "GendfMaterial")
    .def("hasSection", &GendfMaterial::hasSection)
    .def("size", &GendfMaterial::size)
    .def_property_readonly("materialNumber",
                           &GendfMaterial::getMaterialNumber)
    .def_property_readonly("sections",
                           &GendfMaterial::getSections);

  py::class_< GendfSection >(m, "GendfSection")
    .def_property_readonly("fileNumber",
                           &GendfSection::fileNo)
    .def_property_readonly("sectionNumber",
                           &GendfSection::sectionNo)
    .def("parse", (const section::GendfType (GendfSection::*)())
                  &GendfSection::parse)
    .def("parse", (const section::GendfType (GendfSection::*)(long&))
                  &GendfSection::parse);

  py::class_< section::GendfType >(m, "GendfType")
    .def_property_readonly("xs",
                           &section::GendfType::xs);

}
