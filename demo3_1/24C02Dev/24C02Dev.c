#include "24C02Dev.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>


static uint8_t I2C_Buffer_Write[256];
ALIGN_32BYTES (uint8_t I2C_Buffer_Write[256]) __attribute__((section(".ARM.__at_0x30000000")));
static uint8_t I2C_Buffer_Read[256];
ALIGN_32BYTES (uint8_t I2C_Buffer_Read[256]) __attribute__((section(".ARM.__at_0x30000100")));

HAL_StatusTypeDef AT24C02_Ready(void)
{
    return HAL_I2C_IsDeviceReady(&I2C_AT24C02,
                                 ADDR_AT24C02_WRITE,
                                 5,
                                 100
    );
}


HAL_StatusTypeDef AT24C02_write(uint16_t address, uint8_t data)
{
    if(AT24C02_Ready() != HAL_OK)
        return HAL_ERROR;

		//printf("add:%d data:%d\r\n", address, data);
    HAL_StatusTypeDef status = HAL_OK;
    status = HAL_I2C_Mem_Write_DMA(  &I2C_AT24C02,
                                    ADDR_AT24C02_WRITE, 
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
    if(AT24C02_Ready() != HAL_OK)
        return HAL_ERROR;

    HAL_StatusTypeDef status = HAL_OK;
    for(int i = 0; i < dataLen; i++){
        AT24C02_write(address + i, data[i]) ;
    }

    return status;
}


HAL_StatusTypeDef AT24C02_Read(uint16_t address, uint8_t *data)
{
    if(AT24C02_Ready() != HAL_OK)
        return HAL_ERROR;
    
    HAL_StatusTypeDef status;
    // status =  HAL_I2C_Mem_Read( &hi2c1, 
    //                             ADDR_AT24C02_READ, 
    //                             address, 
    //                             I2C_MEMADD_SIZE_8BIT,
    //                             data,
    //                             1, 
    //                             100);

    status =  HAL_I2C_Mem_Read_DMA( &hi2c1, 
                                ADDR_AT24C02_READ, 
                                address, 
                                I2C_MEMADD_SIZE_8BIT,
                                data,
                                1);

    //增加间隔防止 未准备好
    HAL_Delay(10);
    return  status;
}

HAL_StatusTypeDef AT24C02_Read_Array(uint16_t address,  uint8_t* data, uint16_t dataLen)
{
    if(AT24C02_Ready() != HAL_OK)
        return HAL_ERROR;

    HAL_StatusTypeDef status = HAL_OK;

    for(int i = 0; i < dataLen; i++){
        status = AT24C02_Read(address + i, data + i) ;
    }

    return status;
}

HAL_StatusTypeDef AT24C02_Inspect (void)
{
    printf("\r\nAT24C02 Inspect DMA:\r\n");

    if(AT24C02_Ready() != HAL_OK)
    {
        printf("I2C Dev ERROR\r\n");
        return HAL_ERROR;
    }
    else{
        printf("I2C Dev OK\r\n");

    }

    uint16_t i;

    HAL_StatusTypeDef retStatus = HAL_OK;

    /* WriteBuffer Initialization */
    for(i=0; i<256; i++)
    {
        I2C_Buffer_Write[i] = i;    
    }

     /* write data to AT24C02 */
    if(AT24C02_write_Array(0, I2C_Buffer_Write, sizeof(I2C_Buffer_Write)) == HAL_OK){
        printf("Write OK\r\n");
    }
    else{
        retStatus = HAL_ERROR;
        printf("Write Failed\r\n");
        goto RET;
    }

    /* read data from EEPROM */
//    printf("\r\nReading from AT24C02:\r\n");
//    AT24C02_Read_Array(0, I2C_Buffer_Read, 256);

//    for(i=0; i<256; i++)
//    {
//        printf("0x%02X  ",I2C_Buffer_Read[i]);
//    }
//    printf("\r\n");
//    HAL_Delay(500);

    /* check data */
    if(memcmp(I2C_Buffer_Read,I2C_Buffer_Write,256) == 0 ) {
        printf("Read OK\r\n");
    }
    else {
        printf("Read Failed\r\n");
        retStatus = HAL_ERROR;
        goto RET;
    }

    /*clear write data*/
    for(i=0; i<256; i++)
    {
        I2C_Buffer_Write[i]=0x00;    
    }

    AT24C02_write_Array(0, I2C_Buffer_Write, sizeof(I2C_Buffer_Write));

    /*return status*/
RET:
    if(retStatus == HAL_OK)
        printf("AT24C02 Work OK\r\n");
    else
        printf("AT24C02 Work ERROR\r\n");

    return retStatus;
}










