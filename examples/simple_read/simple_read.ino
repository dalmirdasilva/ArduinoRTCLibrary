#include <Wire.h>
#include <WiredDevice.h>
#include <RegisterBasedWiredDevice.h>
#include <RealTimeClock.h>
#include <RealTimeClockDS1307.h>

RealTimeClockDS1307 rtc;
unsigned char d;

void setup() {
  Serial.begin(9600);
  Serial.println("initialized");
}

void loop() {
  d = rtc.getYear();
  Serial.print("year: ");
  Serial.println(d);
  d = rtc.getMonth();
  Serial.printoi("month: ");
  Serial.println(d);
  d = rtc.getDay();
  Serial.print("day: ");
  Serial.println(d);
  d = rtc.getHour();
  Serial.print("hour: ");
  Serial.println(d);
  d = rtc.getMinutes();
  Serial.print("minutes: ");
  Serial.println(d);
  d = rtc.getSeconds();
  Serial.print("seconds: ");
  Serial.println(d);
  delay(500);
}