#include <Arduino.h>
#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(int tempPin, int noOfReadings, bool centigrade) 
  : tempPin(tempPin), noOfReadings(noOfReadings), centigrade(centigrade)
{  
}

double TemperatureSensor::ReadTemperature()
{
  double temperatureMiliVolts = analogRead(tempPin) * 5 / 1023.0 * 1000;  //convert to V (1023 is 5V) and then to mV
  double temperature = (temperatureMiliVolts - 500) / 10;  //500 mV is an offset to make negative degrees possible, 10 mV is per degree C.

  if (!centigrade)
    temperature = temperature * 1.8 + 32;
  return temperature;
}

double TemperatureSensor::GetTemperature()
{
  double temperature = 0.0;
  //Get the average of several readings to increase accuracy.
  for (int i = 0; i < noOfReadings; i++)
    temperature += ReadTemperature();
  
  return temperature / noOfReadings;
}
