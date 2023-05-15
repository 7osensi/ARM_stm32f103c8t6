################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/Delay_Program.c \
../Drivers/Src/RCC_prog.c \
../Drivers/Src/Stm32F103_AFIO.c \
../Drivers/Src/Stm32F103_EXTI.c \
../Drivers/Src/Stm32F103_GPIO.c \
../Drivers/Src/Stm32F103_NVIC.c 

OBJS += \
./Drivers/Src/Delay_Program.o \
./Drivers/Src/RCC_prog.o \
./Drivers/Src/Stm32F103_AFIO.o \
./Drivers/Src/Stm32F103_EXTI.o \
./Drivers/Src/Stm32F103_GPIO.o \
./Drivers/Src/Stm32F103_NVIC.o 

C_DEPS += \
./Drivers/Src/Delay_Program.d \
./Drivers/Src/RCC_prog.d \
./Drivers/Src/Stm32F103_AFIO.d \
./Drivers/Src/Stm32F103_EXTI.d \
./Drivers/Src/Stm32F103_GPIO.d \
./Drivers/Src/Stm32F103_NVIC.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su Drivers/Src/%.cyclo: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/0PandaKit/stm32F103c8t6-main/STM32F103_DRIVERS/BluePill_STM32F103_Drivers/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/Delay_Program.cyclo ./Drivers/Src/Delay_Program.d ./Drivers/Src/Delay_Program.o ./Drivers/Src/Delay_Program.su ./Drivers/Src/RCC_prog.cyclo ./Drivers/Src/RCC_prog.d ./Drivers/Src/RCC_prog.o ./Drivers/Src/RCC_prog.su ./Drivers/Src/Stm32F103_AFIO.cyclo ./Drivers/Src/Stm32F103_AFIO.d ./Drivers/Src/Stm32F103_AFIO.o ./Drivers/Src/Stm32F103_AFIO.su ./Drivers/Src/Stm32F103_EXTI.cyclo ./Drivers/Src/Stm32F103_EXTI.d ./Drivers/Src/Stm32F103_EXTI.o ./Drivers/Src/Stm32F103_EXTI.su ./Drivers/Src/Stm32F103_GPIO.cyclo ./Drivers/Src/Stm32F103_GPIO.d ./Drivers/Src/Stm32F103_GPIO.o ./Drivers/Src/Stm32F103_GPIO.su ./Drivers/Src/Stm32F103_NVIC.cyclo ./Drivers/Src/Stm32F103_NVIC.d ./Drivers/Src/Stm32F103_NVIC.o ./Drivers/Src/Stm32F103_NVIC.su

.PHONY: clean-Drivers-2f-Src

