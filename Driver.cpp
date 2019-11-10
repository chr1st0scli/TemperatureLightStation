#include <Arduino.h>
#include "Driver.h"

Driver::Driver() : 
  lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN), 
  tmprtSensor(TEMPERATURE_PIN)
{
  prevTemperature = 0;
  prevDarkness = 0;
  prevDarknessThreshold = 0;
}

void Driver::Initialize()
{
  pinMode(RELAY_PIN, OUTPUT);
  lcd.begin(16, 2);
}

void Driver::PerformOperation()
{
  bool updateLcd = false;
  int darkness = round(analogRead(LIGHT_PIN) / 1023.0 * 100);
  int darknessThreshold = round(analogRead(POTENTIO_PIN) / 1023.0 * 100);
  double temperature = tmprtSensor.GetTemperature();
  
  if (fabs(temperature - prevTemperature) >= 1)
  {
    prevTemperature = temperature;
    updateLcd = true;
  }
  
  if (fabs(darkness - prevDarkness) >= 1) //50
  {
    prevDarkness = darkness;
    updateLcd = true;
  }

  if (fabs(darknessThreshold - prevDarknessThreshold) >= 1)
  {
    prevDarknessThreshold = darknessThreshold;
    updateLcd = true;
  }

  if (updateLcd)
    PrintToLCD(temperature, darkness, darknessThreshold);
  
  digitalWrite(RELAY_PIN, darkness >= darknessThreshold ? LOW : HIGH);
}

void Driver::PrintToLCD(double temperature, int darkness, int darknessThreshold)
{
  lcd.clear();
  lcd.print("Temperature ");
  lcd.print(round(temperature));
  lcd.print(" C");
  lcd.setCursor(0, 1);  //second line
  lcd.print("Dark ");
  lcd.print(darkness);
  lcd.print(" / ");
  lcd.print(darknessThreshold);  
}
