cmake_minimum_required( VERSION 3.14 )
include( FetchContent )

#######################################################################
# Declare project dependencies
#######################################################################

FetchContent_Declare( catch-adapter
    GIT_REPOSITORY  https://github.com/njoy/catch-adapter
    GIT_TAG         fb84b82ebf7a4789aa43cea560680cf745c6ee4f
    )

FetchContent_Declare( disco
    GIT_REPOSITORY  https://github.com/njoy/disco
    GIT_TAG         178a03cf4a571fee028b008ffac85e20f6059ade
    )

FetchContent_Declare( hana
    GIT_REPOSITORY  https://github.com/boostorg/hana.git
    GIT_TAG         07b42492765f7384e053c4761f4d0eda32b75834
    )

FetchContent_Declare( header-utilities
    GIT_REPOSITORY  https://github.com/njoy/header-utilities
    GIT_TAG         7d575429926e033acd18340d04e44d1bc51f19d5
    )

FetchContent_Declare( Log
    GIT_REPOSITORY  https://github.com/njoy/Log
    GIT_TAG         9e99c58ab5745a4e6053ec2b92a1619295284804
    )

FetchContent_Declare( range-v3-adapter
    GIT_REPOSITORY  https://github.com/njoy/range-v3-adapter
    GIT_TAG         4d1a3bde6aba47ca59a65713f9cab7877ad2cc87
    )

FetchContent_Declare( spdlog
    GIT_REPOSITORY  https://github.com/gabime/spdlog.git
    GIT_TAG         a51b4856377a71f81b6d74b9af459305c4c644f8
    GIT_SHALLOW     TRUE
    )
set( SPDLOG_BUILD_TESTING CACHE BOOL OFF )

#######################################################################
# Load dependencies
#######################################################################

FetchContent_MakeAvailable(
    catch-adapter
    disco
    hana
    header-utilities
    Log
    range-v3-adapter
    spdlog
    )
