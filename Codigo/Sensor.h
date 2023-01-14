/**
* @file Sensor.h
* @brief defines the sensor class with its attributes, methods, and constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/

//we define the sensor class
#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
using namespace std;

class Sensor {
public:
  Sensor(); //sensor class constructor
  //class functions

  /**
  * Depending on the state of the sensor, we turn it on and indicate its state
  */
  void turnOn();

  /**
  * Depending on the state of the sensor, we turn it off and indicate its state 
  */
  void turnOff();
  
	/**
  * Displays the sensor info (polymorphism)
  */
  virtual void getInfo();

private:
  //class attributes
  bool state = true;
};
#endif
