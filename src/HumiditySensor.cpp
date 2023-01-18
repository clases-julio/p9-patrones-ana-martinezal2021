//we include the .h of the classes that we are going to use
#include "../include/HumiditySensor.h"
#include "../include/Sensor.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

HumiditySensor::HumiditySensor():Sensor() {} //we define the constructor indicating that it is an inherit class of sensor

void HumiditySensor::getInfo(){
  srand(time(NULL)+1);  
  humidity = rand()%101;
  cout << "\nCurrent humidity: " << humidity << "%" << endl;
}
