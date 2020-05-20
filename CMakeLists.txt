# Preamble
cmake_minimum_required( VERSION 3.16 )
project( ENDFtk LANGUAGES CXX )

# Dependencies
include( cmake/ENDFtk_dependencies.cmake )

# Project targets
add_library( ENDFtk INTERFACE )
target_include_directories( ENDFtk INTERFACE src/ )
target_link_libraries( ENDFtk
    INTERFACE range-v3-adapter
    INTERFACE catch-adapter
    INTERFACE disco
    INTERFACE hana-adapter
    INTERFACE header-utilities
    INTERFACE Log )

