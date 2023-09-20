################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance.c \
../Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance_RELOC.c \
../Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance_TFLM.c 

OBJS += \
./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance.o \
./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance_RELOC.o \
./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance_TFLM.o 

C_DEPS += \
./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance.d \
./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance_RELOC.d \
./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance_TFLM.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/AI/SystemPerformance/Src/%.o Middlewares/ST/AI/SystemPerformance/Src/%.su Middlewares/ST/AI/SystemPerformance/Src/%.cyclo: ../Middlewares/ST/AI/SystemPerformance/Src/%.c Middlewares/ST/AI/SystemPerformance/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI/App -I../X-CUBE-AI -I../X-CUBE-AI/Target -I../Middlewares/ST/AI/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-AI-2f-SystemPerformance-2f-Src

clean-Middlewares-2f-ST-2f-AI-2f-SystemPerformance-2f-Src:
	-$(RM) ./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance.cyclo ./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance.d ./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance.o ./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance.su ./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance_RELOC.cyclo ./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance_RELOC.d ./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance_RELOC.o ./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance_RELOC.su ./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance_TFLM.cyclo ./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance_TFLM.d ./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance_TFLM.o ./Middlewares/ST/AI/SystemPerformance/Src/aiSystemPerformance_TFLM.su

.PHONY: clean-Middlewares-2f-ST-2f-AI-2f-SystemPerformance-2f-Src

