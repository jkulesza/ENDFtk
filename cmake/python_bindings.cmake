message( STATUS "Creating ENDFtk Python bindings" )


#######################################################################
# Load dependencies
#######################################################################

FetchContent_MakeAvailable( pybind11 )


#######################################################################
# Define Python bindings target
#######################################################################

pybind11_add_module( pyENDFtk python/ENDFtk.py.cpp
                               python/TapeIdentification.py.cpp
                               python/StructureDivision.py.cpp
                               python/syntaxTree.py.cpp
                               # python/syntaxTree.GENDF.py.cpp
                               python/section.1.py.cpp
                               python/section.3.py.cpp
                               python/section.4.py.cpp
                               python/section.5.py.cpp
                               python/section.6.py.cpp
                               python/file.3.py.cpp )
target_include_directories( pyENDFtk PUBLIC python )
target_link_libraries( pyENDFtk PUBLIC ENDFtk )
set_target_properties( pyENDFtk PROPERTIES
                                 OUTPUT_NAME ENDFtk
                                 )
