//we include the .h of the classes that we are going to use
#include "HumiditySensor.h"
#include "Sensor.h"
#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

HumiditySensor::HumiditySensor():Sensor() {} //we define the constructor indicating that it is an inherit class of sensor

const void HumiditySensor::getInfo(){
  srand(time(NULL)+1);  
  humidity = rand()%101;
  cout << "\nCurrent humidity: " << humidity << "%" << endl;
}
