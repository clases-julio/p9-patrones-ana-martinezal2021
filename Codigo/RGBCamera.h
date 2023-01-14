/**
* @file RGBCamera.h
* @brief defines the RGBCamera class, wich is is inherited from 
  the camera class, with its attributes, methods, and constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/

//we define the RGB camera class
#ifndef RGBCAMERA_H
#define RGBCAMERA_H

#include "Camera.h"
#include <iostream>
using namespace std;

class RGBCamera : public Camera {
public:
  RGBCamera();//RGB camera class constructor
  //class functions
  
  /**
  * Displays the "thermal image"
  */
  void getInfo();

private:

};
#endif
