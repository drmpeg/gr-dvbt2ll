/* -*- c++ -*- */

#define DVBT2LL_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "dvbt2ll_swig_doc.i"

%{
#include "dvbt2ll/dvbt2ll_config.h"
#include "dvbt2ll/bbheaderbch_bb.h"
#include "dvbt2ll/interleavermod_bc.h"
#include "dvbt2ll/framemapperfint_cc.h"
#include "dvbt2ll/pilotgenp1insert_cc.h"
%}


%include "dvbt2ll/dvbt2ll_config.h"
%include "dvbt2ll/bbheaderbch_bb.h"
GR_SWIG_BLOCK_MAGIC2(dvbt2ll, bbheaderbch_bb);
%include "dvbt2ll/interleavermod_bc.h"
GR_SWIG_BLOCK_MAGIC2(dvbt2ll, interleavermod_bc);
%include "dvbt2ll/framemapperfint_cc.h"
GR_SWIG_BLOCK_MAGIC2(dvbt2ll, framemapperfint_cc);
%include "dvbt2ll/pilotgenp1insert_cc.h"
GR_SWIG_BLOCK_MAGIC2(dvbt2ll, pilotgenp1insert_cc);
