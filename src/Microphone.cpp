#include "../include/Microphone.h" //we include the .h to its respective .cpp
#include <iostream>
#include <stdlib.h>

using namespace std;

Microphone::Microphone() {} //we define the constructor

void Microphone::getSound() {
  //prints that a command is being listened for
  cout << sound << endl;
}

void Microphone::turnOn() {
  //Depending on the state of the microphone, we turn it on and indicate its state
  if (state == false){
    cout << "\nMicrophone status: On" << endl;
    state = true;
  }else{
    cout << "\nThe microphone is already on" << endl;
  }
}

void Microphone::turnOff() {
  //Depending on the state of the microphone, we turn it off and indicate its state
  if (state = true){
    cout << "\nMicrophone status: Off" << endl;
    state = false;
  }else{
    cout << "\nThe microphone is already off" << endl;
  }
}

void Microphone::showChoice(){
  //displays the microphone options menu
  while (true) {
    cout << "\n               ___  ___ _                           _                         " << endl 
    << "               |  \\/  |(_)                         | |                        " << endl 
    << "               | .  . | _   ___  _ __  ___   _ __  | |__    ___   _ __    ___ " << endl 
    << "               | |\\/| || | / __|| '__|/ _ \\ | '_ \\ | '_ \\  / _ \\ | '_ \\  / _ \\" << endl 
    << "               | |  | || || (__ | |  | (_) || |_) || | | || (_) || | | ||  __/" << endl 
    << "               \\_|  |_/|_| \\___||_|   \\___/ | .__/ |_| |_| \\___/ |_| |_| \\___|" << endl 
    << "                                            | |                               " << endl 
    << "                                            |_|                               " << endl 
    << "                                                                              " << endl
    << "-----------------------------------------------------------------------------------------------" << endl
    << "ººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººº\n" << endl;
    cout << "                                   1. TURN ON" << endl 
        << "                                   2. TURN OFF" << endl 
        << "                                   3. RECORD COMMAND" << endl 
        << "                                   4. BACK TO MENU" << endl;
    cout << "Enter your choice number: ";
    cin >> choice;
    
    switch (choice)
    {
    case 1:
      turnOn();
      system("sleep 3");
      system("clear");
      break;

    case 2:
      turnOff();
      system("sleep 3");
      system("clear");
      break;

    case 3:
      getSound();
      system("sleep 3");
      system("clear");
      break;

    case 4:
      return;
      break;
    }
  }
}
