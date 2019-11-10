/*
 * Class for reading temperature based on a TMP36 sensor.
 * A supply of 5V is assumed.
 */
class TemperatureSensor
{   
  public:
    /*
     * tempPin is the analog pin for reading in values.
     * noOfReadings is the number of reads that occur to reduce fluctuations and increase accuracy.
     * centigrade is whether the readings are expressed in Centigrade or Fahrenheit.
     */
    TemperatureSensor(int tempPin, int noOfReadings = 10, bool centigrade = true);

    double GetTemperature();

  private:
    int tempPin;
    int noOfReadings;
    bool centigrade;

    double ReadTemperature();
};
