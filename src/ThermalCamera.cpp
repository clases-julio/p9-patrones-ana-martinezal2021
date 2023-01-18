//we include the .h of the classes that we are going to use
#include "../include/ThermalCamera.h"
#include "../include/Camera.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

ThermalCamera::ThermalCamera():Camera() {} //we define the constructor indicating that it is an inherit class of camera

void ThermalCamera::getInfo() {
  //prints that an image is being displayed
  cout << " ---------------------------------------------" << endl << "-                                     LIVE... -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                Thermal image                -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << "-                                             -" << endl << " ---------------------------------------------"<< endl;
}
