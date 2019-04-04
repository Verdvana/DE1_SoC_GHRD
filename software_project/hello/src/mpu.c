/*
 * mpu.c
 *
 *  Created on: 2019��3��26��
 *      Author: Verdvana
 */

#include "../inc/mpu.h"

//gcc��׼ͷ�ļ�
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include "socal/hps.h"		//�����ַ��Ϣ����

//hps �����ṩ�ĵײ㶨��ͷ�ļ�
#define soc_cv_av	//����ʹ��soc_cv_avӲ��ƽ̨

#include "hwlib.h"			//��������
#include "socal/socal.h"	//�ײ������������λ���ֽڡ����֡��ֵĶ�д
#include "socal/hps.h"		//�����ַ��Ϣ����

#include "../hps_0.h"

extern volatile unsigned long *led_pio_virtual_base;
extern volatile unsigned long *button_pio_virtual_base ;

int fpga_init(long int *virtual_base) {
	int fd;
	void *periph_virtual_base;	//����ռ������ַ

	//��MPU
	if ((fd = open("/dev/mem", ( O_RDWR | O_SYNC))) == -1) {
		printf("ERROR: could not open \"/dev/mem\"...\n");
		return (1);
	}

	//�������ַ��ӳ�䵽�û��ռ�
	periph_virtual_base = mmap( NULL, HW_REGS_SPAN, ( PROT_READ | PROT_WRITE),
			MAP_SHARED, fd, HW_REGS_BASE);
	if (periph_virtual_base == MAP_FAILED) {
		printf("ERROR: mmap() failed...\n");
		close(fd);
		return (1);
	}

	//ӳ��õ�led_pio���������ַ
	led_pio_virtual_base = periph_virtual_base
			+ ((unsigned long) ( ALT_LWFPGASLVS_OFST + LED_PIO_BASE)
					& (unsigned long) ( HW_REGS_MASK));
	//ӳ��õ�button_pio���������ַ
	button_pio_virtual_base = periph_virtual_base
			+ ((unsigned long) ( ALT_LWFPGASLVS_OFST + BUTTON_PIO_BASE)
					& (unsigned long) ( HW_REGS_MASK));
	*virtual_base = periph_virtual_base;	//�����������ַ���棬�����ͷ�ʱ��ʹ��
	return fd;
}
