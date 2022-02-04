/*
 * Copyright 2022 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(framemapperfint_cc.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(f353b425b521bec60e90c4977d5e6741)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <dvbt2ll/framemapperfint_cc.h>
// pydoc.h is automatically generated in the build directory
#include <framemapperfint_cc_pydoc.h>

void bind_framemapperfint_cc(py::module& m)
{

    using framemapperfint_cc    = ::gr::dvbt2ll::framemapperfint_cc;


    py::class_<framemapperfint_cc, gr::block, gr::basic_block,
        std::shared_ptr<framemapperfint_cc>>(m, "framemapperfint_cc", D(framemapperfint_cc))

        .def(py::init(&framemapperfint_cc::make),
           py::arg("framesize"),
           py::arg("rate"),
           py::arg("constellation"),
           py::arg("rotation"),
           py::arg("fecblocks"),
           py::arg("tiblocks"),
           py::arg("carriermode"),
           py::arg("fftsize"),
           py::arg("guardinterval"),
           py::arg("l1constellation"),
           py::arg("pilotpattern"),
           py::arg("t2frames"),
           py::arg("numdatasyms"),
           py::arg("paprmode"),
           py::arg("version"),
           py::arg("preamble"),
           py::arg("inputmode"),
           py::arg("reservedbiasbits"),
           py::arg("l1scrambled"),
           py::arg("inband"),
           D(framemapperfint_cc,make)
        )
        



        ;




}








