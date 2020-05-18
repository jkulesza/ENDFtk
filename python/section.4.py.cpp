#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "ENDFtk.hpp"

namespace py = pybind11;
using namespace njoy::ENDFtk;

void py_section_4(py::module &m) {

  using namespace section;
  using Type_4_t = section::Type< 4 >;

  py::class_< Type_4_t >(m, "Type4", py::dynamic_attr())
    .def_property_readonly("LCT", &Type_4_t::LCT)
    .def_property_readonly("referenceFrame", &Type_4_t::referenceFrame)
    .def_property_readonly("LTT", &Type_4_t::LTT)
    .def_property_readonly("LAW", &Type_4_t::LAW)
    .def_property_readonly("LI", &Type_4_t::LI)
    .def_property_readonly("isotropicAngularDistributions",
                           &Type_4_t::isotropicAngularDistributions)
    .def_property_readonly("_distributions", &Type_4_t::distributions)
  ;

  /* Define submodule for various distribution types. */
  py::module m_mf4 = m.def_submodule("MF4");

  /* Distribution classes */
  using LegendreCoefficients = Type_4_t::LegendreCoefficients;
  py::class_< LegendreCoefficients >(m_mf4, "LegendreCoefficients")
    .def_property_readonly("E", &LegendreCoefficients::E)
    .def_property_readonly("incidentEnergy",
                           &LegendreCoefficients::incidentEnergy)
  ;

  using TabulatedDistribution = Type_4_t::TabulatedDistribution;
  py::class_< TabulatedDistribution >(m_mf4, "TabulatedDistribution")
    .def_property_readonly("E", &TabulatedDistribution::E)
    .def_property_readonly("incidentEnergy",
                           &TabulatedDistribution::incidentEnergy)
  ;

  /* Containers of distributions */
  using LTT0 = Type_4_t::Isotropic;
  py::class_< Type_4_t::Isotropic >(m_mf4, "Isotropic");

  using LTT1 = Type_4_t::LegendreDistributions;
  py::class_< LTT1 >(m_mf4, "LegendreDistributions")
    .def_property_readonly("angularDistributions",
                           [] (LTT1& dist) {
                             return dist.angularDistributions()
                               | ranges::to_vector;
                           })
  ;

  using LTT2 = Type_4_t::TabulatedDistributions;
  py::class_< LTT2 >(m_mf4, "TabulatedDistributions")
    .def_property_readonly("angularDistributions",
                           [] (LTT2& dist) {
                             return dist.angularDistributions()
                               | ranges::to_vector;
                           })
  ;

  using LTT3 = Type_4_t::MixedDistributions;
  py::class_< LTT3 >(m_mf4, "MixedDistributions")
    .def_property_readonly("angularDistributions",
                           [] (LTT3& dist) {
                             return dist.angularDistributions()
                               | ranges::to_vector;
                           })
  ;

}
