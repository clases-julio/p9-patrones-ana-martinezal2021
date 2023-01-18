//we include the .h of the classes that we are going to use
#include "../include/AirConditionSensor.h"
#include "../include/Sensor.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

AirConditionSensor::AirConditionSensor():Sensor() {} //we define the constructor indicating that it is an inherit class of sensor

void AirConditionSensor::getInfo(){
  srand(time(NULL)+3); 
  airCondition = rand()%301;
  cout << "\nCurrent air condition level: " << airCondition << " ppm" << endl;
}
