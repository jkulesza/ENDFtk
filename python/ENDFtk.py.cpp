#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "ENDFtk.hpp"

namespace py = pybind11;
using namespace njoy::ENDFtk;

/**
 * @brief helper to "bind" std::multimap to Python
 */
template< typename T1, typename T2 >
auto multi2map( const std::multimap<T1,T2> &mmap ) {
  std::map<T1,std::vector<T2>> new_map;
  for (auto it : mmap)
    new_map[it.first].push_back(it.second);
  return new_map;
}

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
                           [](const GendfTape &tape) {
                             return multi2map( tape.getMaterials() );
                           });

  py::class_< GendfMaterial >(m, "GendfMaterial")
    .def("hasSection", &GendfMaterial::hasSection)
    .def("size", &GendfMaterial::size)
    .def_property_readonly("materialNumber",
                           &GendfMaterial::getMaterialNumber);


}
