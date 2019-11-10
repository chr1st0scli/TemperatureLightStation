#include <LiquidCrystal.h>
#include "TemperatureSensor.h"

/*
 * Class that performs the following operations.
 * Prints the temperature to an LCD screen.
 * Prints the level of darkness and a darkness threshold setting to an LCD screen.
 * When the darkness exceeds the threshold, it sends a signal to a relay e.g. for turning on a light.
 * 
 * The relay should be powered by a separate PSU in an isolated manner to avoid fluctuations in the 
 * temperature reading when signaling the relay.
 */
class Driver
{
  public:
    Driver();
    void Initialize();
    void PerformOperation();
    
  private:
    void PrintToLCD(double temperature, int darkness, int darknessThreshold);
  
    const int RELAY_PIN = 8;  //Digital output
    const int LIGHT_PIN = 0, POTENTIO_PIN = 1, TEMPERATURE_PIN = 2; //Analog input
    const int LCD_RS_PIN = 12, LCD_E_PIN = 11, LCD_D4_PIN = 5, LCD_D5_PIN = 4, LCD_D6_PIN = 3, LCD_D7_PIN = 2;  //LCD related digital pins

    double prevTemperature;
    int prevDarkness;
    int prevDarknessThreshold;

    LiquidCrystal lcd;
    TemperatureSensor tmprtSensor;
};
