################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/model/NetworkController.cpp \
../src/model/NetworkLayer.cpp \
../src/model/NetworkNode.cpp \
../src/model/Trainer.cpp \
../src/model/Util.cpp 

OBJS += \
./src/model/NetworkController.o \
./src/model/NetworkLayer.o \
./src/model/NetworkNode.o \
./src/model/Trainer.o \
./src/model/Util.o 

CPP_DEPS += \
./src/model/NetworkController.d \
./src/model/NetworkLayer.d \
./src/model/NetworkNode.d \
./src/model/Trainer.d \
./src/model/Util.d 


# Each subdirectory must supply rules for building sources it contributes
src/model/%.o: ../src/model/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


