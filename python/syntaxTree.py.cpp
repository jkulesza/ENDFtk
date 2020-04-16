#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "pyutilities.hpp"

#include "ENDFtk.hpp"

namespace py = pybind11;
using namespace njoy::ENDFtk;

void py_syntaxTree(py::module &m) {

  using namespace syntaxTree;
  using BufferIterator = ranges::iterator_t< const std::string >;
  using Tape_t = Tape< std::string >;
  using Material_t = Material< BufferIterator >;
  using File_t = File< BufferIterator >;
  using Section_t = Section< BufferIterator >;
  using Type_3_t = section::Type< 3 >;

  py::class_< Tape_t >(m, "Tape")
    .def(py::init<std::string>())
    .def("hasMaterialNumber", &Tape_t::hasMaterialNumber)
    .def("size", &Tape_t::size)
    .def_property_readonly("materials",
                           [](Tape_t& tape) {
                             return toVector<Material_t>(tape);
                           });

  py::class_< Material_t >(m, "Material")
    .def("hasFileNumber", &Material_t::hasFileNumber)
    .def("size", &Material_t::size)
    .def("MF", (File_t& (Material_t::*)(int))
               &Material_t::MF)
    .def_property_readonly("materialNumber",
                           &Material_t::materialNumber)
    .def_property_readonly("files",
                           [](Material_t& matl) {
                             return toVector<File_t>(matl);
                           });

  py::class_< File_t >(m, "File")
    .def("hasSectionNumber", &File_t::hasSectionNumber)
    .def("size", &File_t::size)
    .def("MT", (Section_t& (File_t::*)(int))
               &File_t::MT)
    .def_property_readonly("fileNumber",
                           &File_t::fileNumber)
    .def_property_readonly("sections",
                           [](File_t& file) {
                             return toVector<Section_t>(file);
                           });

  py::class_< Section_t >(m, "Section")
    .def_property_readonly("sectionNumber",
                           &Section_t::sectionNumber)
    .def_property_readonly("buffer",
                           [](Section_t& sec) {
                             return std::string(sec.buffer().begin(),
                                                sec.buffer().end());
                           })
    .def("parse", (Type_3_t (Section_t::*)() const)
                  &Section_t::parse<3>)
    .def("parse", (Type_3_t (Section_t::*)(long&) const)
                  &Section_t::parse<3>);

}
