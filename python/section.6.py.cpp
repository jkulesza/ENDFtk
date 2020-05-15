#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "ENDFtk.hpp"

namespace py = pybind11;
using namespace njoy::ENDFtk;

void py_section_6(py::module &m) {

  using namespace section;
  using Type_6_t = section::Type< 6 >;
  using ReactionProduct = Type_6_t::ReactionProduct;

  py::class_< Type_6_t >(m, "Type6")
    .def_property_readonly("JP", &Type_6_t::JP)
    .def_property_readonly("averageMultipleParticlesFlag",
                           &Type_6_t::averageMultipleParticlesFlag)
    .def_property_readonly("LCT", &Type_6_t::LCT)
    .def_property_readonly("referenceFrame", &Type_6_t::referenceFrame)
    .def_property_readonly("NK", &Type_6_t::NK)
    .def_property_readonly("numberSubSections", &Type_6_t::numberSubSections)
    .def_property_readonly("products",
                           [](Type_6_t& type) {
                             return type.products() | ranges::to_vector;
                           })
    .def_property_readonly("ZA", [](Type_6_t& type) { return type.ZA(); })
    .def_property_readonly("AWR", [](Type_6_t& type) { return type.AWR(); })
  ;

  py::class_< ReactionProduct >(m, "ReactionProduct")
    .def_property_readonly("ZAP", &ReactionProduct::ZAP)
    .def_property_readonly("productIdentifier", &ReactionProduct::productIdentifier)
    .def_property_readonly("AWP", &ReactionProduct::AWP)
    .def_property_readonly("productMassRatio", &ReactionProduct::productMassRatio)
    .def_property_readonly("LIP", &ReactionProduct::LIP)
    .def_property_readonly("productModifierFlag", &ReactionProduct::productModifierFlag)
    .def_property_readonly("LAW", &ReactionProduct::LAW)
    .def_property_readonly("distribution", &ReactionProduct::distribution)
  ;

  /* LAW 2 namespace */
  py::module m_law2 = m.def_submodule("LAW2");
  using LAW2 = Type_6_t::DiscreteTwoBodyScattering;
  using SubSection = LAW2::SubSection;
  using LegendreCoefficients = LAW2::LegendreCoefficients;

  py::class_< LAW2 >(m_law2, "DiscreteTwoBodyScattering")
    .def_property_readonly("LAW", &LAW2::LAW)
    .def_property_readonly("subsections",
                           [](LAW2& law) {
                             return law.subsections() | ranges::to_vector;
                           })
  ;

  py::class_< SubSection >(m_law2, "SubSection")
    .def_property_readonly("energy", &SubSection::energy)
    .def_property_readonly("LANG", &SubSection::LANG)
    .def_property_readonly("NL", &SubSection::NL)
    .def_property_readonly("data", &SubSection::data)
  ;

  py::class_< LegendreCoefficients >(m_law2, "LegendreCoefficients")
    .def_property_readonly("energy", &LegendreCoefficients::energy)
    .def_property_readonly("LANG", &LegendreCoefficients::LANG)
    .def_property_readonly("NL", &LegendreCoefficients::NL)
    .def_property_readonly("legendreOrder", &LegendreCoefficients::legendreOrder)
    .def_property_readonly("coefficients",
                           [](LegendreCoefficients& coeff) {
                             return coeff.coefficients() | ranges::to_vector;
                           })
  ;


  /* LAW 5 namespace */
  py::module m_law5 = m.def_submodule("LAW5");
  using LAW5 = Type_6_t::ChargedParticleElasticScattering;
  using SubSection5 = LAW5::SubSection;
  using LegendreCoefficients5 = LAW5::LegendreCoefficients;
  using NuclearAmplitudeExpansion = LAW5::NuclearAmplitudeExpansion;

  py::class_< LAW5 >(m_law5, "ChargedParticleElasticScattering")
    .def_property_readonly("LAW", &LAW5::LAW)
    .def_property_readonly("LIDP", &LAW5::LIDP)
    .def_property_readonly("identicalParticles", &LAW5::identicalParticles)
    .def_property_readonly("subsections",
                           [](LAW5& law) {
                             return law.subsections() | ranges::to_vector;
                           })
  ;

  py::class_< SubSection5 >(m_law5, "SubSection")
    .def_property_readonly("energy", &SubSection5::energy)
    .def_property_readonly("LTP", &SubSection5::LTP)
    .def_property_readonly("NL", &SubSection5::NL)
    .def_property_readonly("data", &SubSection5::data)
  ;

  py::class_< LegendreCoefficients5 >(m_law5, "LegendreCoefficients")
    .def_property_readonly("energy", &LegendreCoefficients5::energy)
    .def_property_readonly("LTP", &LegendreCoefficients5::LTP)
    .def_property_readonly("NL", &LegendreCoefficients5::NL)
    .def_property_readonly("coefficients",
                           [](LegendreCoefficients& coeff) {
                             return coeff.coefficients() | ranges::to_vector;
                           })
  ;

  py::class_< NuclearAmplitudeExpansion >(m_law5, "NuclearAmplitudeExpansion")
    .def_property_readonly("energy", &NuclearAmplitudeExpansion::energy)
    .def_property_readonly("LTP",    &NuclearAmplitudeExpansion::LTP)
    .def_property_readonly("scatteringCoefficients",
                           [](NuclearAmplitudeExpansion& nae) {
                             return nae.scatteringCoefficients()
                               | ranges::to_vector;
                           })
    .def_property_readonly("realInterferenceCoefficients",
                           [](NuclearAmplitudeExpansion& nae) {
                             return nae.realInterferenceCoefficients()
                               | ranges::to_vector;
                           })
    .def_property_readonly("imaginaryInterferenceCoefficients",
                           [](NuclearAmplitudeExpansion& nae) {
                             return nae.imaginaryInterferenceCoefficients()
                               | ranges::to_vector;
                           })
  ;

}
