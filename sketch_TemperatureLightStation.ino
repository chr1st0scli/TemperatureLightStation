#include "Driver.h"

Driver driver;

void setup() 
{
  driver.Initialize();
}

void loop() 
{
  driver.PerformOperation();
  delay(1000);
}
