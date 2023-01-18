/**
* @file Dashboard.h
* @brief defines the dashboard class with its attributes, methods, and constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/

//we define the dashboard class
#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "Login.h"
#include <iostream>
using namespace std;

class Dashboard {
public:
  //class functions
  static Dashboard* getDashboard();
  
  /**
  * Displays the login screen and, depending on whether the user exists, displays the main menu
  * Checks that the user entered is of type Admin
  * Allows the showMenu() function to be called again when you want to log out and re-enter a user 
  * in case of not putting it, it does not verify that the user exists
  */
  void showMenu();

  /**
  * Depending on the option entered, performs an action
  */
  bool getOption();
  
  /**
  * Displays the sensor options menu and performs the action depending on the option entered
  */
  void showSensorChoices(Sensor*);
  
  /**
  * Displays the camera options menu and performs the action depending on the option entered
  */
  void showCameraChoices(Camera*);
  
  Dashboard (Dashboard &otherDashboard) = delete;
  void operator= (const Dashboard&) = delete;
  
protected:
  Dashboard();//dashboard class constructor

private:
  //class attributes
  int option;
  int choice;
  static Dashboard* singleDashboard;
  //constructors and pointers of all used classes
  Login L;
  DataBase D;
  TemperatureSensor* T = new TemperatureSensor();
  HumiditySensor* H = new HumiditySensor();
  LigthLevelSensor* Li = new LigthLevelSensor();
  AirConditionSensor* A = new AirConditionSensor();
  RGBCamera* RC = new RGBCamera();
  ThermalCamera* TC = new ThermalCamera();
  Microphone M;
  
};
#endif
