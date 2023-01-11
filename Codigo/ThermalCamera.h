/**
* @file ThermalCamera.h
* @brief defines the ThermalCamera class, wich is is inherited from 
  the camera class, with its attributes, methods, and constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/

//we define the thermal camera class
#ifndef THERMALCAMERA_H
#define THERMALCAMERA_H

#include "Camera.h"
#include <iostream>
using namespace std;

class ThermalCamera : public Camera {
public:
  ThermalCamera();//thermal camera class constructor
  //class functions

  /**
  * Displays the thrermal camera options menu
  * Depending on the option that is entered, it calls its respective function
  */
  void showChoice();
  
  /**
  * Displays the "thermal image"
  */
  const void getInfo();
  
private:
  //class attributes
  int choice;
};
#endif
