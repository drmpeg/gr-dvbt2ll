# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT dvbt2ll_sources)
    MESSAGE(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT dvbt2ll_sources)

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND dvbt2ll_python_files
    bbheaderbch_bb_python.cc
    framemapperfint_cc_python.cc
    interleavermod_bc_python.cc
    pilotgenp1insert_cc_python.cc
    dvbt2ll_config_python.cc python_bindings.cc)

GR_PYBIND_MAKE_OOT(dvbt2ll
   ../..
   gr::dvbt2ll
   "${dvbt2ll_python_files}")

# copy in bindings .so file for use in QA test module
add_custom_target(
  copy_bindings_for_tests ALL
  COMMAND
    ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/*.so"
    ${CMAKE_BINARY_DIR}/test_modules/dvbt2ll/
  DEPENDS dvbt2ll_python)

install(TARGETS dvbt2ll_python DESTINATION ${GR_PYTHON_DIR}/dvbt2ll COMPONENT pythonapi)
