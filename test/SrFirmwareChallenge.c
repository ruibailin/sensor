#if 0
#define NUM_CHIP_SELECT_LINES 4

void (*device_inserted_removed_callback)(uint8_t port_num, bool device_inserted);
void (*data_read_callback)(uint8_t port_num, uint8_t *data);

void TIMER_ISR()
{
}

void I2C_ISR(bool success)
{
}

void SPI_ISR()
{
}

/* If you need a description of this function it's probably not gonna work out :)
 */
void main()
{
	//...
}

/* This function starts a SPI transfer.
 * It is NOT a blocking function, and will return immediately.
 * Once the SPI transfer is complete the system will call the SPI_ISR() function.
 * tx_data and rx_data arrays should be the same length.
 * The tx_data will be sent sent out on MOSI at the same time the rx_data is filled in from MISO.
 * There are 4 sensor "ports" sharing the same MISO, MOSI, and CLK lines, and each having their own chip_select line.
 *
 * Parameters:
 *   chip_select - Valid values are 0-NUM_CHIP_SELECT_LINES.  This selects which chip select line should be activated (driven low) during the SPI tranfer
 *   tx_data - data to be transmitted on MOSI
 *   rx_data - data read from MISO
 *   length - number of bytes of both the tx_data and rx_data
 */
void start_spi_transfer(uint8_t chip_select, uint8_t *tx_data, uint8_t *rx_data, uint8_t length)
{
	//Not to be implemented
}

/* This function starts an I2C transfer.
 * It is NOT a blocking function, and will return immediately.
 * Once the I2C transfer is complete the system will call the I2C_ISR() function.
 * The address will be sent, followed by the tx_data, then the rx_data.
 *
 * Parameters:
 *   address - Address of I2C device
 *   tx_data - data to be transmitted
 *   tx_length - number of bytes to transmit
 *   rx_data - data read from I2C bus (can be NULL if rx_length is 0)
 *   rx_length - number of bytes to read back from I2C device
 */
void start_i2c_transfer(uint8_t address, uint8_t *tx_data, uint8_t tx_length, uint8_t *rx_data, uint8_t rx_length)
{
	//Not to be implemented
}

/* These functions will setup either an I2C or SPI transaction to 
 * read data from the sensor.  The length of the data returned in buffer
 * is 16 bytes.
 * Parameters:
 *   buffer - the buffer where the 16 bytes of sensor data will be written
 *   chip_select - Valid values are 0-NUM_CHIP_SELECT_LINES.  The chip_select line of the port to be read.
 */
void start_MMC5603_data_read(uint8_t *buffer)
{
	//Not to be implemented
}
void start_MMC5983_data_read(uint8_t chip_select, uint8_t *buffer)
{
	//Not to be implemented
}
void start_LSM6DSM_data_read(uint8_t chip_select, uint8_t *buffer)
{
	//Not to be implemented
}

/* This function starts a fictitious interval timer.  Once this is called
 * the system will start calling "void TIMER_ISR()" once every 100ms
 */
void start_timer()
{
	//Not to be implemented
}
#endif
