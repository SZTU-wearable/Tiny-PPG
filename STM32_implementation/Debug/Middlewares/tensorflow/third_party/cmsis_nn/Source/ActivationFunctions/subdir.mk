################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu6_s8.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q15.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q7.c 

OBJS += \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu6_s8.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q15.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q7.o 

C_DEPS += \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu6_s8.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q15.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q7.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/%.o Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/%.su Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/%.cyclo: ../Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/%.c Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI/App -I../X-CUBE-AI -I../X-CUBE-AI/Target -I../Middlewares/ST/AI/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-tensorflow-2f-third_party-2f-cmsis_nn-2f-Source-2f-ActivationFunctions

clean-Middlewares-2f-tensorflow-2f-third_party-2f-cmsis_nn-2f-Source-2f-ActivationFunctions:
	-$(RM) ./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu6_s8.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu6_s8.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu6_s8.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu6_s8.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q15.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q15.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q15.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q15.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q7.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q7.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q7.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q7.su

.PHONY: clean-Middlewares-2f-tensorflow-2f-third_party-2f-cmsis_nn-2f-Source-2f-ActivationFunctions

