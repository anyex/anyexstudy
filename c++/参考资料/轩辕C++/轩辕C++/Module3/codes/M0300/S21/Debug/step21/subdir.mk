################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../step21/Circle.cpp \
../step21/Rectangle.cpp 

OBJS += \
./step21/Circle.o \
./step21/Rectangle.o 

CPP_DEPS += \
./step21/Circle.d \
./step21/Rectangle.d 


# Each subdirectory must supply rules for building sources it contributes
step21/%.o: ../step21/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/kwarph/Training/Module02/context/cdt/M0300S1/step21" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


