// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// other includes
#include "views.hpp"

// namespace aliases
namespace python = pybind11;

// declarations - records
void wrapDirectoryRecord( python::module& );

// declarations - files
void wrapFile_1( python::module& );
void wrapFile_3( python::module& );

// declarations - tree
void wrapTreeSection( python::module& );
void wrapTreeFile( python::module& );
void wrapTreeMaterial( python::module& );
void wrapTreeTape( python::module& );
// void wrapMakeTreeTape( python::module& );

/**
 *  @brief ENDFtk python bindings
 *
 *  The name given here (ENDFtk) must be the same as the name
 *  set on the PROPERTIES OUTPUT_NAME in the CMakeLists.txt file.
 */
PYBIND11_MODULE( ENDFtk, module ) {

  // wrap some basic recurring views
  // none of these are supposed to be created directly by the user
  wrapRandomAccessAnyViewOf< double >( module,
                                       "any_view< double, random_access >" );
  wrapRandomAccessAnyViewOf< long >( module,
                                     "any_view< long, random_access >" );

  // wrap records
  wrapDirectoryRecord( module );

  // wrap files
  wrapFile_1( module );
  wrapFile_3( module );

  // create the submodule
  python::module submodule = module.def_submodule(

    "tree",
    "tree - ENDF tree components"
  );

  // wrap tree
  wrapTreeSection( submodule );
  wrapTreeFile( submodule );
  wrapTreeMaterial( submodule );
  wrapTreeTape( submodule );

  // module.def(
  //
  //   "add",
  //   [] ( int left, int right ) { return left + right; },
  //   python::arg( "left" ), python::arg( "right" ),
  //   "Return the sum of two integers\n\n"
  //   "This function does not throw an exception.\n\n"
  //   "Arguments:\n"
  //   "    left    the integer on the left\n"
  //   "    right   the integer on the right"
  // );

}
