################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../RealTimeClock/RealTimeClock.cpp 

OBJS += \
./RealTimeClock/RealTimeClock.o 

CPP_DEPS += \
./RealTimeClock/RealTimeClock.d 


# Each subdirectory must supply rules for building sources it contributes
RealTimeClock/%.o: ../RealTimeClock/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoRealTimeClock/RealTimeClock" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoRealTimeClock/RealTimeClockDS1307" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoCore" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoCore/variants/standard" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoDevice/RegisterBasedWiredDevice" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoDevice/WiredDevice" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoDevice/EepromBasedWiredDevice" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


