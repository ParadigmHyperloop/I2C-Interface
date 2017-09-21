#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include "i2cfunc.h"

#define MODE1              0x00
#define MODE2              0x01
#define SUBADR1            0x02
#define SUBADR2            0x03
#define SUBADR3            0x04
#define PRESCALE           0xFE
#define LED0_ON_L          0x06
#define LED0_ON_H          0x07
#define LED0_OFF_L         0x08
#define LED0_OFF_H         0x09
#define ALL_LED_ON_L       0xFA
#define ALL_LED_ON_H       0xFB
#define ALL_LED_OFF_L      0xFC
#define ALL_LED_OFF_H      0xFD

#define RESTART            0x80
#define SLEEP              0x10
#define ALLCALL            0x01
#define INVRT              0x10
#define OUTDRV             0x04

#ifndef I2CBUS
#define I2CBUS 1
#endif

#ifndef BASEADDRESS
#define BASEADDRESS 0x40
#endif



int main(int argc, char *argv[]) {
    int handle;
    int value = 0x0;
    int channel = 0;
    if (argc < 2) {
        printf("Usage: ssr <channel> <value 0-4096>");
        exit(1);
    }

    channel = atoi(argv[1]);
    value = atoi(argv[2]);

    int addr;
    addr = BASEADDRESS + (channel > 15 ? 1 : 0);
    handle = i2c_open(I2CBUS, addr);
    channel = channel % 16; 
    
   // write_reg(handle, addr, 0x01, 0x04);
   // write_reg(handle, addr, 0x00, 0x01);
    int oldmode = 0;

   // read_reg(handle, addr, MODE1, (unsigned char*)&oldmode, 1);

   // write_reg(handle, addr, MODE1, (oldmode & 0x7F) | 0x10);
   // write_reg(handle, addr, PRESCALE, 0x04);ui
  //  write_reg(handle, addr, MODE1, oldmode | 0x80);

   // usleep(500);

    write_reg(handle, addr, 0x06 + 4 * channel, 0);
    write_reg(handle, addr, 0x07 + 4 * channel, 0);
    write_reg(handle, addr, 0x08 + 4 * channel, 0xFF & value);
    write_reg(handle, addr, 0x09 + 4 * channel, (value >> 8) & 0xFF);

   i2c_close(handle);
}
