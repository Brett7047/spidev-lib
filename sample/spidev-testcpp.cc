#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <spidev_lib++.h>
#include <iostream>
#include <bitset>


spi_config_t spi_config;
uint8_t a = 5;
uint8_t b = 21;
uint8_t c = 123;
uint32_t d = (c<<16 | b<<8 | a);
uint8_t buff[3];
uint8_t rx_buffer[sizeof(buff)];

int  main( void)
{

  SPI *mySPI = NULL;

  spi_config.mode=0;
  spi_config.speed=1000000;
  spi_config.delay=0;
  spi_config.bits_per_word=8;

  mySPI=new SPI("/dev/spidev0.1",&spi_config);

  if (mySPI->begin())
  {
     //memset(tx_buffer,0,32);
     memset(rx_buffer,0,3);
     memset(buff,0,3);
     buff[0] = a;
     buff[1] = b;
     buff[2] = c;

    //sprintf((char*)tx_buffer,"51235");
    // printf("sending %s, to spidev2.0 in full duplex \n ",(char*)tx_buffer); 
     for (auto elem : buff)
       std::cout << "elem is: " << std::bitset<8*sizeof(elem)>(elem) << std::endl;

    mySPI->xfer(buff,sizeof(buff),rx_buffer);
    printf("tx_buffer=%s\n",(char *)buff);
    printf("rx_buffer=%s\n",(char *)rx_buffer);

    delete mySPI; 
  }
 return 1;
}
