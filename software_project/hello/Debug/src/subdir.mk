################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/button.c \
../src/led.c \
../src/mpu.c 

OBJS += \
./src/button.o \
./src/led.o \
./src/mpu.o 

C_DEPS += \
./src/button.d \
./src/led.d \
./src/mpu.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler 4 [arm-linux-gnueabihf]'
	arm-linux-gnueabihf-gcc -I"D:\intelFPGA\18.1\embedded\ip\altera\hps\altera_hps\hwlib\include" -I"D:\intelFPGA\18.1\embedded\ip\altera\hps\altera_hps\hwlib\include\soc_cv_av" -I"E:\DE1-SoC\FPGA_HPS\DE1_SoC_GHRD\software_project\hello\inc" -O0 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


