/*
 * mpu.c
 *
 *  Created on: 2019年3月26日
 *      Author: Verdvana
 */

#include "../inc/mpu.h"

//gcc标准头文件
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include "socal/hps.h"		//外设地址信息定义

//hps 厂家提供的底层定义头文件
#define soc_cv_av	//定义使用soc_cv_av硬件平台

#include "hwlib.h"			//常量定义
#include "socal/socal.h"	//底层操作函数，如位、字节、半字、字的读写
#include "socal/hps.h"		//外设地址信息定义

#include "../hps_0.h"

extern volatile unsigned long *led_pio_virtual_base;
extern volatile unsigned long *button_pio_virtual_base ;

int fpga_init(long int *virtual_base) {
	int fd;
	void *periph_virtual_base;	//外设空间虚拟地址

	//打开MPU
	if ((fd = open("/dev/mem", ( O_RDWR | O_SYNC))) == -1) {
		printf("ERROR: could not open \"/dev/mem\"...\n");
		return (1);
	}

	//将外设地址段映射到用户空间
	periph_virtual_base = mmap( NULL, HW_REGS_SPAN, ( PROT_READ | PROT_WRITE),
			MAP_SHARED, fd, HW_REGS_BASE);
	if (periph_virtual_base == MAP_FAILED) {
		printf("ERROR: mmap() failed...\n");
		close(fd);
		return (1);
	}

	//映射得到led_pio外设虚拟地址
	led_pio_virtual_base = periph_virtual_base
			+ ((unsigned long) ( ALT_LWFPGASLVS_OFST + LED_PIO_BASE)
					& (unsigned long) ( HW_REGS_MASK));
	//映射得到button_pio外设虚拟地址
	button_pio_virtual_base = periph_virtual_base
			+ ((unsigned long) ( ALT_LWFPGASLVS_OFST + BUTTON_PIO_BASE)
					& (unsigned long) ( HW_REGS_MASK));
	*virtual_base = periph_virtual_base;	//将外设虚拟地址保存，用以释放时候使用
	return fd;
}
