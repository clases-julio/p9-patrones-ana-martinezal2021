#include "Camera.h" //we include the .h to its respective .cpp
#include <iostream>
using namespace std;

Camera::Camera() {} //we define the constructor

void Camera::turnOn() {
  //Depending on the state of the camera, we turn it on and indicate its state
  if (state == false){
    cout << "\nCamera status: On" << endl;
    state = true;
  }else{
    cout << "\nThe camera is already on" << endl;
  }
}

void Camera::turnOff() {
  //Depending on the state of the camera, we turn it off and indicate its state
  if (state == true){
    cout << "\nCamera status: Off" << endl;
    state = false;
  }else{
    cout << "\nThe camera is already off" << endl;
  }
}

const void Camera::getInfo(){};
