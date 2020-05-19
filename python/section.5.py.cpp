#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "ENDFtk.hpp"

namespace py = pybind11;
using namespace njoy::ENDFtk;

void py_section_5(py::module &m) {

  using namespace section;
  using Type_5_t = section::Type< 5 >;

  py::class_< Type_5_t >(m, "Type5", py::dynamic_attr())
    .def_property_readonly("NK", &Type_5_t::NK)
    .def_property_readonly("numberPartialDistributions",
                           &Type_5_t::numberPartialDistributions)
    .def_property_readonly("distributions",
                           [] (Type_5_t& type) {
                             return type.distributions()
                               | ranges::to_vector;
                           })
  ;

  /* Define submodule for various distribution types. */
  py::module m_mf5 = m.def_submodule("MF5");

  /* Subsection container */
  using Subsection = Type_5_t::Subsection;
  py::class_< Subsection >(m_mf5, "Subsection")
    .def_property_readonly("p", &Subsection::p)
    .def_property_readonly("probability", &Subsection::probability)
    .def_property_readonly("distribution", &Subsection::distribution)
  ;

  /* Probability class */
  using PartialProbability = Type_5_t::PartialProbability;
  py::class_< PartialProbability >(m_mf5, "PartialProbability")
    .def_property_readonly("LF", &PartialProbability::LF)
    .def_property_readonly("LAW", &PartialProbability::LAW)
    .def_property_readonly("E",
                           [] (PartialProbability& prob) {
                             return prob.E()
                               | ranges::to_vector;
                           })
    .def_property_readonly("energies",
                           [] (PartialProbability& prob) {
                             return prob.energies()
                               | ranges::to_vector;
                           })
    .def_property_readonly("p",
                           [] (PartialProbability& prob) {
                             return prob.p()
                               | ranges::to_vector;
                           })
    .def_property_readonly("probabilities",
                           [] (PartialProbability& prob) {
                             return prob.probabilities()
                               | ranges::to_vector;
                           })
  ;

  /* Distribution classes */
  using LF1 = Type_5_t::TabulatedSpectrum;
  py::class_< LF1 >(m_mf5, "TabulatedSpectrum")
  ;
  
  using LF5 = Type_5_t::GeneralEvaporationSpectrum;
  py::class_< LF5 >(m_mf5, "GeneralEvaporationSpectrum")
  ;

  using LF7 = Type_5_t::MaxwellianFissionSpectrum;
  py::class_< LF7 >(m_mf5, "MaxwellianFissionSpectrum")
  ;

  using LF9 = Type_5_t::EvaporationSpectrum;
  py::class_< LF9 >(m_mf5, "EvaporationSpectrum")
  ;

  using LF11 = Type_5_t::WattSpectrum;
  py::class_< LF11 >(m_mf5, "WattSpectrum")
  ;

  using LF12 = Type_5_t::MadlandNixSpectrum;
  py::class_< LF12 >(m_mf5, "MadlandNixSpectrum")
  ;

}
