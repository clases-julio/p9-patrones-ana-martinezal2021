/**
* @file Microphone.h
* @brief defines the microphone class with its attributes, methods, and constructor
* @author Ana Martínez Albendea
* @date 2022-11-23
*************************************************/

//we define the microphone class
#ifndef MICROPHONE_H
#define MICROPHONE_H

#include <iostream>
using namespace std;

class Microphone {
public:
  Microphone();//microphone class constructor
  //class functions

  /**
  * Depending on the state of the microphone, we turn it on and indicate its state   
  */
  void turnOn();

  /**
  * Depending on the state of the microphone, we turn it off and indicate its state  
  */
  void turnOff();

  /**
  * Prints that a command is being listened for 
  */
  void getSound();

  /**
  * Displays the microphone options menu 
  * Depending on the option that is entered, it calls its respective function.  
  */
  void showChoice();

private:
  //class attributes
  bool state = true;
  string sound = "\nListening command...";
  int choice;
};
#endif
