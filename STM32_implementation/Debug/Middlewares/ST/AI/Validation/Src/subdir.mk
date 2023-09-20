################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/AI/Validation/Src/aiPbIO.c \
../Middlewares/ST/AI/Validation/Src/aiPbMemRWServices.c \
../Middlewares/ST/AI/Validation/Src/aiPbMgr.c \
../Middlewares/ST/AI/Validation/Src/aiValidation.c \
../Middlewares/ST/AI/Validation/Src/pb_common.c \
../Middlewares/ST/AI/Validation/Src/pb_decode.c \
../Middlewares/ST/AI/Validation/Src/pb_encode.c \
../Middlewares/ST/AI/Validation/Src/stm32msg.pb.c 

OBJS += \
./Middlewares/ST/AI/Validation/Src/aiPbIO.o \
./Middlewares/ST/AI/Validation/Src/aiPbMemRWServices.o \
./Middlewares/ST/AI/Validation/Src/aiPbMgr.o \
./Middlewares/ST/AI/Validation/Src/aiValidation.o \
./Middlewares/ST/AI/Validation/Src/pb_common.o \
./Middlewares/ST/AI/Validation/Src/pb_decode.o \
./Middlewares/ST/AI/Validation/Src/pb_encode.o \
./Middlewares/ST/AI/Validation/Src/stm32msg.pb.o 

C_DEPS += \
./Middlewares/ST/AI/Validation/Src/aiPbIO.d \
./Middlewares/ST/AI/Validation/Src/aiPbMemRWServices.d \
./Middlewares/ST/AI/Validation/Src/aiPbMgr.d \
./Middlewares/ST/AI/Validation/Src/aiValidation.d \
./Middlewares/ST/AI/Validation/Src/pb_common.d \
./Middlewares/ST/AI/Validation/Src/pb_decode.d \
./Middlewares/ST/AI/Validation/Src/pb_encode.d \
./Middlewares/ST/AI/Validation/Src/stm32msg.pb.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/AI/Validation/Src/%.o Middlewares/ST/AI/Validation/Src/%.su Middlewares/ST/AI/Validation/Src/%.cyclo: ../Middlewares/ST/AI/Validation/Src/%.c Middlewares/ST/AI/Validation/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI/App -I../X-CUBE-AI -I../X-CUBE-AI/Target -I../Middlewares/ST/AI/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-AI-2f-Validation-2f-Src

clean-Middlewares-2f-ST-2f-AI-2f-Validation-2f-Src:
	-$(RM) ./Middlewares/ST/AI/Validation/Src/aiPbIO.cyclo ./Middlewares/ST/AI/Validation/Src/aiPbIO.d ./Middlewares/ST/AI/Validation/Src/aiPbIO.o ./Middlewares/ST/AI/Validation/Src/aiPbIO.su ./Middlewares/ST/AI/Validation/Src/aiPbMemRWServices.cyclo ./Middlewares/ST/AI/Validation/Src/aiPbMemRWServices.d ./Middlewares/ST/AI/Validation/Src/aiPbMemRWServices.o ./Middlewares/ST/AI/Validation/Src/aiPbMemRWServices.su ./Middlewares/ST/AI/Validation/Src/aiPbMgr.cyclo ./Middlewares/ST/AI/Validation/Src/aiPbMgr.d ./Middlewares/ST/AI/Validation/Src/aiPbMgr.o ./Middlewares/ST/AI/Validation/Src/aiPbMgr.su ./Middlewares/ST/AI/Validation/Src/aiValidation.cyclo ./Middlewares/ST/AI/Validation/Src/aiValidation.d ./Middlewares/ST/AI/Validation/Src/aiValidation.o ./Middlewares/ST/AI/Validation/Src/aiValidation.su ./Middlewares/ST/AI/Validation/Src/pb_common.cyclo ./Middlewares/ST/AI/Validation/Src/pb_common.d ./Middlewares/ST/AI/Validation/Src/pb_common.o ./Middlewares/ST/AI/Validation/Src/pb_common.su ./Middlewares/ST/AI/Validation/Src/pb_decode.cyclo ./Middlewares/ST/AI/Validation/Src/pb_decode.d ./Middlewares/ST/AI/Validation/Src/pb_decode.o ./Middlewares/ST/AI/Validation/Src/pb_decode.su ./Middlewares/ST/AI/Validation/Src/pb_encode.cyclo ./Middlewares/ST/AI/Validation/Src/pb_encode.d ./Middlewares/ST/AI/Validation/Src/pb_encode.o ./Middlewares/ST/AI/Validation/Src/pb_encode.su ./Middlewares/ST/AI/Validation/Src/stm32msg.pb.cyclo ./Middlewares/ST/AI/Validation/Src/stm32msg.pb.d ./Middlewares/ST/AI/Validation/Src/stm32msg.pb.o ./Middlewares/ST/AI/Validation/Src/stm32msg.pb.su

.PHONY: clean-Middlewares-2f-ST-2f-AI-2f-Validation-2f-Src

