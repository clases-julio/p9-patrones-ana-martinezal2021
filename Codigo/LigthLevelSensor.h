/**
* @file LigthLevelSensor.h
* @brief defines the LigthLevelSensor class, wich is is inherited from 
  the sensor class, with its attributes, methods, and constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/

//we define the ligth level sensor class
#ifndef LIGTHLEVELSENSOR_H
#define LIGTHLEVELSENSOR_H

#include "Sensor.h"
#include <iostream>
using namespace std;

class LigthLevelSensor : public Sensor {
public:
  LigthLevelSensor();//ligth level sensor class constructor
  //class functions

  /**
  * Displays the ligth level sensor options menu
  * Depending on the option that is entered, it calls its respective function
  */ 
  void showChoice();
  
  /**
  * Creates a random number to simulate de current ligth level and displays it
  */
  const void getInfo();

private:
  //class attributes
  float ligthLevel;
  int choice;
};
#endif
