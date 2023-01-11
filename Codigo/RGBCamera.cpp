//we include the .h of the classes that we are going to use
#include "RGBCamera.h"
#include "Camera.h"
#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

RGBCamera::RGBCamera():Camera() {} //we define the constructor indicating that it is an inherit class of camera

const void RGBCamera::getInfo() {
  //prints that an image is being displayed
  cout << " ---------------------------------------------" << endl << "-                                     LIVE... -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                 RGB image                   -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << " ---------------------------------------------"<< endl;;
}
