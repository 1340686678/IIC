# IIC
H750
参考  
 **https://www.cnblogs.com/jiek/p/15501199.html#:~:text=STM32CubeMX-%E7%A1%AC%E4%BB%B6IIC%E8%AF%BB%E5%8F%96AT24C02%EF%BC%88%E9%98%BB%E5%A1%9E%E3%80%81%E4%B8%AD%E6%96%AD%E3%80%81DMA%E4%B8%89%E7%A7%8D%E6%96%B9%E5%BC%8F%EF%BC%89,%E6%96%87%E7%AB%A0%E7%9B%AE%E5%BD%95%20STM32CubeMX-%E7%A1%AC%E4%BB%B6IIC%E8%AF%BB%E5%8F%96AT24C02%EF%BC%88%E9%98%BB%E5%A1%9E%E3%80%81%E4%B8%AD%E6%96%AD%E3%80%81DMA%E4%B8%89%E7%A7%8D%E6%96%B9%E5%BC%8F%EF%BC%89%E4%B8%80%E3%80%81%E5%88%9D%E5%A7%8B%E5%87%86%E5%A4%871.%E7%A1%AC%E4%BB%B6%E5%B9%B3%E5%8F%B02.%E8%BD%AF%E4%BB%B6%E5%B9%B3%E5%8F%B0**
# demo1
使用I2C1与24C02通讯  
**IIC**  
参考：
https://blog.csdn.net/qq_35697978/article/details/116375880?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522169068449316800225544885%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=169068449316800225544885&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-116375880-null-null.142^v91^control_2,239^v12^control&utm_term=STM32cube%2024c02&spm=1018.2226.3001.4187  
**24C02参数**  
总容量2K->char*32

# demo1_1
在HAL库的基础上继续封装  

# demo1_2
AT24C02通讯的读写都进行封装

# demo2
使用I2C1 + 中断 与24C02通讯 

# demo3
使用I2C1 + DMA 与24C02通讯
**注意**
使用DMA时，需要开启中断，不然发送完之后会一直占着总线。 