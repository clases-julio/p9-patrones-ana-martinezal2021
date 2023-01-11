#include "Sensor.h" //we include the .h to its respective .cpp
#include <iostream>
using namespace std;

Sensor::Sensor() {} //we define the constructor

void Sensor::turnOn() {
  //Depending on the state of the sensor, we turn it on and indicate its state
  if (state == false){
    cout << "\nSensor status: On" << endl;
    state = true;
  }else{
    cout << "\nThe sensor is already on" << endl;
  }
}

void Sensor::turnOff() {
  //Depending on the state of the sensor, we turn it off and indicate its state
  if (state == true){
    cout << "\nSensor Status: Off" << endl;
    state = false;
  }else{
    cout << "\nThe sensor is already off" << endl;
  }
}

const void Sensor::getInfo(){}
