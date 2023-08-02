#include "24C02Dev.h"
#include <stdio.h>

HAL_StatusTypeDef AT24C02_write(uint16_t address, uint8_t data)
{
	printf("add:%d data:%d\r\n", address, data);
    HAL_StatusTypeDef status;
    // status =  HAL_I2C_Mem_Write(   &I2C_AT24C02, 
    //                                 ADDR_AT24C02_Write, 
    //                                 address, 
    //                                 I2C_MEMADD_SIZE_8BIT,
    //                                 &data,
    //                                 1, 
    //                                 1000);

    // status = HAL_I2C_Mem_Write_IT(  &I2C_AT24C02,
    //                                 ADDR_AT24C02_Write, 
    //                                 address, 
    //                                 I2C_MEMADD_SIZE_8BIT,
    //                                 &data,
    //                                 1);

    status = HAL_I2C_Mem_Write_DMA(  &I2C_AT24C02,
                                    ADDR_AT24C02_Write, 
                                    address, 
                                    I2C_MEMADD_SIZE_8BIT,
                                    &data,
                                    1);
    //增加间隔防止 未准备好
    HAL_Delay(10);
    return  status;
}


HAL_StatusTypeDef AT24C02_write_Array(uint16_t address, uint8_t* data, uint16_t dataLen)
{
    HAL_StatusTypeDef status = HAL_OK;
    for(int i = 0; i < dataLen; i++){
        AT24C02_write(address + i, data[i]) ;
    }

    return status;
}




