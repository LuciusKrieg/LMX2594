################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/LMX2594/Src/lmx2594_com_control.c \
../Drivers/LMX2594/Src/lmx2594_parameters.c \
../Drivers/LMX2594/Src/lmx2594_parameters_control.c \
../Drivers/LMX2594/Src/lmx2594_registers_control.c \
../Drivers/LMX2594/Src/lmx2594_synthesizer_control.c \
../Drivers/LMX2594/Src/lmx2594_synthesizer_init.c 

OBJS += \
./Drivers/LMX2594/Src/lmx2594_com_control.o \
./Drivers/LMX2594/Src/lmx2594_parameters.o \
./Drivers/LMX2594/Src/lmx2594_parameters_control.o \
./Drivers/LMX2594/Src/lmx2594_registers_control.o \
./Drivers/LMX2594/Src/lmx2594_synthesizer_control.o \
./Drivers/LMX2594/Src/lmx2594_synthesizer_init.o 

C_DEPS += \
./Drivers/LMX2594/Src/lmx2594_com_control.d \
./Drivers/LMX2594/Src/lmx2594_parameters.d \
./Drivers/LMX2594/Src/lmx2594_parameters_control.d \
./Drivers/LMX2594/Src/lmx2594_registers_control.d \
./Drivers/LMX2594/Src/lmx2594_synthesizer_control.d \
./Drivers/LMX2594/Src/lmx2594_synthesizer_init.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/LMX2594/Src/%.o Drivers/LMX2594/Src/%.su: ../Drivers/LMX2594/Src/%.c Drivers/LMX2594/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/LMX2594/Inc -I../Drivers/LMX2594_In_Pair/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-LMX2594-2f-Src

clean-Drivers-2f-LMX2594-2f-Src:
	-$(RM) ./Drivers/LMX2594/Src/lmx2594_com_control.d ./Drivers/LMX2594/Src/lmx2594_com_control.o ./Drivers/LMX2594/Src/lmx2594_com_control.su ./Drivers/LMX2594/Src/lmx2594_parameters.d ./Drivers/LMX2594/Src/lmx2594_parameters.o ./Drivers/LMX2594/Src/lmx2594_parameters.su ./Drivers/LMX2594/Src/lmx2594_parameters_control.d ./Drivers/LMX2594/Src/lmx2594_parameters_control.o ./Drivers/LMX2594/Src/lmx2594_parameters_control.su ./Drivers/LMX2594/Src/lmx2594_registers_control.d ./Drivers/LMX2594/Src/lmx2594_registers_control.o ./Drivers/LMX2594/Src/lmx2594_registers_control.su ./Drivers/LMX2594/Src/lmx2594_synthesizer_control.d ./Drivers/LMX2594/Src/lmx2594_synthesizer_control.o ./Drivers/LMX2594/Src/lmx2594_synthesizer_control.su ./Drivers/LMX2594/Src/lmx2594_synthesizer_init.d ./Drivers/LMX2594/Src/lmx2594_synthesizer_init.o ./Drivers/LMX2594/Src/lmx2594_synthesizer_init.su

.PHONY: clean-Drivers-2f-LMX2594-2f-Src

