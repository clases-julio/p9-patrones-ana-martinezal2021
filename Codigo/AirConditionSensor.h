/**
* @file AirConditionSensor.h
* @brief defines the AirConditionSensor class, wich is is inherited from 
  the sensor class, with its attributes, methods, and constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/

//we define the air condition sensor class
#ifndef AIRCONDITIONSENSOR_H
#define AIRCONDITIONSENSOR_H

#include "Sensor.h"
#include <iostream>
using namespace std;

class AirConditionSensor : public Sensor {
public:
  AirConditionSensor();//air condition sensor class constructor
  //class functions

  /**
  * Displays the air condition sensor options menu. 
  * Depending on the option that is entered, it calls its respective function.
  */ 
  void showChoice();

  /**
  * Creates a random number to simulate de current air condition and displays it
  */
  const void getInfo();
  
private:
  //class attributes
  float airCondition;
  int choice;
};
#endif
