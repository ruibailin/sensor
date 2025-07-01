
/*------------------------------------
 * reg.h
 * Create:  2025-06-28
 * Author:  Steve Rui
 *------------------------------------
 * Record:
 *
 *
 *
 *
 *------------------------------------
 */


#include "1imp.h"
#ifndef SOC_SPI_REG_H_
#define SOC_SPI_REG_H_
/*================================================================*/
extern void reg_init_spi_bus(void);
extern bool reg_write_spi_device(uint8_t address, uint8_t *tx_data, uint8_t tx_length);
extern bool reg_read_spi_device(uint8_t address, uint8_t *rx_data, uint8_t *rx_length);
extern void reg_deinit_spi_bus(uint8_t address, uint8_t *tx_data, uint8_t tx_length);
/*================================================================*/
#endif
/* end of reg.h */
