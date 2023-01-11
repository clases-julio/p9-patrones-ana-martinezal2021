//we include the .h of the classes that we are going to use
#include "LigthLevelSensor.h"
#include "Sensor.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

LigthLevelSensor::LigthLevelSensor():Sensor() {} //we define the constructor indicating that it is an inherit class of sensor

const void LigthLevelSensor::getInfo(){
  srand(time(NULL)+2); 
  ligthLevel = rand()%101;
  cout << "\nCurrent ligth level: " << ligthLevel << "%" << endl;
}
