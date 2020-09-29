#ifndef NJOY_ENDFTK_PYTHON_SEQUENCE
#define NJOY_ENDFTK_PYTHON_SEQUENCE

// system includes

// other includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "range/v3/view/any_view.hpp"
#include "range/v3/distance.hpp"
#include "range/v3/index.hpp"
#include "range/v3/at.hpp"
#include "range/v3/utility/iterator.hpp"
#include "range/v3/to_container.hpp"

namespace py = pybind11;

template < typename T >
using RandomAccessAnyView = ranges::any_view< T, ranges::category::random_access >;

template < typename T >
void wrapSequenceOf( py::module& module, const std::string& name ) {

  py::class_< RandomAccessAnyView< T > >( module, name.c_str() )
  .def( "__len__",
      	[] ( RandomAccessAnyView< T >& view )
           { return ranges::distance( view ); } )
  .def( "__getitem__",
      	[] ( RandomAccessAnyView< T >& view, int i )
           { return ranges::index( view, i ); },
   	    py::return_value_policy::reference_internal )
  .def( "__iter__",
  	    [] ( RandomAccessAnyView< T >& view )
           { return py::make_iterator<
                        py::return_value_policy::reference_internal,
  				              ranges::iterator_t< RandomAccessAnyView< T > >,
  				              ranges::sentinel_t< RandomAccessAnyView< T > >,
  				              T >( view.begin(), view.end() ); },
  	    py::keep_alive< 0, 1 >() )
  .def( "list",
      	[] ( RandomAccessAnyView< T >& view ) -> std::vector< T >
           { return view; } );
}

#endif
