/**
* @file Camera.h
* @brief defines the camera class with its attributes, methods, and constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/

//we define the camera class
#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
using namespace std;

class Camera {
public:
  Camera();//camera class constructor
  //class functions

  /**
  * Depending on the state of the camera, we turn it on and indicate its state
  */
  void turnOn();

  /**
  * Depending on the state of the camera, we turn it off and indicate its state
  */
  void turnOff();
  
  const void getInfo();

private:
  //class attributes
  bool state = true;
};
#endif
