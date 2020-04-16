#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "pyutilities.hpp"

#include "ENDFtk.hpp"

namespace py = pybind11;
using namespace njoy::ENDFtk;

void py_section_3(py::module &m) {

  using namespace section;
  using Type_3_t = section::Type< 3 >;

  py::class_< Type_3_t >(m, "Type")
    .def_property_readonly("QM", &Type_3_t::QM)
    .def_property_readonly("QI", &Type_3_t::QI)
    .def_property_readonly("LR", &Type_3_t::LR)
    .def_property_readonly("NR", &Type_3_t::NR)
    .def_property_readonly("NP", &Type_3_t::NP)
    .def_property_readonly("NC", &Type_3_t::NC)
    .def_property_readonly("interpolants", 
                           [](Type_3_t& type) {
                             return toVector<long>(type.interpolants());
                           })
    .def_property_readonly("boundaries", 
                           [](Type_3_t& type) {
                             return toVector<long>(type.boundaries());
                           })
    .def_property_readonly("energies", 
                           [](Type_3_t& type) {
                             return toVector<double>(type.energies());
                           })
    .def_property_readonly("crossSections", 
                           [](Type_3_t& type) {
                             return toVector<double>(type.crossSections());
                           });

}
