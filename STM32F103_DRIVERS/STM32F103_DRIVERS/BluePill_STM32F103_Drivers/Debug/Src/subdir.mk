################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/003LED_Toggle_BTN_INT.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/003LED_Toggle_BTN_INT.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/003LED_Toggle_BTN_INT.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/0PandaKit/stm32F103c8t6-main/STM32F103_DRIVERS/BluePill_STM32F103_Drivers/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/003LED_Toggle_BTN_INT.cyclo ./Src/003LED_Toggle_BTN_INT.d ./Src/003LED_Toggle_BTN_INT.o ./Src/003LED_Toggle_BTN_INT.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

