#ifndef __24C02DEV_H
#define __24C02DEV_H

#include "stm32h7xx_hal.h"
#include "i2c.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define I2C_AT24C02        hi2c1
#define ADDR_AT24C02_Write 0xA0
#define ADDR_AT24C02_Read  0xA1

HAL_StatusTypeDef AT24C02_write(uint16_t address, uint8_t data);
HAL_StatusTypeDef AT24C02_write_Array(uint16_t address, uint8_t* data, uint16_t dataLen);
#endif
