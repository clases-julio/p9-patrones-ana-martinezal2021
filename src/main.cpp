/* ---------------------------
  File: main.cpp
  Author: Ana Martínez Albendea
  Date: 23/11/22
  Goal: its the main program where the interface is initialized
------------------------------ */
//all .h of the classes we need are included
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "../include/Sensor.h"
#include "../include/TemperatureSensor.h"
#include "../include/HumiditySensor.h"
#include "../include/LigthLevelSensor.h"
#include "../include/AirConditionSensor.h"
#include "../include/Camera.h"
#include "../include/RGBCamera.h"
#include "../include/ThermalCamera.h"
#include "../include/User.h"
#include "../include/Microphone.h"
#include "../include/DataBase.h"
#include "../include/Login.h"
#include "../include/Dashboard.h"

using namespace std; //it prevents us from putting std with everything that requires it

int main(){
  //title created with ascii art
  system("clear");
  cout << "ººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººº" << endl;
  cout << "-----------------------------------------------------------------------------------------------" << endl;
  cout << "      _       _ _        __     __                                        _   _ _  _           " << endl
  << "     | |_   _| (_) ___   \\ \\   / /__  __ _  __ _ _ __   ___  ___    ___  | | | (_)(_) ___  ___ " << endl 
  << "  _  | | | | | | |/ _ \\   \\ \\ / / _ \\/ _` |/ _` | '_ \\ / _ \\/ __|  / _ \\ | |_| | || |/ _ \\/ __|" << endl
  << " | |_| | |_| | | | (_) |   \\ V /  __/ (_| | (_| | | | | (_) \\__ \\ |  __/ |  _  | || | (_) \\__ \\" << endl
  << "  \\___/ \\__,_|_|_|\\___/     \\_/ \\___|\\__, |\\__,_|_| |_|\\___/|___/  \\___| |_| |_|_|/ |\\___/|___/" << endl
  << "                                     |___/                                      |__/           " << endl;
  cout << "\n-----------------------------------------------------------------------------------------------" << endl;
  cout << "ººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººººº\n" << endl;


  cout << "                                Please, log in to continue\n"  << endl;
  try{

    // Creates the binary file users.dat and save 10 spaces to store users. Can be created without that reservation
    /*ofstream outUsersFile ("users.dat", ios::out | ios::binary);

    if (!outUsersFile) { // ofstream could not open file
      cerr << "File could not be opened." << endl;
      exit (1);
    }

    User user; // fill with zeros each data member
    for (int i = 0; i < 10; i++){ // write 10 empty records to file
      outUsersFile.write (reinterpret_cast <const char *> (&user), sizeof (User));
    }*/

    Dashboard* Ds = Dashboard::getDashboard(); //construction of a dashboard type object

    //while loop allowing to log back in after log out
    while (true) {
      Ds->Dashboard::showMenu(); //call to the function that shows the main menu of the dashboard
    }
  }
    
  catch(bad_alloc &except){
    cout << "Exception: " << except.what() << endl;
  }
}
