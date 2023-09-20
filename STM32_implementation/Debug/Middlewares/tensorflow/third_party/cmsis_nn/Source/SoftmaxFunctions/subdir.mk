################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_nn_softmax_common_s8.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s16.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8_s16.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_u8.c 

OBJS += \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_nn_softmax_common_s8.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s16.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8_s16.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_u8.o 

C_DEPS += \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_nn_softmax_common_s8.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s16.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8_s16.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_u8.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/%.o Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/%.su Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/%.cyclo: ../Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/%.c Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI/App -I../X-CUBE-AI -I../X-CUBE-AI/Target -I../Middlewares/ST/AI/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-tensorflow-2f-third_party-2f-cmsis_nn-2f-Source-2f-SoftmaxFunctions

clean-Middlewares-2f-tensorflow-2f-third_party-2f-cmsis_nn-2f-Source-2f-SoftmaxFunctions:
	-$(RM) ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_nn_softmax_common_s8.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_nn_softmax_common_s8.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_nn_softmax_common_s8.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_nn_softmax_common_s8.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s16.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s16.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s16.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s16.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8_s16.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8_s16.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8_s16.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8_s16.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_u8.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_u8.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_u8.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_u8.su

.PHONY: clean-Middlewares-2f-tensorflow-2f-third_party-2f-cmsis_nn-2f-Source-2f-SoftmaxFunctions

