/*
 * led.c
 *
 *  Created on: 2019Äê3ÔÂ26ÈÕ
 *      Author: Verdvana
 */

#include <stddef.h>
#include <fcntl.h>
#include <sys/mman.h>

#include "../inc/led.h"

//#include "../inc/mpu.h"

extern volatile unsigned long *led_pio_virtual_base;


void LED(u_int16_t x){

	*(led_pio_virtual_base + 0) = x; //
}

void LED_OFF(viod){

	*(led_pio_virtual_base + 0) = 0; //
}
