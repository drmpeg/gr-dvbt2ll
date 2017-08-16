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

#ifndef INCLUDED_DVBT2LL_BBHEADERBCH_BB_IMPL_H
#define INCLUDED_DVBT2LL_BBHEADERBCH_BB_IMPL_H

#include <dvbt2ll/bbheaderbch_bb.h>

#define MAX_BCH_PARITY_BITS 192

typedef struct{
    int ts_gs;
    int sis_mis;
    int ccm_acm;
    int issyi;
    int npd;
    int ro;
    int isi;
    int upl;
    int dfl;
    int sync;
    int syncd;
}BBHeader;

typedef struct{
   BBHeader bb_header;
}FrameFormat;

namespace gr {
  namespace dvbt2ll {

    class bbheaderbch_bb_impl : public bbheaderbch_bb
    {
     private:
      unsigned int kbch;
      unsigned int nbch;
      unsigned int count;
      unsigned char crc;
      unsigned int input_mode;
      unsigned int extra;
      unsigned int frame_size;
      unsigned int frame_size_type;
      unsigned int q_val;
      unsigned int code_rate;
      unsigned char bsave;
      int inband_type_b;
      int fec_blocks;
      int fec_block;
      int ts_rate;
      FrameFormat m_format[1];
      unsigned char crc_tab[256];
      unsigned char bb_randomise[FRAME_SIZE_NORMAL];
      unsigned int bch_code;
      std::bitset<MAX_BCH_PARITY_BITS> crc_table[256];
      unsigned int num_parity_bits;
      std::bitset<MAX_BCH_PARITY_BITS> polynome;
      void calculate_crc_table();
      void add_bbheader(unsigned char *, int, int);
      void build_crc8_table(void);
      int add_crc8_bits(unsigned char *, int);
      void add_inband_type_b(unsigned char *, int);
      void init_bb_randomiser(void);
      int poly_mult(const int*, int, const int*, int, int*);
      void bch_poly_build_tables(void);
      void bch_calculate(unsigned char *);
      void ldpc_calculate(unsigned char *);
      void ldpc_lookup_generate(void);

      int** ldpc_lut;

      const static int ldpc_tab_1_2N[90][9];
      const static int ldpc_tab_3_5N[108][13];
      const static int ldpc_tab_2_3N_DVBT2[120][14];
      const static int ldpc_tab_3_4N[135][13];
      const static int ldpc_tab_4_5N[144][12];
      const static int ldpc_tab_5_6N[150][14];

      const static int ldpc_tab_1_3S[15][13];
      const static int ldpc_tab_2_5S[18][13];
      const static int ldpc_tab_1_2S[20][9];
      const static int ldpc_tab_3_5S_DVBT2[27][13];
      const static int ldpc_tab_2_3S[30][14];
      const static int ldpc_tab_3_4S[33][13];
      const static int ldpc_tab_4_5S[35][4];
      const static int ldpc_tab_5_6S[37][14];

     public:
      bbheaderbch_bb_impl(dvbt2_framesize_t framesize, dvbt2_code_rate_t rate, dvbt2_inputmode_t mode, dvbt2_inband_t inband, int fecblocks, int tsrate);
      ~bbheaderbch_bb_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace dvbt2ll
} // namespace gr

#endif /* INCLUDED_DVBT2LL_BBHEADERBCH_BB_IMPL_H */

