/**
* @file HumiditySensor.h
* @brief defines the HumiditySensor class, wich is is inherited from 
  the sensor class, with its attributes, methods, and constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/

//we define the humidity sensor class
#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include "Sensor.h"
#include <iostream>
using namespace std;

class HumiditySensor : public Sensor {
public:
  HumiditySensor();//humidity sensor class constructor
  //class functions

  /**
  * Creates a random number to simulate de current humidity
  */
  void checkHumidity(); 

  /**
  * Displays the current humidity created with checkHumidity()
  */ 
  void getHumidity();

  /**
  * Displays the humidity sensor options menu
  * Depending on the option that is entered, it calls its respective function
  */
  void showChoice();
  
  /**
  * Creates a random number to simulate de current humidity and displays it
  */
  const void getInfo();

private:
  //class attributes
  float humidity;
  int choice;
};
#endif
