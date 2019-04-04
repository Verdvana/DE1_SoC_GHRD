################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c 

OBJS += \
./main.o 

C_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler 4 [arm-linux-gnueabihf]'
	arm-linux-gnueabihf-gcc -I"D:\intelFPGA\18.1\embedded\ip\altera\hps\altera_hps\hwlib\include" -I"D:\intelFPGA\18.1\embedded\ip\altera\hps\altera_hps\hwlib\include\soc_cv_av" -I"E:\DE1-SoC\FPGA_HPS\DE1_SoC_GHRD\software_project\hello\inc" -O0 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


