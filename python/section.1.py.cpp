#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "ENDFtk.hpp"

namespace py = pybind11;
using namespace njoy::ENDFtk;

void py_section_1(py::module &m) {

  using namespace section;
  using Type_1_t = section::Type< 1, 451 >;

  py::class_< Type_1_t >(m, "Type1")
    .def_property_readonly("MT", [](Type_1_t& type) { return type.MT(); })
    .def_property_readonly("ZA", [](Type_1_t& type) { return type.ZA(); })
    .def_property_readonly("AWR", [](Type_1_t& type) { return type.AWR(); })
    .def_property_readonly("LRP", &Type_1_t::LRP)
    .def_property_readonly("LFI", &Type_1_t::LFI)
    .def_property_readonly("NLIB", &Type_1_t::NLIB)
    .def_property_readonly("NMOD", &Type_1_t::NMOD)
    .def_property_readonly("ELIS", &Type_1_t::ELIS)
    .def_property_readonly("STA", &Type_1_t::STA)
    .def_property_readonly("LIS", &Type_1_t::LIS)
    .def_property_readonly("LISO", &Type_1_t::LISO)
    .def_property_readonly("NFOR", &Type_1_t::NFOR)
    .def_property_readonly("AWI", &Type_1_t::AWI)
    .def_property_readonly("EMAX", &Type_1_t::EMAX)
    .def_property_readonly("LREL", &Type_1_t::LREL)
    .def_property_readonly("NSUB", &Type_1_t::NSUB)
    .def_property_readonly("NVER", &Type_1_t::NVER)
    .def_property_readonly("TEMP", &Type_1_t::TEMP)
    .def_property_readonly("LDRV", &Type_1_t::LDRV)
    .def_property_readonly("NWD", &Type_1_t::NWD)
    .def_property_readonly("NXC", &Type_1_t::NXC)
    .def_property_readonly("index",
                           [](Type_1_t& type) {
                             return type.index() | ranges::to_vector;
                           })
    .def_property_readonly("NC", &Type_1_t::NC)
    .def_property_readonly("description",
                           [](Type_1_t& type) {
                             return type.description()
                               | ranges::to_<std::string>();
                           });

}
