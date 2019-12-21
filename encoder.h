/*
	Copyright 2016 Benjamin Vedder	benjamin@vedder.se

	This file is part of the VESC firmware.

	The VESC firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    The VESC firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

#ifndef ENCODER_H_
#define ENCODER_H_

#include "conf_general.h"

// Functions
void encoder_deinit(void);
void encoder_init_abi(uint32_t counts);
void encoder_init_as5047p_spi(void);
void encoder_init_ad2s1205_spi(void);
void encoder_init_sincos(float sin_gain, float sin_offset,
						 float cos_gain, float cos_offset, float sincos_filter_constant);
void encoder_init_ts5700n8501(void);
bool encoder_is_configured(void);
float encoder_read_deg(void);
void encoder_reset(void);
void encoder_tim_isr(void);
void encoder_set_counts(uint32_t counts);
bool encoder_index_found(void);

uint16_t encoder_spi_get_val(void);
uint32_t encoder_spi_get_error_cnt(void);
float encoder_spi_get_error_rate(void);
uint32_t encoder_sincos_get_signal_below_min_error_cnt(void);
uint32_t encoder_sincos_get_signal_above_max_error_cnt(void);
float encoder_sincos_get_signal_below_min_error_rate(void);
float encoder_sincos_get_signal_above_max_error_rate(void);

#endif /* ENCODER_H_ */
