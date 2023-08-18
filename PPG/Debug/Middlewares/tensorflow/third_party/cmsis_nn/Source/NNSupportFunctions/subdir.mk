################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_kernel_s16.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.c \
../Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.c 

OBJS += \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_kernel_s16.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.o \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.o 

C_DEPS += \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_kernel_s16.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.d \
./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/%.o Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/%.su Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/%.cyclo: ../Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/%.c Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI/App -I../X-CUBE-AI -I../X-CUBE-AI/Target -I../Middlewares/ST/AI/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-tensorflow-2f-third_party-2f-cmsis_nn-2f-Source-2f-NNSupportFunctions

clean-Middlewares-2f-tensorflow-2f-third_party-2f-cmsis_nn-2f-Source-2f-NNSupportFunctions:
	-$(RM) ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_kernel_s16.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_kernel_s16.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_kernel_s16.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_kernel_s16.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.su ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.cyclo ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.d ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.o ./Middlewares/tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.su

.PHONY: clean-Middlewares-2f-tensorflow-2f-third_party-2f-cmsis_nn-2f-Source-2f-NNSupportFunctions

