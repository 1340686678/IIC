#ifndef __24C02DEV_H
#define __24C02DEV_H

#include "stm32h7xx_hal.h"
#include "i2c.h"

#define I2C_AT24C02        hi2c1
#define ADDR_AT24C02_WRITE 0xA0
#define ADDR_AT24C02_READ  0xA1

HAL_StatusTypeDef AT24C02_Ready(void);

HAL_StatusTypeDef AT24C02_Write(uint16_t address, uint8_t data);
HAL_StatusTypeDef AT24C02_Write_Array(uint16_t address, uint8_t* data, uint16_t dataLen);

HAL_StatusTypeDef AT24C02_Read(uint16_t address, uint8_t *data);
HAL_StatusTypeDef AT24C02_Read_Array(uint16_t address,  uint8_t* data, uint16_t dataLen);


HAL_StatusTypeDef AT24C02_Inspect(void);

#endif
