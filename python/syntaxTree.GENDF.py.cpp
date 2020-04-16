#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "pyutilities.hpp"

#include "ENDFtk.hpp"

namespace py = pybind11;
using namespace njoy::ENDFtk;

void py_syntaxTree_GENDF(py::module &m) {

  using namespace syntaxTree;
  using BufferIterator = ranges::iterator_t< const std::string >;
  using Material_t = GendfMaterial< BufferIterator >;
  using Section_t = GendfSection< BufferIterator >;
  using Type_t = section::GendfType< BufferIterator >;

  py::class_< GendfTape >(m, "GendfTape")
    .def(py::init<std::string>())
    .def("hasMaterialNumber", &GendfTape::hasMaterialNumber)
    .def("size", &GendfTape::size)
    .def_property_readonly("materials",
                           [](GendfTape& tape) {
                             return toVector<Material_t>(tape);
                           });

  py::class_< Material_t >(m, "GendfMaterial")
    .def("hasSection", &Material_t::hasSection)
    .def("size", &Material_t::size)
    .def_property_readonly("materialNumber",
                           &Material_t::getMaterialNumber)
    .def_property_readonly("sections",
                           &Material_t::getSections);

  py::class_< Section_t >(m, "GendfSection")
    .def_property_readonly("fileNumber",
                           &Section_t::fileNo)
    .def_property_readonly("sectionNumber",
                           &Section_t::sectionNo)
    .def("parse", (const Type_t (Section_t::*)())
                  &Section_t::parse)
    .def("parse", (const Type_t (Section_t::*)(long&))
                  &Section_t::parse);

  py::class_< Type_t >(m, "GendfType")
    .def_property_readonly("xs",
                           &Type_t::xs);

}
