################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/activation_function.cpp \
../src/back_propagation.cpp \
../src/fbool.cpp \
../src/fset.cpp \
../src/hebb.cpp \
../src/main.cpp \
../src/perceptron.cpp 

OBJS += \
./src/activation_function.o \
./src/back_propagation.o \
./src/fbool.o \
./src/fset.o \
./src/hebb.o \
./src/main.o \
./src/perceptron.o 

CPP_DEPS += \
./src/activation_function.d \
./src/back_propagation.d \
./src/fbool.d \
./src/fset.d \
./src/hebb.d \
./src/main.d \
./src/perceptron.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


