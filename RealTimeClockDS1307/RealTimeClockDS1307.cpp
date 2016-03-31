#include "RealTimeClockDS1307.h"

RealTimeClockDS1307::RealTimeClockDS1307()
        : RegisterBasedWiredDevice(DS1307_ADDRESS) {
}

unsigned char RealTimeClockDS1307::getSeconds() {
    SecondsBits bits = {0};
    bits.value = readRegister(SECONDS_REGISTER);
    return 10 * bits.TEN_SECONDS + bits.SECONDS;
}

unsigned char RealTimeClockDS1307::getMinutes() {
    MinutesBits bits = {0};
    bits.value = readRegister(MINUTES_REGISTER);
    return 10 * bits.TEN_MINUTES + bits.MINUTES;
}

unsigned char RealTimeClockDS1307::getHour() {
    unsigned char modeMask = 0x01;
    HourBits bits = {0};
    bits.value = readRegister(HOURS_REGISTER);
    if (bits.MODE_12_24) {
        modeMask = 0x02;
    }
    return 10 * (bits.TEM_HOURS & modeMask) + bits.HOURS;
}

unsigned char RealTimeClockDS1307::getDay() {
    DayBits bits = {0};
    bits.value = readRegister(DATE_REGISTER);
    return bits.DAY;
}

unsigned char RealTimeClockDS1307::getDate() {
    DateBits bits = {0};
    bits.value = readRegister(DATE_REGISTER);
    return 10 * bits.TEN_DATE + bits.DATE;
}

unsigned char RealTimeClockDS1307::getMonth() {
    MonthBits bits = {0};
    bits.value = readRegister(MONTH_REGISTER);
    return 10 * bits.TEN_MONTH + bits.MONTH;
}

unsigned char RealTimeClockDS1307::getYear() {
    YearBits bits = {0};
    bits.value = readRegister(YEAR_REGISTER);
    return 10 * bits.TEN_YEAR + bits.YEAR;
}
