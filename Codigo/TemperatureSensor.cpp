//we include the .h of the classes that we are going to use
#include "TemperatureSensor.h"
#include "Sensor.h"
#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

TemperatureSensor::TemperatureSensor():Sensor() {} //we define the constructor indicating that it is an inherit class of sensor

const void TemperatureSensor::getInfo(){
  srand(time(NULL));
  temperature = 25+rand()%(40 +1 - 25); 
  cout << "\nCurrent temperature: " << temperature << " ºC" << endl; 
}
