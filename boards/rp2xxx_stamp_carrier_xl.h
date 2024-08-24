/*
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// -----------------------------------------------------
// NOTE: THIS HEADER IS ALSO INCLUDED BY ASSEMBLER SO
//       SHOULD ONLY CONSIST OF PREPROCESSOR DIRECTIVES
// -----------------------------------------------------

// This header may be included by other board headers as "boards/solderparty_rp2xxx_stamp_carrier_xl.h"

// pico_cmake_set PICO_PLATFORM=rp2350

#ifndef _BOARDS_SOLDERPARTY_RP2XXX_STAMP_CARRIER_XL_H
#define _BOARDS_SOLDERPARTY_RP2XXX_STAMP_CARRIER_XL_H

// For board detection
#define SOLDERPARTY_RP2350_STAMP_XL

// --- RP2350 VARIANT ---
#define PICO_RP2350A 0

// --- UART ---
#define PICO_DEFAULT_UART 0
#define PICO_DEFAULT_UART_TX_PIN 0
#define PICO_DEFAULT_UART_RX_PIN 1

// --- I2C ---
#define PICO_DEFAULT_I2C 0
#define PICO_DEFAULT_I2C_SDA_PIN 4
#define PICO_DEFAULT_I2C_SCL_PIN 5

// --- SPI ---
#define PICO_DEFAULT_SPI 0
#define PICO_DEFAULT_SPI_SCK_PIN 18
#define PICO_DEFAULT_SPI_TX_PIN 19
#define PICO_DEFAULT_SPI_RX_PIN 16
#define PICO_DEFAULT_SPI_CSN_PIN 17

// --- FLASH ---
#define PICO_BOOT_STAGE2_CHOOSE_W25Q080 1
#define PICO_FLASH_SPI_CLKDIV 2

// pico_cmake_set_default PICO_FLASH_SIZE_BYTES = (16 * 1024 * 1024)
#define PICO_FLASH_SIZE_BYTES (16 * 1024 * 1024)

#define PICO_RP2350_A2_SUPPORTED 1

// --- PINS ---
#define SFE_RP2350_XIP_CSI_PIN 8 // PSRAM

#define PIN_LCD_CS 17
#define PIN_LCD_DC 12
#define PIN_LCD_BL 20
#define PIN_LCD_CS PICO_DEFAULT_SPI_CSN_PIN

#define SPI_LCD spi0

#endif
