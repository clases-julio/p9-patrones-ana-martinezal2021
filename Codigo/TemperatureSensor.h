/**
* @file TemperatureSensor.h
* @brief defines the TemperatureSensor class, wich is is inherited from 
  the sensor class, with its attributes, methods, and constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/

//we define the temperature sensor class
#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "Sensor.h"
#include <iostream>
using namespace std;

class TemperatureSensor : public Sensor {
public:
  TemperatureSensor();//temperature sensor class constructor
  //class functions
  
  /**
  * Creates a random number to simulate de current temperature and displays it
  */
  void getInfo();
  
private:
  //class attributes
  float temperature;
};
#endif
