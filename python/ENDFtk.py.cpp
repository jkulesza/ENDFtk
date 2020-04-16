#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "ENDFtk.hpp"

namespace py = pybind11;
using namespace njoy::ENDFtk;

// wrapper for multimap to Python bindable vector
template< typename T1, typename T2 >
auto toVectorFromMap( const T2& map ) {

  std::vector< const T1* > recast;
  for ( auto& i : map )
    recast.push_back( &i.second ); 

  return recast;
}

// wrapper for view to Python bindable vector
template< typename T1, typename T2 >
auto toVector( const T2& view ) {

  std::vector< const T1* > recast;
  for ( auto& i : view )
    recast.push_back( &i ); 

  return recast;
}

/*
 * Python bindings!!
 */
PYBIND11_MODULE(ENDFtk, m) {

  using namespace syntaxTree;
  using BufferIterator = ranges::iterator_t< std::string >;
  using GM = GendfMaterial< BufferIterator >;
  using GS = GendfSection< BufferIterator >;

  py::class_< GendfTape >(m, "GendfTape")
    .def(py::init<std::string>())
    .def("hasMaterialNumber", &GendfTape::hasMaterialNumber)
    .def("size", &GendfTape::size)
    .def_property_readonly("materials",
                           [](GendfTape& tape) {
                             return toVector<GM>(tape);
                           });

  py::class_< GM >(m, "GendfMaterial")
    .def("hasSection", &GM::hasSection)
    .def("size", &GM::size)
    .def_property_readonly("materialNumber",
                           &GM::getMaterialNumber)
    .def_property_readonly("sections",
                           &GM::getSections);

  py::class_< GS >(m, "GendfSection")
    .def_property_readonly("fileNumber",
                           &GS::fileNo)
    .def_property_readonly("sectionNumber",
                           &GS::sectionNo)
    .def("parse", (const section::GendfType (GS::*)())
                  &GS::parse)
    .def("parse", (const section::GendfType (GS::*)(long&))
                  &GS::parse);

  py::class_< section::GendfType >(m, "GendfType")
    .def_property_readonly("xs",
                           &section::GendfType::xs);

}
