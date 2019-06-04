#ifndef _GP2Y0E03_H_
#define _GP2Y0E03_H_

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>    
 
#define GP2Y0E          0x40//default
#define SHIFT_BYTE      0x02 //64 cm shift = 2 128 cm shift = 1
#define SHIFT_ADDR      0x35
#define DISTANCE_ADDR1  0x5E
#define DISTANCE_ADDR2  0x5F
#define RIGHT_EDGE_ADDR 0xF8 // C
#define LEFT_EDGE_ADDR  0xF9 // A
#define PEAK_EDGE_ADDR  0xFA // B     

    
void DS_init(char sladress);    
unsigned char DS_get_data(char sladress);    
void Ds_change( uint8_t new_address);
void DS_range(char adress,char distance);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif // _RC522_H_