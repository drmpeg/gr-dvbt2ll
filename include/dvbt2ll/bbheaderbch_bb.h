/* -*- c++ -*- */
/* 
 * Copyright 2017 Ron Economos.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_DVBT2LL_BBHEADERBCH_BB_H
#define INCLUDED_DVBT2LL_BBHEADERBCH_BB_H

#include <dvbt2ll/api.h>
#include <dvbt2ll/dvbt2ll_config.h>
#include <gnuradio/block.h>

namespace gr {
  namespace dvbt2ll {

    /*!
     * \brief <+description of block+>
     * \ingroup dvbt2ll
     *
     */
    class DVBT2LL_API bbheaderbch_bb : virtual public gr::block
    {
     public:
      typedef std::shared_ptr<bbheaderbch_bb> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of dvbt2ll::bbheaderbch_bb.
       *
       * To avoid accidental use of raw pointers, dvbt2ll::bbheaderbch_bb's
       * constructor is in a private implementation
       * class. dvbt2ll::bbheaderbch_bb::make is the public interface for
       * creating new instances.
       */
      static sptr make(dvbt2_framesize_t framesize, dvbt2_code_rate_t rate, dvbt2_inputmode_t mode, dvbt2_inband_t inband, int fecblocks, int tsrate);
    };

  } // namespace dvbt2ll
} // namespace gr

#endif /* INCLUDED_DVBT2LL_BBHEADERBCH_BB_H */

